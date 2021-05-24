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

    glViewport(0, 0, _width, _height);
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