#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"

using namespace std;


int main()
{
    Display display = Display(800, 600, "Hello world");

    Vertex vertices[] = {   Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
                            Vertex(glm::vec3(0 , 0.5, 0),    glm::vec2(0.5, 1.0)), 
                            Vertex(glm::vec3(0.5 , -0.5, 0), glm::vec2(1.0, 0.0))
                        };
    
    Texture texture("../textures/route.png");
    shader shader("../shaders/basic.glsl");
    Mesh mesh = Mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
    Transform transform;

    float counter = 0.0f;
    

    while (!display.IsClosed())
    {
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

        transform.getPos().x = sinf(counter);
        transform.getRot().y = counter * 20;
        shader.Bind();
        texture.Bind(0);
        shader.Update(transform);
        mesh.Draw();
        
        display.Update();
        counter += 0.01f;
    }
    

    return 0;
}