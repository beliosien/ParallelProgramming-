#include "vertexBuffer.h"
#include "log.h"

#include <stdlib.h>
#include <time.h>
#include <GL/glew.h>


vertexBuffer::vertexBuffer(const void* data, unsigned int size)
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


vertexBuffer::~vertexBuffer()
{
    glDeleteBuffers(1, &m_rendererID);
    if(LOG_ERROR_OPENGL("glDeleteBuffers") < 0)
    {
        exit(1);
    }
}


void vertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
    if(LOG_ERROR_OPENGL("glBindBuffer") < 0)
    {
        exit(1);
    }
}

void vertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    if(LOG_ERROR_OPENGL("glBindBuffer") < 0)
    {
        exit(1);
    }
}