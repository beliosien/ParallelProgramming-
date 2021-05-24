#include <iostream>
#include <string>
#include "utilitary.h"
#include "image.h"
#include "filter.h"

using namespace std;

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
    image gray_img = filter_to_grayscale(img);
    image scaled_image = filter_scale_up(gray_img, 3);
    image sobel_image = filter_sobel(scaled_image);
    image edge_image = filter_edge_detect(scaled_image);
    image sharpen_image = filter_sharpen(scaled_image);
    image box_blur_image = filter_box_blur(scaled_image);
    image gaussian_blur_image = filter_gaussian_blur(scaled_image);
    string filename = "./result.jpg";
    save_image(gaussian_blur_image, filename);

    cout << "done" << endl;
}