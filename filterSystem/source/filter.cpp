#include "filter.h"

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

