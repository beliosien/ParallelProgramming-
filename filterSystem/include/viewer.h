#ifndef INCLUDE_VIEWER_H
#define INCLUDE_VIEWER_H

#include <GL/glew.h>
#include "shader.h"
#include <iostream>
#include <string>
#include <vector>
#include "image.h"

#include <GL/glxew.h>
#include "log.h"


#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#define WIDTH 640
#define HEIGHT 480


class viewer
{
private:
    static viewer* _viewer;
    unsigned int _width;
    unsigned int _height;
    unsigned int _window_id;
    std::vector<image> _images;
    GLuint _texture;
    bool _enabled;
    
    viewer();
    ~viewer();

public:

    /**
     * get the viewer instance
     * 
     * @return the instance of the viewer
    */
    static viewer* getInstance()
    {
        if (!_viewer)
        {
            _viewer = new viewer();
        }
        return _viewer;
    }

    void addImage(image& img);
    
    int display_init();
    static int pre_display();
    int display_open();
    static void post_display();
    
    static void callback_display();
    static void callback_idle();
    static void callback_keyboard(unsigned char key, int x, int y);
    static void callback_reshape(int width, int height);

    static int display();


    unsigned int getWidth();
    unsigned int getHeight();
    unsigned int getWindowId();

    void setWidth(int width);
    void setHeight(int height);
};

#endif