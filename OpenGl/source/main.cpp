#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "shader.h"

using namespace std;


int main()
{
    Display display = Display(800, 600, "Hello world");
    shader  shader("../shaders/basic.glsl");

    while (!display.IsClosed())
    {
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
        shader.Bind();

        display.Update();
    }
    

    return 0;
}