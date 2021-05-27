#include <experimental/filesystem>
#include <iostream>
#include <string>
#include "utilitary.h"
#include "image.h"
#include "filter.h"

using namespace std;

int main(int argc, char *argv[]) 
{
    glutInitContextVersion(3,3);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutInit(&argc, argv);

    bool isFile = false;
    bool isFolder = false;

    std::string path;

    // Read program arguments
    for (int i=1; i<argc; i++) {
        std::string arg(argv[i]);
        if (arg == "--file") 
        {
            isFile = true;
            path = argv[i+1]; i++;
        } else if (arg == "--directory")
        {
            isFolder = true;
            path = argv[i+1]; i++;
        } 
        else if (arg == "--help")
        {
            show_help();
        }
    }

    if (path.empty())
    {
        LOG_ERROR("Error: File missing. Please enter your file or directory.");
        cout << endl;
        show_help(); 
    }

    if (isFile && isFolder)
    {
        LOG_ERROR("Error: Parameters are wrong. Please refer to the help.");
        cout << endl;
        show_help();
    }

    cout << "welcome to filter system" << endl;
    
    if (isFile)
    {
        std::string name = getFileName(path);

        image img = image(path, name);
        image gray_img = filter_to_grayscale(img);
        viewer* v = v->getInstance();
        std::string save = "./" + name;
        save_image(img, save);
        v->addImage(gray_img);
        run_viewer();
        
    } else if (isFolder)
    {
        load_images(path);
    }
    
    cout << "done" << endl;
    return 0;


}