#include "filter.h"

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

