#include "log.h"
#include "image.h"


int image_opencl_init(image_opencl_t* opencl_image, cl_device_id device_id, unsigned int width, unsigned int height)
{
    cl_int err = 0;

    opencl_image->context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
    if (err != CL_SUCCESS)
    {
        LOG_ERROR("error creating opencl context");
        goto fail_exit;
    }


    opencl_image->command_queue = clCreateCommandQueueWithProperties(opencl_image->context, device_id, 0, &err);
    if (err != CL_SUCCESS)
    {
        LOG_ERROR("error creating opencl command queue");
        goto fail_exit;
    }

    const unsigned int buffer_size = width * height;
    opencl_image->buffer_in = clCreateBuffer(opencl_image->context , CL_MEM_READ_ONLY, buffer_size, NULL, &err);
    if (err != CL_SUCCESS)
    {
        LOG_ERROR("error creating buffer in");
        goto fail_exit;
    }

    opencl_image->buffer_out = clCreateBuffer(opencl_image->context , CL_MEM_WRITE_ONLY, buffer_size, NULL, &err);
    if (err != CL_SUCCESS)
    {
        LOG_ERROR("error creating buffer out");
        goto fail_exit;
    }






fail_exit:
    return -1;
}