#include "utilitary.h"

/**
 * show all the necessary commands to run the project 
*/
void show_help()
{
    std::cout << "Usage: filter [OPTION]..." << std::endl;
    std::cout << std::endl;

    std::cout << "Options:" << std::endl;
    std::cout << "   --file             Filename the name of the file you want to apply filter " << std::endl;
    std::cout << "   --directory        Filename the name of the directory you want to apply filter " << std::endl;
    std::cout << "   --help             Show this help" << std::endl;
    exit(0);
}


/**
 * load all png image in the folder
 * 
 * @param dirname the name of the folder containing
 * png images
 * 
 * @return list of all image found
*/
std::vector<image> load_images(std::string& dirname)
{
    std::vector<image> imgs;
    DIR* dir = opendir(dirname.c_str());
    if (dir == NULL)
    {
        LOG_ERROR_NULL_PTR();
        exit(1);
    }

    struct dirent* entity; 
    entity = readdir(dir);

    while (entity != NULL)
    {
        char filepath[100] = {0};
        strcat(filepath, dirname.c_str());
        strcat(filepath, "/");
        strcat(filepath, entity->d_name);
        entity = readdir(dir);

       std::string s = std::string(filepath);
       if (s.find(".png") != std::string::npos) 
       {
           std::cout << filepath << std::endl;
       }
    }

    return imgs;
}




/**
 * save the final image in a specified place
 * 
 * @param img the image we want to save
 * @param filename the name of the saved image
*/
void save_image(image& img, std::string& filename)
{
    stbi_write_jpg(filename.c_str(), img.getWidth(), img.getHeight(), img.getChannels(), img.getPixels(), 100);
}

/**
 * save all image in a folder
 * 
 * @param imgs list of all images we want to save
 * @param dirname the directory where we want the images
 * 
*/
void save_folder(std::vector<image>& imgs, std::string& dirname)
{
    for (auto it = imgs.begin(); it != imgs.end(); it++)
    {
        std::string filename = dirname + "/" + it->getName() + ".jpg";
        save_image(*it, filename);
    }
}

/***
 * run the image viewer 
*/
void run_viewer()
{
    viewer* v = v->getInstance();
    if (v->display_init() < 0)
    {
        LOG_ERROR("initialisation failed");
        exit(1);
    }

    if(v->display_open() < 0)
    {
        LOG_ERROR("failed to open viewer");
        exit(1);
    }
}

/** code from https://www.oreilly.com/library/view/c-cookbook/0596007612/ch10s15.html*/
std::string getFileName(const std::string& s) 
{
   char sep = '/';
   std::string extension = ".png";

#ifdef _WIN32
   sep = '\\';
#endif

   size_t i = s.rfind(sep, s.length());
   size_t j = s.rfind(extension, s.length());
   if (i != std::string::npos && j != std::string::npos) {
      return(s.substr(i+1, j-i-1));
   }

   return("");
}
