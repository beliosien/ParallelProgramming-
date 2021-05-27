#include "filter.h"
#include "math.h"
#include <omp.h>

/**
 * convert an rgb image to grayscale
 * 
 * @param img the image that we want to convert to grayscale
 * @return image in grayscale
*/
image filter_to_grayscale(image& img)
{
    int g_width = img.getWidth();
    int g_heigth = img.getHeight();
    int g_channels = 1;
    std::string name = "gray_" + img.getName();

    int channels = img.getChannels();
    image gray_img = image(g_width, g_heigth, g_channels, name);
    int i,j;

    #pragma omp parallel for collapse(2)
    for (i = 0; i < g_width; i++)
    {
        for (j = 0; j < g_heigth; j++)
        {
            int index = i * channels + j * channels * g_width;
            unsigned char pix1 = img.getPixel(index);
            unsigned char pix2 = img.getPixel(index + 1);
            unsigned char pix3 = img.getPixel(index + 2);
            unsigned char pixVal = (unsigned char) ((pix1 + pix2 + pix3)/channels);
            gray_img.setPixel(i, j, pixVal);
        }
    }

    return gray_img;
}


/**
 * scale your image by some factor
 * 
 * @param img the image that we want to scale up
 * @param factor how much we want to enlarge the image
 * @return image scaled up
*/
image filter_scale_up(image& img, size_t factor)
{   
    int s_width = img.getWidth() * factor;
    int s_heigth = img.getHeight() * factor;
    int s_channels = img.getChannels();
    std::string name = "scaled_" + img.getName();

    image img_scaled_up = image(s_width, s_heigth, s_channels, name);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < img.getWidth(); i++)
    {
        for (int j = 0; j < img.getHeight(); j++)
        {
            unsigned char pixVal = img.getPixel(i,j);
            #pragma omp parallel for collapse(2)
            for (int ki = 0; ki < factor; ki++)
            {
                for (int kj = 0; kj < factor; kj++)
                {
                    img_scaled_up.setPixel(factor * i + ki, factor * j + kj, pixVal);
                }
           }
        }
    }

    return img_scaled_up;
}


/**
 * apply sobel filter on a image
 * 
 * @param img the image that we want apply the filter
 * @return sobel image
*/
image filter_sobel(image& img)
{   
    int s_width = img.getWidth();
    int s_heigth = img.getHeight();
    int s_channels = img.getChannels();
    std::string name = "sobel_" + img.getName();

    image sobel_image = image(s_width, s_heigth, s_channels, name);

    #pragma omp parallel for collapse(2)
    for (int i = 1; i < s_width-1; i++)
    {
        for (int j = 1; j < s_heigth-1; j++)
        {
            int pixel_x = 0;
            int pixel_y = 0;

            #pragma omp parallel for collapse(2) reduction(+:pixel_x,pixel_y)
            for (int ki = 0; ki < size; ki++)
            {
                for (int kj = 0; kj < size; kj++)
                {
                    pixel_x += img.getPixel(i-1 + ki, j-1 + kj) * sobel_x[ki][kj];
                    pixel_y += img.getPixel(i-1 + ki, j-1 + kj) * sobel_y[ki][kj];
                }
            }

            int val = (int)sqrt((pixel_x * pixel_x) + (pixel_y * pixel_y));

            if(val < 0) val = 0;
            if(val > 255) val = 255;
         
            sobel_image.setPixel(i, j, val);
        }
    }

    return sobel_image;
}


/**
 * apply convolution on an image
 * 
 * @param img the image that we want apply the convolution
 * @param mask the mask we use to apply the convolution
 * @param name the name of the image
 * @return the image convoluted
*/
image convolution(image& img, const double mask[3][3], std::string& name)
{
    int width = img.getWidth();
    int height = img.getHeight();
    int channels = img.getChannels();
    name += img.getName();

    image conv_image = image(width, height, channels, name);    

    #pragma omp parallel for collapse(2)
    for (int i = 1; i < width -1; i++)
    {
        for (int j = 1; j < height -1; j++)
        {
            int pix = 0;

            #pragma omp parallel for collapse(2) reduction(+:pix)
            for (int ki = 0; ki < size; ki++)
            {
                for (int kj = 0; kj < size; kj++)
                {
                    pix += img.getPixel(i-1+ki, j-1+kj) * mask[ki][kj];
                }
            }

            conv_image.setPixel(i,j, pix);
        }
    }

    return conv_image;
}

/**
 * detect the egde of an image
 * 
 * @param img the image that we want to detect edge
 * @return the image with edge detected
*/
image filter_edge_detect(image& img)
{   
    std::string name = "edge_";
    return convolution(img, egde_mask, name);
}

/**
 * sharpen the edge of your image
 * 
 * @param img the image that we want to sharpe edge
 * @return the image with edge sharpened
*/
image filter_sharpen(image& img)
{
    std::string name = "sharpen_";
    return convolution(img, sharpen_mask, name);
}

/**
 * blur your image using box blur filter
 * 
 * @param img the image that we want to blur
 * @return the image blurred
*/
image filter_box_blur(image& img)
{
    std::string name = "box_blur_";
    return convolution(img, box_blur_mask, name);
}

/**
 * blur your image using gaussian blur filter
 * 
 * @param img the image that we want to blur
 * @return the image blurred
*/
image filter_gaussian_blur(image& img)
{
    std::string name = "gaussian_blur";
    return convolution(img, gaussian_blur_mask, name);
}