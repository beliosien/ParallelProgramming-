#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
private:
    glm::vec3 pos;
public:
    Vertex(const glm::vec3& pos)
    {
        this->pos = pos;
    }

    ~Vertex() {}
};


class Mesh
{
private:

    enum
    {
        POSITION_VB,

        NUM_BUFFERS
    };

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
    
public:
    Mesh(Vertex* vertices, unsigned int numVertices);
    ~Mesh();

    void Draw();
};

#endif // MESH_H

