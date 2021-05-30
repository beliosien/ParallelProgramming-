#ifndef INCLUDE_VIEWER_UTILITARY
#define INCLUDE_VIEWER_UTILITARY

#include <GL/glew.h>
#include "shader.h"
#include <GL/glxew.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "log.h"
#include "viewer.h"

#define WIDTH 640
#define HEIGHT 480

// all function necessary to the viewer to works properly

static viewer* v = NULL;

static float vertices[] = {
                // positions          // colors           // texture coords
                -1.0f,  -1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 1.0f,   // top right
                1.0f,  -1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,   // bottom right
                1.0f,   1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   1.0f, 0.0f,   // bottom left
                -1.0f,   1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f    // top left 
            };
 
static unsigned int indices[] = {  // note that we start from 0!
                        0, 1, 3,   // first triangle
                        1, 2, 3    // second triangle
                    }; 


int viewer_init(std::vector<image>& images);
int viewer_open();
void viewer_destroy();

static int pre_display();
static int display();
static void post_display();
    
static void callback_display();
static void callback_idle();
static void callback_keyboard(unsigned char key, int x, int y);
static void callback_reshape(int width, int height);

#endif