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
    glutInitContextVersion(3,3);
    glutInitContextProfile(GLUT_CORE_PROFILE);
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
        LOG_ERROR("Error: File missing. Please enter your file.");
        cout << endl;
        show_help(); 
    }

    cout << "welcome to filter system" << endl;
    
    image img = image(file_path);
    image gray_img = filter_to_grayscale(img);

    viewer* v = v->getInstance();
    v->addImage(gray_img);
    run_viewer();
    
    cout << "done" << endl;
    return 0;


}