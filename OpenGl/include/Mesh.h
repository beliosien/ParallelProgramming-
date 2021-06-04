#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
public:
    Vertex(const glm::vec3& pos, const glm::vec2& texCoord)
    {
        this->pos = pos;
        this->texCoord = texCoord;
    }

    glm::vec3 getPos() { return pos; }
    glm::vec2 getTexCoord() { return texCoord;}

    ~Vertex() {}
};


class Mesh
{
private:

    enum
    {
        POSITION_VB,
        TEXCOORD_VB,
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

