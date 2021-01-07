#include "indexBuffer.h"
#include "log.h"
#include <stdlib.h>
#include <time.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glxew.h>

#include <GL/freeglut_ext.h>


IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
: m_count(count)
{
    glGenBuffers(1, &m_rendererID);
    if(LOG_ERROR_OPENGL("glGenBuffer") < 0)
    {
        exit(1);
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
    if(LOG_ERROR_OPENGL("glBindBuffer") < 0)
    {
        exit(1);
    }

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
    if(LOG_ERROR_OPENGL("glBufferData") < 0)
    {
        exit(1);
    }
}


IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_rendererID);
    if(LOG_ERROR_OPENGL("glDeleteBuffers") < 0)
    {
        exit(1);
    }
}


void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
    if(LOG_ERROR_OPENGL("glBindBuffer") < 0)
    {
        exit(1);
    }
}

void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    if(LOG_ERROR_OPENGL("glBindBuffer") < 0)
    {
        exit(1);
    }
}