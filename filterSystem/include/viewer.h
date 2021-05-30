#ifndef INCLUDE_VIEWER_H
#define INCLUDE_VIEWER_H

#include <iostream>
#include <string>
#include <vector>
#include "image.h"


typedef struct viewer
{
    unsigned int width;
    unsigned int height;
    unsigned int window_id;
    std::vector<image> images;
    GLuint texture;
    bool enabled;
    int curr_pos;

    viewer(unsigned int width, unsigned int height, unsigned int window_id, std::vector<image>& images,
                GLuint texture, bool enabled);

    void addImage(image& img);
    void show_viewer_commands();

} viewer;

#endif