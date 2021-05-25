#include "utilitary.h"

/**
 * show all the necessary commands to run the project 
*/
void show_help()
{
    std::cout << "Usage: filter [OPTION]..." << std::endl;
    std::cout << std::endl;

    std::cout << "Options:" << std::endl;
    std::cout << "   --file      Filename the name of the file you want to apply filter " << std::endl;
    std::cout << "   --help      Show this help" << std::endl;
    exit(0);
}

/**
 * save the final image in a specified place
 * 
 * @param img the image we want to save
 * @param filename the name of the saved image
*/
void save_image(image img, std::string filename)
{
    stbi_write_jpg(filename.c_str(), img.getWidth(), img.getHeight(), img.getChannels(), img.getPixels(), 100);
}

/***
 * run the image viewer 
*/
void run_viewer()
{
    viewer* v = v->getInstance();
    if (v->display_init() < 0)
    {
        LOG_ERROR("initialisation failed");
        exit(1);
    }

    if(v->display_open() < 0)
    {
        LOG_ERROR("failed to open viewer");
        exit(1);
    }
}
