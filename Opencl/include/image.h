/* DO NOT EDIT THIS FILE */

#ifndef INCLUDE_IMAGE_H_
#define INCLUDE_IMAGE_H_

#include <stdbool.h>
#include <stddef.h>
#include "pixel.h"
#include "opencl.h"

typedef struct image {
    size_t id;
    size_t width;
    size_t height;
    pixel_t* pixels;
} image_t;

static inline pixel_t* image_get_pixel(image_t* image, unsigned int x, unsigned int y) {
    if (x >= image->width || y >= image->height) {
        return NULL;
    }

    return &image->pixels[x + y * image->width];
}

image_t* image_create(size_t id, size_t width, size_t height);
image_t* image_create_from_png(char* filename);
image_t* image_copy(image_t* image);
void image_destroy(image_t* image);
int image_save_png(image_t* image, char* filename);

typedef struct image_dir {
    char* name;
    char* save_prefix;
    size_t load_current;
    bool stop;
} image_dir_t;

image_t* image_dir_load_next(image_dir_t* image_dir);
int image_dir_save(image_dir_t* image_dir, image_t* image);


typedef struct image_opencl {
    cl_context context;
    cl_command_queue queue;
    cl_mem buffer;
    cl_kernel kernel;

} image_opencl_t;

typedef struct image image_t;
typedef int(*image_handler)(image_t* image);

typedef struct image_to_send {
    size_t id;
    size_t width;
    size_t height;

    unsigned char* buffer;
    size_t buffer_size;

    image_handler* handler;
    image_opencl_t* opencl;

} image_to_send_t;

image_to_send_t* create_image_to_send(size_t id, image_handler* handler, image_t* image);
unsigned char*  create_buffer(image_t* image);
void destroy_image_to_send(image_to_send_t* image);

int image_opencl_init(image_opencl_t* opencl_image, cl_device_id device_id, size_t width, size_t height);
void image_opencl_cleanup(image_opencl_t* opencl_image);
int image_opencl(image_to_send_t* image);


#endif /* INCLUDE_IMAGE_H_ */
