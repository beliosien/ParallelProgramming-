#ifndef INCLUDE_FILTER_H
#define INCLUDE_FILTER_H

#include "image.h"
#include <vector>

#define mask_size 3

const double sobel_x[mask_size][mask_size]= { 
    { -1, 0, 1 },
    { -2, 0, 2 },
    {-1, 0, 1 } };


const double sobel_y[mask_size][mask_size]= {
    { -1, -2, -1 },
    { 0,  0,  0 },
    { 1,  2,  1 } };

const double egde_mask[mask_size][mask_size]= {
    {-1, -1, -1},
    {-1,  8, -1},
    {-1, -1, -1}};

const double sharpen_mask[mask_size][mask_size]= {
    { -1.0 / 9.0, -1.0 /9.0,  -1.0 / 9.0},
    { -1.0 / 9.0,  1.0,       -1.0 / 9.0},
    { -1.0 / 9.0, -1.0 / 9.0, -1.0 / 9.0}};

const double box_blur_mask[mask_size][mask_size] = {
    { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0},
    { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0},
    { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0}};


const double gaussian_blur_mask[mask_size][mask_size] = {
    { 1.0 / 16.0, 2.0 / 16.0, 1.0 / 16.0},
    { 2.0 / 16.0, 4.0 / 16.0, 4.0 / 16.0},
    { 1.0 / 16.0, 2.0 / 16.0, 1.0 / 16.0}};


image filter_to_grayscale(image& img);
image filter_scale_up(image& img, size_t factor);
image filter_sobel(image& img);
image convolution(image& img, const double mask[mask_size][mask_size], std::string& name);
image filter_edge_detect(image& img);
image filter_sharpen(image& img);
image filter_box_blur(image& img);
image filter_gaussian_blur(image& img);

#endif