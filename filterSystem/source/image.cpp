#include "image.h"
#include "stb_image.h"


image::image(std::string filename)
{
    _pixels = stbi_load(filename.c_str(), &_width, &_height, &_channels, 0);

    if (_pixels == nullptr)
    {
        std::cout << "image not found" << std::endl;
    }
}

image::image(int width, int height, int channels)
{
    _width = width;
    _height = height;
    _channels = channels;
    _pixels = new unsigned char[_width*_height*_channels];

    if (_pixels == nullptr)
    {
        std::cout << "Error allocating space for the pixels array of the image" << std::endl;
    }
}

image::~image()
{
    delete _pixels;
}

/**
 * @return the width of the image
*/

int image::getWidth()
{
    return _width;
}

/**
 * @return the height of the image
*/

int image::getHeight() 
{
    return _height;
}

/**
 * @return the channels of the image
*/
int image::getChannels()
{
    return _channels;
}

/**
 * @return the width of the pixels of the image
*/

unsigned char* image::getPixels()
{
    return _pixels;
}

/**
 * @param i position of the pixel in the horizontal axis
 * @param j position of the pixel in the vertical axis
 * @return the width of the image
*/
unsigned char image::getPixel(int i, int j)
{
    if (i >=0 && i < _width && j >=0 && j < _height)
    {
        return _pixels[i + j * _width];
    }

    return -1;
}


/**
 * set the value of a pixel at the given position
 * 
 * @param i position of the pixel in the horizontal axis
 * @param j position of the pixel in the vertical axis
*/
void image::setPixel(int i, int j, unsigned char pixVal)
{
    if (i >=0 && i < _width && j >=0 && j < _height)
    {
        _pixels[i + j * _width] = pixVal;
    }
}