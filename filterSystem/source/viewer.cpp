#include "viewer.h"

viewer *viewer::_viewer = 0;

viewer::viewer()
{
}

viewer::~viewer()
{
    if (!_images.empty())
    {
        _images.clear();
    }
}

/**
 * add image 
 * 
 * @param img the image we want to add
*/
void viewer::addImage(image& img)
{
    _images.push_back(img);
}


int viewer::display_init()
{
    _width = WIDTH;
    _height = HEIGHT;
    _window_id = 0;
    _texture = 0;
    _enabled = true;

    return 0;

}

int viewer::pre_display()
{
    glViewport(0, 0, _viewer->getWidth(), _viewer->getHeight());
    if (LOG_ERROR_OPENGL("glViewport") < 0) {
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    if (LOG_ERROR_OPENGL("glClearColor") < 0) {
        return -1;
    }


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (LOG_ERROR_OPENGL("glClear") < 0) {
        return -1;
    }

    return 0;
}


void viewer::callback_display() 
{
    if (pre_display() < 0) {
        LOG_ERROR("pre-display failed");
    }

    if (display() < 0) {
        LOG_ERROR("display failed");
    }

    post_display();
}

void viewer::callback_idle()
{
    viewer* v = v->getInstance();
    glutSetWindow(v->getWindowId());
    glutPostRedisplay();
}

void viewer::callback_keyboard(unsigned char key, int x, int y)
{
    // TODO change: zoom in, zoom out, avancer, rentrer
    switch (key) {
    case 'q':
        printf("Closing application\n");
        glutLeaveMainLoop();
        break;

    case '1':
        printf("Selected serial implementation\n");
        break;

    case '2':
        printf("Selected openmp implementation\n");
        break;

    case '3':
        printf("Selected opencl implementation\n");
        break;

    case ' ':
        printf("Rendering %s\n", _viewer->_enabled ? "disabled" : "enabled");
        _viewer->_enabled = !_viewer->_enabled;
        break;

    default:
        break;
    }
}

void viewer::callback_reshape(int width, int height) 
{
    viewer* v = v->getInstance();
    glutSetWindow(v->getWindowId());
    glutReshapeWindow(width, height);

    v->setWidth(width);
    v->setHeight(height);
}

int viewer::display_open()
{
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    int x_pos = (glutGet(GLUT_SCREEN_WIDTH) - _width) / 2;
    int y_pos = (glutGet(GLUT_SCREEN_HEIGHT) - _height) / 2;

    glutInitWindowPosition(x_pos, y_pos);

    glutInitWindowSize(_width, _height);
    _window_id = glutCreateWindow("Viewer");
    
    glutDisplayFunc(callback_display);
    glutIdleFunc(callback_idle);
    glutKeyboardFunc(callback_keyboard);

    glutReshapeFunc(callback_reshape);
    glewInit();
    glXSwapIntervalMESA(0);

    glutMainLoop();
    return 0;
}

void viewer::post_display() 
{
    glutSwapBuffers();
}


int viewer::display()
{
  GLuint VertexArrayID;
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  // An array of 3 vectors which represents 3 vertices
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f,
        };

    // This will identify our vertex buffer
    GLuint vertexbuffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    shader myShader("../res/shaders/basic.glsl");
    myShader.Bind();

    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);

  return 0;
}

unsigned int viewer::getWidth()
{
    return _width;
}
unsigned int viewer::getHeight()
{
    return _height;
}

unsigned int viewer::getWindowId()
{
    return _window_id;
}

void viewer::setWidth(int width)
{
    _width = width;
}

void viewer::setHeight(int height)
{
    _height = height;
}