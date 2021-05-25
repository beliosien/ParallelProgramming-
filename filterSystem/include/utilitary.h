#ifndef INCLUDE_UTILITARY_H
#define INCLUDE_UTILITARY_H

#include "viewer.h"
#include "image.h"
#include "stb_image_write.h"

void show_help();
void save_image(image img, std::string filename);
void run_viewer();

#endif