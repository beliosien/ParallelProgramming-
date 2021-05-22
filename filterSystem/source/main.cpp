#include <iostream>
#include <string>
#include "image.h"
#include "filter.h"
#include "stb_image_write.h"

using namespace std;

void show_help()
{
    cout << "Usage: filter [OPTION]..." << endl;
    cout << endl;

    cout << "Options:" << endl;
    cout << "   --file      Filename the name of the file you want to apply filter " << endl;
    cout << "   --help      Show this help" << endl;
    exit(0);
}

void save_image(image img)
{
    string filename = "./result.jpg";
    stbi_write_jpg(filename.c_str(), img.getWidth(), img.getHeight(), img.getChannels(), img.getPixels(), 100);
}


int main(int argc, char *argv[]) 
{
    std::string file_path;

    // Read program argument
    for (int i=1; i<argc; i++) {
        std::string arg(argv[i]);
        if (arg == "--file") 
        {
            file_path = argv[i+1]; i++;
        } else if (arg == "--help")
        {
            show_help();
            i++;
        }
    }

    if (file_path.empty())
    {
        cout << "Error: File missing. Please enter your file." << endl;
        cout << endl;
        show_help(); 
    }

    cout << "welcome to filter system" << endl;

    image img = image(file_path);
    image scaled_img = filter_scale_up(img, 2);
    save_image(scaled_img);

    cout << "done" << endl;
}