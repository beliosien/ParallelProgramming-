#ifndef INCLUDE_VIEWER_H
#define INCLUDE_VIEWER_H

#include <iostream>
#include <string>
#include <vector>
#include "image.h"

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
    int _curr_pos;
    bool _isInit = false;
    
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
    
    int viewer_init();
    unsigned int getWidth();
    unsigned int getHeight();
    unsigned int getWindowId();
    int getCurrpos();
    bool getIsEnabled();
    std::vector<image> getImages();
    bool getisInit();
    GLuint getTexture();

    void setWidth(int width);
    void setHeight(int height);
    void setWindowId(int id);
    void setisInit(bool isInit);
    void setCurrPos(int curPos);
    void setIsEnable(bool isEnabled);

    void show_viewer_commands();
    
    
};

#endif