#include <iostream>
#include <GL/glew.h>
#include "Display.h"

using namespace std;


int main()
{
    Display display = Display(800, 600, "Hello world");

    while (!display.IsClosed())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        display.Update();
    }
    

    return 0;
}