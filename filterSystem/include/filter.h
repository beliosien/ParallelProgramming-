#ifndef INCLUDE_FILTER_H
#define INCLUDE_FILTER_H

#include "image.h"
#include <vector>

#define size 3

const double sobel_x[size][size]= { 
    { -1, 0, 1 },
    { -2, 0, 2 },
    {-1, 0, 1 } };


const double sobel_y[size][size]= {
    { -1, -2, -1 },
    { 0,  0,  0 },
    { 1,  2,  1 } };

const double egde_mask[size][size]= {
    {-1, -1, -1},
    {-1,  8, -1},
    {-1, -1, -1}};

const double sharpen_mask[size][size]= {
    { -1.0 / 9.0, -1.0 /9.0,  -1.0 / 9.0},
    { -1.0 / 9.0,  1.0,       -1.0 / 9.0},
    { -1.0 / 9.0, -1.0 / 9.0, -1.0 / 9.0}};

const double box_blur_mask[size][size] = {
    { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0},
    { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0},
    { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0}};


const double gaussian_blur_mask[size][size] = {
    { 1.0 / 16.0, 2.0 / 16.0, 1.0 / 16.0},
    { 2.0 / 16.0, 4.0 / 16.0, 4.0 / 16.0},
    { 1.0 / 16.0, 2.0 / 16.0, 1.0 / 16.0}};



image filter_to_grayscale(image& img);
image filter_scale_up(image& img, size_t factor);
image filter_sobel(image& img);
image convolution(image& img, const double mask[size][size]);
image filter_edge_detect(image& img);
image filter_sharpen(image& img);
image filter_box_blur(image& img);
image filter_gaussian_blur(image& img);
image filter_to_hsv(image& img);
image filter_to_rgb(image& img);
image filter_desaturate(image& img);
image filter_edge_identity(image& img);
image filter_horizontal_flip(image& img);
image filter_vertical_flip(image& img);

#endif