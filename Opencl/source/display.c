#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glxew.h>

#include <GL/freeglut_ext.h>

#include "display.h"
#include "log.h"
#include "image.h"

typedef struct display {
    unsigned int width;
    unsigned int height;

    unsigned int window_id;

    image_t* image;
    GLuint texture; 
    bool enabled;

} display_t;


static display_t* display = NULL;



int display_init(image_t* image)
{
    if (display != NULL)
    {
        LOG_ERROR("display has already been initialised");
        goto fail_exit;
    }

    display = malloc(sizeof(display_t));

    if (display == NULL)
    {
        LOG_ERROR_ERRNO("malloc");
        goto fail_exit;
    }

    display->width = image->width;
    display->height = image->height;
    display->window_id = 0;

    display->image = image;
    display->texture = 0;
    display->enabled = true;

    return 0;


fail_exit:
    return -1;
}

void display_destroy()
{
    if (display != NULL)
    {
        free(display);
        display = NULL;
    }
}

int display_open()
{
    
}


