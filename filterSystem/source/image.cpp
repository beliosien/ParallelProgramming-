#include "image.h"
#include "stb_image.h"


image::image(std::string filename, std::string name)
{
    _pixels = stbi_load(filename.c_str(), &_width, &_height, &_channels, 0);
    _name = name;
    if (_pixels == nullptr)
    {
        std::cout << "image not found" << std::endl;
    }
}

image::image(int width, int height, int channels, std::string name)
{
    _width = width;
    _height = height;
    _channels = channels;
    _name = name;
    _pixels = new unsigned char[_width*_height*_channels];

    if (_pixels == NULL)
    {
        std::cout << "Error allocating space for the pixels array of the image" << std::endl;
    }
}

image::image(): _width(0), _height(0), _channels(0), _name(""),_pixels(NULL)
{
}

image::~image()
{
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
 * @return the name of the image
*/
std::string image::getName()
{
    return _name;
}

/**
 * @return the pixel array of the image
*/
unsigned char* image::getPixels()
{
    return _pixels;
}

/**
 * @param i position of the pixel in the horizontal axis
 * @param j position of the pixel in the vertical axis
 * @return the pixel of the image at the given position
*/
unsigned char image::getPixel(int i, int j)
{
    if (i >=0 && i < _width && j >=0 && j < _height)
    {
        return _pixels[i *_channels + j * _width *_channels];
    }

    return -1;
}

/**
 * @param index index of the pixel we want to get
 * @return the pixel of the image at the given position
*/
unsigned char image::getPixel(int index)
{
    if (index < _channels*_height*_width && index >=0)
    {
        return _pixels[index];
    }

    return 0;
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
        _pixels[i * _channels + j * _width * _channels] = pixVal;
    } else {
        std::cout << "out of bonds set pixel" << std::endl;
    }
}