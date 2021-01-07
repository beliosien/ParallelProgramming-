#include "vertexBuffer.h"
#include "log.h"

#include <stdlib.h>
#include <time.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glxew.h>

#include <GL/freeglut_ext.h>


VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &m_rendererID);
    if(LOG_ERROR_OPENGL("glGenBuffer") < 0)
    {
        exit(1);
    }

    glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
    if(LOG_ERROR_OPENGL("glBindBuffer") < 0)
    {
        exit(1);
    }

    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    if(LOG_ERROR_OPENGL("glBufferData") < 0)
    {
        exit(1);
    }
}


VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_rendererID);
    if(LOG_ERROR_OPENGL("glDeleteBuffers") < 0)
    {
        exit(1);
    }
}


void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
    if(LOG_ERROR_OPENGL("glBindBuffer") < 0)
    {
        exit(1);
    }
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    if(LOG_ERROR_OPENGL("glBindBuffer") < 0)
    {
        exit(1);
    }
}