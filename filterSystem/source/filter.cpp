#include "filter.h"
#include "math.h"


image filter_to_grayscale(image& img)
{
    int g_width = img.getWidth();
    int g_heigth = img.getHeight();
    int g_channels = 1;

    int channels = img.getChannels();
    image gray_img = image(g_width, g_heigth, g_channels);

    for (int i = 0; i < g_width; i++)
    {
        for (int j = 0; j < g_heigth; j++)
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



image filter_scale_up(image& img, size_t factor)
{   
    int s_width = img.getWidth() * factor;
    int s_heigth = img.getHeight() * factor;
    int s_channels = img.getChannels();

    image img_scaled_up = image(s_width, s_heigth, s_channels);

    for (int i = 0; i < img.getWidth(); i++)
    {
        for (int j = 0; j < img.getHeight(); j++)
        {
            unsigned char pixVal = img.getPixel(i,j);
            
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

image filter_sobel(image& img)
{   
    int s_width = img.getWidth();
    int s_heigth = img.getHeight();
    int s_channels = img.getChannels();

    image sobel_image = image(s_width, s_heigth, s_channels);

    unsigned char* arr = img.getPixels();

    for (int i = 1; i < s_width-1; i++)
    {
        for (int j = 1; j < s_heigth-1; j++)
        {
            int pixel_x = 0;
            int pixel_y = 0;

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

image convolution(image& img, const double mask[3][3])
{
    int width = img.getWidth();
    int height = img.getHeight();
    int channels = img.getChannels();

    image conv_image = image(width, height, channels);    

    for (int i = 1; i < width -1; i++)
    {
        for (int j = 1; j < height -1; j++)
        {
            int pix = 0;

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


image filter_edge_detect(image& img)
{   
    return convolution(img, egde_mask);
}

image filter_sharpen(image& img)
{
    return convolution(img, sharpen_mask);
}

image filter_box_blur(image& img)
{
    return convolution(img, box_blur_mask);
}

image filter_gaussian_blur(image& img)
{
    return convolution(img, gaussian_blur_mask);
}