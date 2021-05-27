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
        LOG_ERROR("Error: Too much parameter. Please refer to the help.");
        cout << endl;
        show_help();
    }

    cout << "welcome to filter system" << endl;
    int choice;
    do
    {
        cin >> choice;
        //show_menu();

            std::cout << "0. Open the viewer" << std::endl;
    std::cout << "1. Apply detect egde filter"     << std::endl;
    std::cout << "2. Apply sharpen edge filter"    << std::endl;
    std::cout << "3. Apply box blur filter"        << std::endl;
    std::cout << "4. Apply gaussian blur filter"   << std::endl;
    std::cout << "5. Apply sobel filter"           << std::endl;
    std::cout << "6. Scale up your image/images"   << std::endl;
    std::cout << "7. close the application"        << std::endl;

        switch (choice)
        {
        case 0:
            run_viewer();
            break;
        
        default:
            break;
        }
    } while (choice != 9);
    
    if (isFile)
    {
        std::string name = getFileName(path);
        image img = image(path, name);
        image gray_img = filter_to_grayscale(img);
        image scaled_img = filter_edge_detect(gray_img);
        
        //std::string save = "./" + name + ".jpg";
        //save_image(scaled_img, save);
        
        viewer* v = v->getInstance();
        v->addImage(gray_img);
        v->addImage(scaled_img);
        run_viewer();
        
    } else if (isFolder)
    {
       vector<image> images = load_images(path);

       viewer* v = v->getInstance();

       for (auto it = images.begin(); it != images.end(); it++)
       {
           v->addImage(*it);
       }

       run_viewer();
    }
    
    cout << "done" << endl;
    return 0;


}