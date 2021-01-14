#include "image.h"
#include "log.h"

int image_opencl_init(image_opencl_t* opencl_image, cl_device_id device_id, size_t width, size_t height)
{
    cl_int err = 0;

    opencl_image->context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
    if (err != CL_SUCCESS)
    {
        LOG_ERROR("error creating opencl context");
        goto fail_exit;
    }


    opencl_image->queue = clCreateCommandQueueWithProperties(opencl_image->context, device_id, 0, &err);
    if (err != CL_SUCCESS)
    {
        LOG_ERROR("error creating opencl command queue");
        goto fail_exit;
    }

    const unsigned int buffer_size = width * height;
    opencl_image->buffer = clCreateBuffer(opencl_image->context , CL_MEM_READ_ONLY, buffer_size, NULL, &err);
    if (err != CL_SUCCESS)
    {
        LOG_ERROR("error creating buffer");
        goto fail_exit;
    }

    char* kernelSource = NULL;
    size_t len = 0;

    err = opencl_load_kernel_code(&kernelSource, &len);

    if (err < 0)
    {
        LOG_ERROR("error loading kernel code");
        goto fail_exit;
    }

    cl_program program = clCreateProgramWithSource(opencl_image->context, 1, (const char**) &kernelSource, NULL, &err);
    if (err != CL_SUCCESS)
    {
        LOG_ERROR("error creating the program");
        free(kernelSource);
        goto fail_exit;
    }
    free(kernelSource);


    char* options_prefix = "-I ";
    char* opencl_include = __OPENCL_INCLUDE__;
    char* options = malloc(strlen(options_prefix) + strlen(opencl_include) + 1);
    strcpy(options, options_prefix);
    strcat(options, opencl_include);
    err = clBuildProgram(program, 1, &device_id, options, NULL, NULL);
    if (err!= CL_SUCCESS) {
        LOG_ERROR("failed to build OpenCL program");
        opencl_print_build_log(program, device_id);
        free(options);
        goto fail_exit;
    }

    free(options);

    opencl_image->kernel = clCreateKernel(program, "sobel_filter", &err);
    if (err != CL_SUCCESS)
    {
        LOG_ERROR("error creating the kernel");
        goto fail_exit;
    }


    return 0;

fail_exit:
    return -1;
}

void image_opencl_cleanup(image_opencl_t* opencl_image)
{
    clReleaseMemObject(opencl_image->buffer);
    clReleaseKernel(opencl_image->kernel);
    clReleaseCommandQueue(opencl_image->queue);
    clReleaseContext(opencl_image->context);
}


struct __attribute__((packed)) params_t {
    size_t width;
    size_t height;
    size_t buffer_size;
};

int image_opencl(image_to_send_t* image) {
    if (image->opencl == NULL) {
        LOG_ERROR_NULL_PTR();
        goto fail_exit;
    }
    cl_int err = 0;

    struct params_t params;
    params.width = image->width;
    params.height = image->height;
    params.buffer_size = image->buffer_size;

    err = clSetKernelArg(image->opencl->kernel,  0, sizeof(cl_mem), &(image->opencl->buffer));
    err |= clSetKernelArg(image->opencl->kernel, 1, sizeof(struct params_t), &params);
    err |= clSetKernelArg(image->opencl->kernel, 2, sizeof(cl_mem), &(image->opencl->buffer));

    if (err != CL_SUCCESS) {
        LOG_ERROR("failed to set OpenCL kernel arguments");
        goto fail_exit;
    }

    size_t global_size[] = {(size_t)image->height, (size_t)image->width};
    err = clEnqueueNDRangeKernel(image->opencl->queue, image->opencl->kernel, 2,
                        NULL, global_size, NULL, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        LOG_ERROR("failed to enqueue and execute OpenCL kernel");
        goto fail_exit;
    }

    err = clFinish(image->opencl->queue);
    if (err != CL_SUCCESS) {
        LOG_ERROR("failed to wait for OpenCL kernel");
        goto fail_exit;
    }

    err = clEnqueueWriteBuffer(image->opencl->queue, image->opencl->buffer, CL_TRUE, 0,
                                image->buffer_size, image->buffer, 0 , NULL, NULL);
    if (err != CL_SUCCESS) {
        LOG_ERROR("failed to enqueue commands to write buffer");
        goto fail_exit;
    }

    err = clEnqueueReadBuffer(image->opencl->queue, image->opencl->buffer, CL_TRUE, 0,
                                image->buffer_size, image->buffer, 0 , NULL, NULL);
    if (err != CL_SUCCESS) {
        LOG_ERROR("failed to enqueue commands to read buffer");
        goto fail_exit;
    }

    return 0;

fail_exit:
    return -1;
}