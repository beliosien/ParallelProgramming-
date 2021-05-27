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
    std::string _name;
    unsigned char* _pixels;
    
public:
    image(std::string filename, std::string name);
    image(int width, int height, int channels, std::string name);
    image();
    ~image();

    int getWidth();
    int getHeight();
    int getChannels();
    std::string getName();

    unsigned char* getPixels();
    unsigned char getPixel(int i, int j);
    unsigned char getPixel(int index);

    void setPixel(int i, int j, unsigned char pixVal);
};

#endif


