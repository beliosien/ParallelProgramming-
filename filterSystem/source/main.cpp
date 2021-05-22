#include <iostream>
#include <string>
#include "image.h"
#include "filter.h"

using namespace std;

void show_help()
{

}

int main(int argc, char *argv[]) 
{
    cout << "welcome to filter system" << endl;

    std::string file_path;

    // Read program argument
    for (int i=1; i<argc; i++) {
        std::string arg(argv[i]);
        if (arg == "-file") 
        {
            file_path = argv[i+1]; i++;
        } else if (arg == "-h")
        {
            show_help();
            i++;
        }
    }

    if (file_path.empty())
    {
        cout << "File missing. Please enter your file." << endl;
        show_help(); 
    }


}