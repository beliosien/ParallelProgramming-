#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <string>

class Texture
{
private:
    GLuint m_texture; 

public:
    Texture(const std::string& filename);
    ~Texture();

    void Bind(unsigned int unit);
};





#endif // TEXTURE_H