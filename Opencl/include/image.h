#ifndef INCLUDE_IMAGE_H_
#define INCLUDE_IMAGE_H_

#include "opencl.h"

typedef struct image_opencl {
    cl_context context;
    cl_command_queue command_queue;
    cl_mem buffer_in;
    cl_mem buffer_out; 
    cl_kernel kernel;

} image_opencl_t;

typedef struct image image_t;
typedef int (*image_handler)(image_t* image);

typedef struct image {
    const char*  name;
    unsigned int width;
    unsigned int height;

    image_handler handler;

    unsigned int buffer_size; 
    unsigned int* buffer;

    image_opencl_t* opencl_image;

} image_t;



image_t* create_image(char* name, image_handler handler, unsigned int width,  unsigned int height); // create an empty image
void  destroy_image(image_t* image);

int image_opencl(image_t* image);

int image_opencl_init(image_opencl_t* opencl_image, cl_device_id device_id, unsigned int width, unsigned int height);
void image_opencl_cleanup(image_opencl_t* opencl_image);

#endif /*INCLUDE_IMAGE_H_*/