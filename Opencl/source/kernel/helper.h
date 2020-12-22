/* filter to apply to image*/


#ifndef BLACK
#define BLACK 0
#endif

#ifndef WHITE
#define WHITE 1
#endif

#define kernel_size 3

float sobel_x[kernel_size][kernel_size] = {{-1, 0, 1},
                       {-2, 0, 2},
                       {-1, 0, 1}};


float sobel_y[kernel_size][kernel_size] = {{-1, -2, -1},
                        {0, 0, 0},
                        {1, 2, 1}};


int checkBorders(int i, int j, unsigned int width, unsigned int height)
{

}