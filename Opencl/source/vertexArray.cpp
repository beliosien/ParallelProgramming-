
#include "vertexArray.h"
#include <GL/glew.h>
#include "log.h"


vertexArray::vertexArray()
{
    glGenVertexArrays(1, &m_rendererID);
}


vertexArray::~vertexArray()
{   
    glDeleteVertexArrays(1, &m_rendererID);
}



void vertexArray::AddBuffer(const vertexBuffer& vb, const vertexBufferLayout& layout)
{
    vb.Bind();
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;

    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*) offset);

        offset += element.count * vertexBufferElement::GetSizeofType(element.type);

    }
}


void vertexArray::Bind() const
{
    glBindVertexArray(m_rendererID);
}


void vertexArray::Unbind() const
{
    glBindVertexArray(0);
}

