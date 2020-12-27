
#include "image.h"
#include "log.h"

image_t* create_image(char* name, image_handler handler, unsigned int width,  unsigned int height)
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
    image->buffer_size = image->height * image->width;
    image->buffer = (unsigned int*) malloc(sizeof(unsigned int)* image->buffer_size);
    image->handler = handler;

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
