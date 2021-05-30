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

    string path;
    vector<image> images;
    vector<image> filtered_images;

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

    if (isFile)
    {
        std::string name = getFileName(path);
        image img = image(path, name);
        image gray_img = filter_to_grayscale(img);
        img = gray_img;
        
    } else if (isFolder)
    {
       vector<image> images = load_images(path);
    }

    cout << "welcome to filter system" << endl;
    cout << endl;
    int choice;
    
    do
    {
        show_menu();
        cout << endl;
        cout << "Select your choice by entering the appropriate number and press enter" << endl;
        cin >> choice;
        
        switch (choice)
        {
        case 0:
            if (filtered_images.size() > 0)
            {
                run_viewer(filtered_images);
            } else 
            {
                std::cout << "Nothing to display. Please choose one operation before using the viewer." << endl;
            }
            break;
        case 1:
            if (isFile)
            {
                std::string name = getFileName(path);
                image img = image(path, name);
                image gray_image = filter_to_grayscale(img);
                image edge_image = filter_edge_detect(gray_image);
                filtered_images.push_back(edge_image);
            } else if (isFolder)
            {
                vector<image> images = load_images(path);
                for (auto it = images.begin(); it != images.end(); it++)
                {
                    image gray_image = filter_to_grayscale(*it);
                    image edge_image = filter_edge_detect(gray_image);
                    filtered_images.push_back(edge_image);
                }
            }
            break;
        case 2:
            if (isFile)
            {
                std::string name = getFileName(path);
                image img = image(path, name);
                image gray_image = filter_to_grayscale(img);
                image sharpen_image = filter_sharpen(gray_image);
                filtered_images.push_back(sharpen_image);
            } else if (isFolder)
            {
                vector<image> images = load_images(path);
                for (auto it = images.begin(); it != images.end(); it++)
                {
                    image gray_image = filter_to_grayscale(*it);
                    image sharpen_image = filter_sharpen(gray_image);
                    filtered_images.push_back(sharpen_image);
                }
            }
            break;
        case 3:
            if (isFile)
            {
                std::string name = getFileName(path);
                image img = image(path, name);
                image gray_image = filter_to_grayscale(img);
                image box_blur_image = filter_box_blur(gray_image);
                filtered_images.push_back(box_blur_image);
            } else if (isFolder)
            {
                vector<image> images = load_images(path);
                for (auto it = images.begin(); it != images.end(); it++)
                {
                    image gray_image = filter_to_grayscale(*it);
                    image box_blur_image = filter_box_blur(gray_image);
                    filtered_images.push_back(box_blur_image);
                }
            }
            break;
        case 4:
            if (isFile)
            {
                std::string name = getFileName(path);
                image img = image(path, name);
                image gray_image = filter_to_grayscale(img);
                image gaussian_blur_image = filter_box_blur(gray_image);
                filtered_images.push_back(gaussian_blur_image);
            } else if (isFolder)
            {
                vector<image> images = load_images(path);
                for (auto it = images.begin(); it != images.end(); it++)
                {
                    image gray_image = filter_to_grayscale(*it);
                    image gaussian_blur_image = filter_box_blur(gray_image);
                    filtered_images.push_back(gaussian_blur_image);
                }
            }
            break;
        case 5:
            if (isFile)
            {
                std::string name = getFileName(path);
                image img = image(path, name);
                image gray_image = filter_to_grayscale(img);
                image sobel_image = filter_sobel(gray_image);
                filtered_images.push_back(sobel_image);
            } else if (isFolder)
            {
                vector<image> images = load_images(path);
                for (auto it = images.begin(); it != images.end(); it++)
                {
                    image gray_image = filter_to_grayscale(*it);
                    image sobel_image = filter_sobel(gray_image);
                    filtered_images.push_back(sobel_image);
                }
            }
            break;
        case 6:
            if (isFile)
            {
                int factor;
                do
                {
                    cout << "Please enter your scaling factor between 0 and 100" << endl;
                    cin >> factor;
                } while (factor > max_factor || factor < min_factor);
                
                std::string name = getFileName(path);
                image img = image(path, name);
                image gray_image = filter_to_grayscale(img);
                image scaled_image = filter_scale_up(gray_image, factor);
                filtered_images.push_back(scaled_image);
            } else if (isFolder)
            {
                vector<image> images = load_images(path);
                for (auto it = images.begin(); it != images.end(); it++)
                {
                    image gray_image = filter_to_grayscale(*it);
                    image scaled_image = filter_box_blur(gray_image);
                    filtered_images.push_back(scaled_image);
                }
            }
            break;
        
        case 7:
            cout << "going to save" << endl;
            if (isFile)
            {
                std::string filename = getFileName(path) + ".jpg";
                image img = v->images[0];
                save_image(img, filename);
            } else 
            {
                images = v->images;
                save_folder(images, path);
            }

            save_folder(images, path);
            break;

        case 9:
            choice = 9;
            cout << "closing the application" << endl;
            break;
        default:
            cout << "Wrong number please refer to the menu" << endl;
            break;
        }
    } while (choice != 9);
    
    return 0;
}