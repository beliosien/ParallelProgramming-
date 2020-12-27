/* filter to apply to image*/


#ifndef BLACK
#define BLACK 0
#endif

#ifndef WHITE
#define WHITE 1
#endif

#define kernel_size 3

__constant float sobel_x[kernel_size][kernel_size] = {{-1, 0, 1},
                       {-2, 0, 2},
                       {-1, 0, 1}};


__constant float sobel_y[kernel_size][kernel_size] = {{-1, -2, -1},
                        {0, 0, 0},
                        {1, 2, 1}};
