#pragma once

#include <vector>
#include <GL/glew.h>

struct vertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;


    static unsigned int GetSizeofType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT: return 4;
            
            case GL_UNSIGNED_INT: return 4;

            case GL_UNSIGNED_BYTE: return 1;

        }

        return 0;
    }
};


class vertexBufferLayout
{
private:
    std::vector<vertexBufferElement> m_Elements;
    unsigned int m_stride;

public:
    vertexBufferLayout()
    : m_stride(0) {};

    template<typename T>
    void Push( unsigned int count )
    {
        //static_assert(false);
    }

    inline const std::vector<vertexBufferElement>& GetElements() const { return m_Elements; };
    inline unsigned int GetStride() const { return m_stride; }; 
};

template<> inline void vertexBufferLayout::Push<float>( unsigned int count )
{
    m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
    m_stride += vertexBufferElement::GetSizeofType(GL_FLOAT) * count;
}

template<> inline void vertexBufferLayout::Push<unsigned int>( unsigned int count )
{
    m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
    m_stride += vertexBufferElement::GetSizeofType(GL_UNSIGNED_INT) * count;
}

template<> inline void vertexBufferLayout::Push<unsigned char>( unsigned int count )
{
    m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
    m_stride += vertexBufferElement::GetSizeofType(GL_UNSIGNED_BYTE) * count;
}
