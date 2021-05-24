#include "filter.h"
#include "math.h"

double sobel_x[3][3] = { { -1, 0, 1 },
                         { -2, 0, 2 },
                         {-1, 0, 1 } };


double sobel_y[3][3] = { { -1, -2, -1 },
                         { 0,  0,  0 },
                         { 1,  2,  1 } };


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

    int pixel_x = 0;
    int pixel_y = 0;

    unsigned char* arr = img.getPixels();

    for (int i = 1; i < s_width-1; i++)
    {
        for (int j = 1; j < s_heigth-1; j++)
        {
            pixel_x = (sobel_x[0][0] * arr[s_width * (j-1) + (i-1)])
                    + (sobel_x[0][1] * arr[s_width * (j-1) +  i   ])
                    + (sobel_x[0][2] * arr[s_width * (j-1) + (i+1)])
                    + (sobel_x[1][0] * arr[s_width *  j    + (i-1)])
                    + (sobel_x[1][1] * arr[s_width *  j    +  i   ])
                    + (sobel_x[1][2] * arr[s_width *  j    + (i+1)])
                    + (sobel_x[2][0] * arr[s_width * (j+1) + (i-1)])
                    + (sobel_x[2][1] * arr[s_width * (j+1) +  i   ])
                    + (sobel_x[2][2] * arr[s_width * (j+1) + (i+1)]);

            pixel_y = (sobel_y[0][0] * arr[s_width * (j-1) + (i-1)])
                    + (sobel_y[0][1] * arr[s_width * (j-1) +  i   ])
                    + (sobel_y[0][2] * arr[s_width * (j-1) + (i+1)])
                    + (sobel_y[1][0] * arr[s_width *  j    + (i-1)])
                    + (sobel_y[1][1] * arr[s_width *  j    +  i   ])
                    + (sobel_y[1][2] * arr[s_width *  j    + (i+1)])
                    + (sobel_y[2][0] * arr[s_width * (j+1) + (i-1)])
                    + (sobel_y[2][1] * arr[s_width * (j+1) +  i   ])
                    + (sobel_y[2][2] * arr[s_width * (j+1) + (i+1)]);

            int val = (int)sqrt((pixel_x * pixel_x) + (pixel_y * pixel_y));

            if(val < 0) val = 0;
            if(val > 255) val = 255;
         
            sobel_image.setPixel(i, j, val);
        }
    }

    return sobel_image;
}
