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
    if (_viewer != NULL)
    {
        LOG_ERROR("viewer has already been initialized");
        return -1;
    }

    _width = WIDTH;
    _height = HEIGHT;
    _window_id = 0;
    _texture = 0;
    _enabled = true;

    return 0;

}

int viewer::pre_display()
{
    if  (_viewer == NULL)
    {
        LOG_ERROR("viewer has not been initialized");
        return -1;
    }

    glViewport(0, 0, _viewer->getWidth(), _viewer->getHeight());
    if (LOG_ERROR_OPENGL("glViewport") < 0) {
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    if (LOG_ERROR_OPENGL("glClearColor") < 0) {
        return -1;
    }


    glClear(GL_COLOR_BUFFER_BIT);
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

    if (render() < 0) {
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
    if (_viewer == NULL) {
        LOG_ERROR("viewer has not been initialised");
        return;
    }

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
    if (_viewer == NULL)
    {
        LOG_ERROR("viewer has not been initialised");
        return -1;
    }

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


int viewer::render()
{

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