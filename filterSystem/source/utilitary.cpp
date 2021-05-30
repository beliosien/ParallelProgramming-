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
 * show the menu
*/
void show_menu()
{
    std::cout << "0. Open the viewer"              << std::endl;
    std::cout << "1. Apply detect egde filter"     << std::endl;
    std::cout << "2. Apply sharpen edge filter"    << std::endl;
    std::cout << "3. Apply box blur filter"        << std::endl;
    std::cout << "4. Apply gaussian blur filter"   << std::endl;
    std::cout << "5. Apply sobel filter"           << std::endl;
    std::cout << "6. Scale up your image/images"   << std::endl;
    std::cout << "7. Save your image/images"       << std::endl;
    std::cout << "9. close the application"        << std::endl;
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
           std::string name = getFileName(filepath);
           image img = image(filepath, name);
           if (img.getChannels() > 1)
           {
                image img_one_channel = filter_to_grayscale(img);
                imgs.push_back(img_one_channel);
           } else 
           {
               imgs.push_back(img);
           }
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
    std::cout << "saving " << filename << std::endl;
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
    if (v->viewer_init() < 0)
    {
        LOG_ERROR("initialisation failed");
        exit(1);
    }

    if(viewer_open() < 0)
    {
        LOG_ERROR("failed to open viewer");
        exit(1);
    }
}

/** code from https://www.oreilly.com/library/view/c-cookbook/0596007612/ch10s15.html
 * modified by me
*/
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
