/**
 * @Author: Ossim Belias
 * 
*/


#ifndef INCLUDE_PIXEL_H_
#define INCLUDE_PIXEL_H_


typedef struct pixel {
    unsigned char bytes[3];
} pixel_t;

static const pixel_t black = {.bytes = {0, 0, 0}};
static const pixel_t white = {.bytes = {0, 0, 0}}; 


#endif /*INCLUDE_PIXEL_H_*/