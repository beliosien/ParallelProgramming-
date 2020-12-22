#include <stdio.h>
#include "opencl.h"
#include "log.h"


#define DATA_SIZE 10

void checkError(cl_int err, char* msg)
{
    if (err != CL_SUCCESS)
    {
        //LOG_ERROR(msg);
        printf("%s \n",msg);
    }
}

const char* KernelSource = "__kernel void hello(__global float* input, __global float* output) \n"\
"{\n"\
"   size_t id = get_global_id(0); \n"\
"   output[id] = input[id] * input[id]; \n"\
"}\n"\
"\n";

int main(){    
    cl_platform_id platform_id;
    cl_uint num_platform;
    cl_device_id device_id;
    cl_uint num_of_devices;
    cl_context context;
    cl_context_properties properties[3];
    cl_command_queue command_queue;
    cl_program program;
    cl_kernel kernel;
    cl_mem input, output;
    size_t global;


    float inputData[DATA_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float result[DATA_SIZE] = {0};

    cl_int err = clGetPlatformIDs(1, &platform_id, &num_platform);
    checkError(err, "No platform found");

    err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_of_devices);
    checkError(err, "No device found");

    // the properties list must finish with 0
    properties[0] = CL_CONTEXT_PLATFORM;
    properties[1] = (cl_context_properties) platform_id;
    properties[2] = 0;

    // create a context with the gpu device
    context = clCreateContext(properties, 1, &device_id, NULL, NULL, &err);
    checkError(err, "error with the context creation");

    // create a command queue using the context and the device
    command_queue = clCreateCommandQueueWithProperties(context, device_id, 0, &err);
    checkError(err, "error with creation of the command queue");

    // create a program from the kernel source
    program = clCreateProgramWithSource(context, 1, (const char**) &KernelSource, NULL, &err);
    checkError(err, "error with the program creation");


    if (clBuildProgram(program, 0, NULL, NULL, NULL, NULL) != CL_SUCCESS)
    {
        printf("Error building program\n");
        char buffer[4096];
        size_t length;
        clGetProgramBuildInfo(
            program, // valid program object
            device_id, // valid device_id that executable was built
            CL_PROGRAM_BUILD_LOG, // indicate to retrieve build log
            sizeof(buffer), // size of the buffer to write log to
            buffer, // the actual buffer to write log to
            &length
        ); // the actual size in bytes of data copied to buffer
        printf("%s\n",buffer);
        exit(1);
    }


    // kernel object
    kernel = clCreateKernel(program, "hello", &err);
    checkError(err, "error with kernel creation");


    // create buffers for input and ouput
    input = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(float)* DATA_SIZE, NULL, NULL);
    output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(float)* DATA_SIZE, NULL, NULL);

    // load data into input buffer
    clEnqueueWriteBuffer(command_queue, input, CL_TRUE, 0, sizeof(float) * DATA_SIZE, inputData, 0, NULL, NULL);

    // specify the arguments associated with the function
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);
    checkError(err, "association failed for the first argument");
    err = clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
    checkError(err, "association failed for the second argument");
    global = DATA_SIZE;

    // enqueue the kernel command for execution 
    err = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
    checkError(err, "enqueue NDrange failed");
    clFinish(command_queue);


    //copy the result from out of the output buffer
    clEnqueueReadBuffer(command_queue, output, CL_TRUE, 0, sizeof(float) * DATA_SIZE, result, 0, NULL, NULL);
    checkError(err, "enqueue read buffer failed");

    //print the results
    printf("output: ");
    for (int i = 0; i < DATA_SIZE; i++)
    {
        printf("%f \n", result[i]);
    }

    // clean up 
    clReleaseMemObject(input);
    clReleaseMemObject(output);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(command_queue);
    clReleaseContext(context);

    return 0;

}
