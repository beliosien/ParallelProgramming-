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
