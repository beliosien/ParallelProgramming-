#ifndef INCLUDE_FILTER_H
#define INCLUDE_FILTER_H

#include "image.h"

image filter_to_grayscale(image& img);
image filter_scale_up(image& img, size_t factor);
image filter_sobel(image& img);
image filter_to_hsv(image& img);
image filter_to_rgb(image& img);
image filter_desaturate(image& img);
image filter_edge_identity(image& img);
image filter_edge_detect(image& img);
image filter_sharpen(image& img);
image filter_box_blur(image& img);
image filter_gaussian_blur(image& img);
image filter_horizontal_flip(image& img);
image filter_vertical_flip(image& img);

#endif