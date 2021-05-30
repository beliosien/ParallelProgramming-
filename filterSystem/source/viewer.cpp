#include "viewer.h"


viewer::viewer(unsigned int width, unsigned int height, unsigned int window_id, std::vector<image>& images,
                GLuint texture, bool enabled)
{
    this->width          = width;
    this->height         = height;
    this->window_id      = window_id;
    this->images         = images;
    this->texture        = texture;
    this->enabled        = enabled;
    this->curr_pos       = 0;

    show_viewer_commands();
}


/**
 * add image 
 * 
 * @param img the image we want to add
*/
void viewer::addImage(image& img)
{
    images.push_back(img);
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

    std::cout << "Thank you." << std::endl;
}




















