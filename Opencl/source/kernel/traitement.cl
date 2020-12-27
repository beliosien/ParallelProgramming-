#include "helpers.cl"

struct __attribute__((packed)) params_t {
    unsigned int width;
    unsigned int height;
    unsigned int buffer_size; 
};

__kernel void sobel_filter(__global unsigned int* buffer_in, struct params_t params, __global unsigned int* buffer_out){
    int i, j;
    int pixel_x = 0;
    int pixel_y = 0;

    i = get_global_id(0);
    j = get_global_id(1);

    for(int row = 0; row < kernel_size; i++)
    {
        for(int column = 0; column < kernel_size; j++)
        {
            int index = params.width * (j + column - 1) + (i + column - 1);
            
            if(index < params.buffer_size)
            {
                pixel_x += sobel_x[i][j] * buffer_in[index];
                pixel_y += sobel_y[i][j] * buffer_in[index];
            }
        }
    }

    double square_value = pixel_x * pixel_x + pixel_y * pixel_y;
    int value = (int)sqrt(square_value);

    if(value < 0){
        value = 0;
    } else if(value > 255){
        value = 255;
    }

    int index_out = params.width * j + i;
    buffer_out[index_out] = value;
}