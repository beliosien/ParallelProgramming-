#include "Texture.h"
#include "stb_image.h"
#include <cassert>
#include <iostream>


Texture::Texture(const std::string& filename)
{
    int width, height,channels; 
    stbi_set_flip_vertically_on_load(1);
    unsigned char* pixel = stbi_load(filename.c_str(), &width, &height, &channels, 4);

    if (pixel == NULL)
    {
        std::cerr << "texture not found for path: " << filename << std::endl;
    }
    
    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixel);
    
    stbi_image_free(pixel);
}

Texture::~Texture()
{
    glDeleteTextures(1,&m_texture);
}

void Texture::Bind(unsigned int unit)
{
    assert(unit >= 0 && unit <= 31);

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_texture);
}