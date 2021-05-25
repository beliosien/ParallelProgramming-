#include <iostream>
#include <string>
#include "viewer.h"
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
    glutInit(&argc, argv);

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
    
    
    
    cout << "done" << endl;
    return 0;


}