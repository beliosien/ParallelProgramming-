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

// initialise the window
static int pre_display() {
    if (display == NULL) {
        LOG_ERROR("display has not been initialised");
        goto fail_exit;
    }

    glViewport(0, 0, display->width, display->height);
    if (LOG_ERROR_OPENGL("glViewport") < 0) {
        goto fail_exit;
    }

    glMatrixMode(GL_PROJECTION);
    if (LOG_ERROR_OPENGL("glMatrixMode") < 0) {
        goto fail_exit;
    }

    glLoadIdentity();
    if (LOG_ERROR_OPENGL("glLoadIdentity") < 0) {
        goto fail_exit;
    }

    gluOrtho2D(0.0, 1.0, 0.0, 1.0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    if (LOG_ERROR_OPENGL("glClearColor") < 0) {
        goto fail_exit;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    if (LOG_ERROR_OPENGL("glClear") < 0) {
        goto fail_exit;
    }

    return 0;

fail_exit:
    return -1;
}


static int display() {
    if (display == NULL) {
        LOG_ERROR("viewer has not been initialised");
        goto fail_exit;
    }

    if (display->image == NULL) {
        LOG_ERROR_NULL_PTR();
        goto fail_exit;
    }

    if (display->image->handler(display->image) < 0) {
        LOG_ERROR("failed to call image handler `%s`\n", display->image->name);
        goto fail_exit;
    }

    if (display->texture == 0) {
        glGenTextures(1, &display->texture);
        if (LOG_ERROR_OPENGL("glGenTextures") < 0) {
            goto fail_exit;
        }
    }

    if (display->enabled) {
        glBindTexture(GL_TEXTURE_2D, display->texture);
        if (LOG_ERROR_OPENGL("glBindTexture") < 0) {
            goto fail_exit;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, 3, display->image->width, display->image->height, 0, GL_RGB,
                     GL_UNSIGNED_BYTE, display->image->buffer);
        if (LOG_ERROR_OPENGL("glTexImage2D") < 0) {
            goto fail_exit;
        }

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
            goto fail_exit;
        }

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
            goto fail_exit;
        }

        glEnable(GL_TEXTURE_2D);
        if (LOG_ERROR_OPENGL("glEnable") < 0) {
            goto fail_exit;
        }

        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 0.0);
        glVertex2d(0.0, 0.0);
        glTexCoord2d(1.0, 0.0);
        glVertex2d(1.0, 0.0);
        glTexCoord2d(1.0, 1.0);
        glVertex2d(1.0, 1.0);
        glTexCoord2d(0.0, 1.0);
        glVertex2d(0.0, 1.0);
        glEnd();

        if (LOG_ERROR_OPENGL("glBegin / glEnd") < 0) {
            goto fail_exit;
        }
    }

    //viewer->fps_count++;

    return 0;

fail_exit:
    return -1;
}



static inline void post_display() {
    glutSwapBuffers();
}


static void callback_display() {
    if (pre_display() < 0) {
        LOG_ERROR("pre-display failed");
    }

    if (display() < 0) {
        LOG_ERROR("display failed");
    }

    post_display();
}

static void callback_idle() {
    glutSetWindow(display->window_id);
    glutPostRedisplay();
}


void callback_keyboard(unsigned char key, int x, int y) {
    if (display == NULL) {
        LOG_ERROR("display has not been initialised");
        return;
    }

    switch (key) {
    case 'q':
        printf("Closing application\n");
        glutLeaveMainLoop();
        break;
    case '3':
        printf("Selected opencl implementation\n");
        display->image->name    = "opencl";
        display->image->handler = image_opencl;
        break;
    case ' ':
        printf("Rendering %s\n", display->enabled ? "disabled" : "enabled");
        display->enabled = !display->enabled;
        break;
    // TODO add a zoom in and zoom out functionnality instead
    default:
        break;
    }
}

int display_open() {
    if (display == NULL) {
        LOG_ERROR("display has not been initialised");
        goto fail_exit;
    }

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    int x_pos = (glutGet(GLUT_SCREEN_WIDTH) - display->width) / 2;
    int y_pos = (glutGet(GLUT_SCREEN_HEIGHT) - display->height) / 2;

    glutInitWindowPosition(x_pos, y_pos);
    glutInitWindowSize(display->width, display->height);
    display->window_id = glutCreateWindow("image_sobel");

    glutDisplayFunc(callback_display);
    glutIdleFunc(callback_idle);
    //glutTimerFunc(fps_delay_ms, callback_timer_fps, 0);
    glutKeyboardFunc(callback_keyboard);
    //glutReshapeFunc(callback_reshape);

    glewInit();
    //glXSwapIntervalMESA(0);
    glutMainLoop();

    return 0;

fail_exit:
    return -1;
}


