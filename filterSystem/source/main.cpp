#include <iostream>
#include <string>
#include "utilitary.h"
#include "image.h"
#include "filter.h"

using namespace std;

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]) 
{
    glutInit(&argc, argv);
    std::string file_path;

    // Read program arguments
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
        
    run_viewer();
    
    cout << "done" << endl;
    return 0;


}