/* DO NOT EDIT THIS FILE */

#ifndef INCLUDE_DISPLAY_H_
#define INCLUDE_DISPLAY_H_

/***
 * display helps us to see any kind of image
*/

#include "image.h"

int display_init(image_dir_t* image_dir);
void display_destroy();
int display_open();

#endif /* INCLUDE_DISPLAY_H_ */