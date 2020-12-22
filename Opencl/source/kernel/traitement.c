#include "helper.h"

struct __attribute__((packed)) params_t {
    unsigned int width;
    unsigned int height;
    unsigned int buffer_size; 
};



void sobel_filter(__global unsigned int* buffer_in, struct params_t params, __global unsigned int* buffer_out)
{
    int i, j;
    int pixel_x = 0;
    int pixel_y = 0;

    i = get_global_id(0);
    j = get_global_id(1);

    for (int i = 0; i < kernel_size; i++)
    {
        for (int j = 0; j < kernel_size; j++)
        {
            
        }
    }
}
