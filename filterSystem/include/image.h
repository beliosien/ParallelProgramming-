#ifndef INCLUDE_IMAGE_H
#define INCLUDE_IMAGE_H

#include <iostream>
#include <string>
#include "log.h"


class image
{
private:
    int _width;
    int _height;
    int _channels;
    unsigned char* _pixels;
    
public:
    image(std::string filename);
    image(int width, int height, int channels);
    ~image();

    int getWidth();
    int getHeight();
    int getChannels();

    unsigned char* getPixels();
    unsigned char getPixel(int i, int j);
    unsigned char getPixel(int index);

    void setPixel(int i, int j, unsigned char pixVal);
};

#endif


