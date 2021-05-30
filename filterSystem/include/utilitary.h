#ifndef INCLUDE_UTILITARY_H
#define INCLUDE_UTILITARY_H

#include "viewer_utilitary.h"
#include "image.h"
#include "stb_image_write.h"
#include "filter.h"
#include <dirent.h>

const int max_factor = 100;
const int min_factor = 0;

void show_help();
void show_menu();
std::vector<image> load_images(std::string& dirname);
void save_image(image& img, std::string& filename);
void save_folder(std::vector<image>& imgs, std::string& dirname);
void run_viewer();
std::string getFileName(const std::string& s);

#endif