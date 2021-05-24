#ifndef INCLUDE_VIEWER_H
#define INCLUDE_VIEWER_H

#include <iostream>
#include <string>
#include <vector>
#include "image.h"
#include "log.h"

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

public:
    viewer();
    ~viewer();

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
    int pre_display();
    void display();
    void post_display();

    int getWidth();
    int getHeight();
};

#endif