
#include "image.h"
#include "log.h"

static const unsigned int BYTE_PER_PIXEL = 3;

image_t* create_image(char* name,  unsigned int width,  unsigned int height)
{
    image_t* image = (image_t*) malloc(sizeof(image_t));
    if (image == NULL)
    {
        LOG_ERROR_ERRNO("error allocating in create image");
        goto fail_exit;
    }

    image->name = name; 
    image->width = width;
    image->height = height;
    image->buffer_size = image->height * image->width * BYTE_PER_PIXEL;
    image->buffer = (unsigned char*) malloc(sizeof(unsigned char)* image->buffer_size);


    if (image->buffer == NULL)
    {
        LOG_ERROR_ERRNO("error allocating in create image");
        goto fail_free_image;
    }

    return image;

fail_free_image:
    free(image);

fail_exit:
    return NULL;
}

void destroy_image(image_t* image)
{
    free(image->buffer);
    free(image);
}
