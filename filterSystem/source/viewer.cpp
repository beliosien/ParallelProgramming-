#include "viewer.h"

viewer *viewer::_viewer = 0;

viewer::viewer()
{
    _curr_pos = 0;
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


/**
 * Initialize de the viewer
 * @return 0 if everything went well and -1 in the opposite
*/
int viewer::viewer_init()
{
    _width = WIDTH;
    _height = HEIGHT;
    _window_id = 0;
    _texture = 0;
    _enabled = true;

    show_viewer_commands();

    return 0;
}


/**
 * @return the width of the viewer
*/
unsigned int viewer::getWidth()
{
    return _width;
}


/**
 * @return the height of the viewer
*/
unsigned int viewer::getHeight()
{
    return _height;
}


/**
 * @return the window id of the viewer
*/
unsigned int viewer::getWindowId()
{
    return _window_id;
}


/**
 * @return the current position in the list of images
*/
int viewer::getCurrpos()
{
    return _curr_pos;
}


/**
 * @return wether or not the viewer is active
*/
bool viewer::getIsEnabled()
{
    return _enabled;
}


/**
 * @return all images
*/
 std::vector<image> viewer::getImages()
 {
    return _images;
 }


/**
 * @return true/false whether or not the window has been initalized
*/
 bool viewer::getisInit()
 {
    return _isInit;
 }


/**
 * @return the texture of the viewer
*/
 GLuint viewer::getTexture()
 {
    return _texture;
 }


/**
 * set the width of the viewer
 * 
 * @param width the width of the viewer
*/
void viewer::setWidth(int width)
{
    _width = width;
}


/**
 * set the height of the viewer
 * 
 * @param height the height of the viewer
*/
void viewer::setHeight(int height)
{
    _height = height;
}


/**
 * set the id of the window
 * 
 * @param id the id of the window
*/
void viewer::setWindowId(int id)
{
    _window_id = id;
}


/**
 * set the value of isInit
 * 
 * @param isInit the value that we want to assign to isInit
*/
void viewer::setisInit(bool isInit)
{
    _isInit = isInit;
}


/**
 * set the current position in the list of images
 * 
 * @param curPos the current position
*/
void viewer::setCurrPos(int curPos)
{
    _curr_pos = curPos;
}
    

/**
 * tell whether or not we want to enable the viewer
 *
 *  @param isEnabled
*/    
void viewer::setIsEnable(bool isEnabled)
{
    _enabled = isEnabled;
}

/**
 * show all the commands to interact with the viewer
*/
void viewer::show_viewer_commands()
{
    std::cout << "Welcome to my viewer" << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << std::endl;

    std::cout << "Options:" << std::endl;
    std::cout << " press 'r'             to move to the next image"     << std::endl;
    std::cout << " press 'l'             to move to the previous image" << std::endl;
    std::cout << " press space           to enable/disable the viewer"  << std::endl;
    std::cout << " press 'q'             to quit the application"       << std::endl;

    std::cout << "Thank you" << std::endl;
}




















