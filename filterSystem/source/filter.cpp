#include "filter.h"
#include "math.h"

#define sobel_size 3

const std::vector<std::vector<float>> sobel_x = { { 1, 0, -1 }, 
                                                { 2, 0, -2 }, 
                                                { 1, 0, -1 } };


const std::vector<std::vector<float>> soble_y = { { 1, 2, 1 }, 
                                                { 0, 0, 0 }, 
                                                {-1, -2,-1 } };


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

    image sobel_image = image(s_width, s_width, s_channels);

    for (int i = 0; i < s_width; i++)
    {
        for (int j = 0; j < s_heigth; j++)
        {
            float pixVal_x = 0.0;
            float pixVal_y = 0.0;
            for (int ki = 0; ki < sobel_size; ki++)
            {
                for (int kj = 0; kj < sobel_size; kj++)
                {
                    pixVal_x += img.getPixel(i, j) * sobel_x[ki][kj];
                    pixVal_y += img.getPixel(i,j) * soble_y[ki][kj];
                }
            }

            int pixVal = (int) sqrt(pixVal_x * pixVal_x + pixVal_y * pixVal_y);

            if (pixVal > 255) pixVal = 255;
            if (pixVal < 0) pixVal = 0;

            sobel_image.setPixel(i, j, pixVal);
        }
    }

    return sobel_image;
}
