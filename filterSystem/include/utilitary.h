#ifndef INCLUDE_UTILITARY_H
#define INCLUDE_UTILITARY_H

#include "viewer.h"
#include "image.h"
#include "stb_image_write.h"
#include <dirent.h>

void show_help();
std::vector<image> load_images(std::string& dirname);
void save_image(image& img, std::string& filename);
void save_folder(std::vector<image>& imgs, std::string& dirname);
void run_viewer();
std::string getFileName(const std::string& s);

#endif