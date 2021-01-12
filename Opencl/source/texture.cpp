#include "texture.h"

Texture::Texture(image_t* image)
{
    texture_id = 0;
    pixels     = image->pixels;
    width      = image->width;
    height     = image->height;

    buffer = (unsigned char*) malloc(width * height * 3);

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            int index = (i * 3) + (j * 3) * width;
            pixel_t* pixel = image_get_pixel(image, i, j);
            buffer[index + 0] = pixel->bytes[0];
            buffer[index + 1] = pixel->bytes[1];
            buffer[index + 2] = pixel->bytes[2];
            buffer[index + 3] = pixel->bytes[3];
        }
    }

    glGenTextures(1, &texture_id);
    if (LOG_ERROR_OPENGL("glGenTextures") < 0) {
        exit(1);
    }

    glBindTexture(GL_TEXTURE_2D, texture_id);
    if (LOG_ERROR_OPENGL("glBindTexture") < 0) {
       exit(1);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
        exit(1);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
       exit(1);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
       exit(1);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
        exit(1);
    }
    

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 buffer);
    if (LOG_ERROR_OPENGL("glTexImage2D") < 0) {
        exit(1);
    }

    glBindTexture(GL_TEXTURE_2D, 0);
    if (LOG_ERROR_OPENGL("glBindTexture") < 0) {
       exit(1);
    }

}

Texture::~Texture() {
    delete pixels;
    Unbind();
    glDeleteTextures(1, &texture_id);
}

int Texture::Bind(unsigned int slot) const {
   
    
    glActiveTexture(GL_TEXTURE0 + slot);
    if (LOG_ERROR_OPENGL("GLTexture0") < 0) {
        goto fail_exit;
    }

    glBindTexture(GL_TEXTURE_2D, texture_id);
    if (LOG_ERROR_OPENGL("glBindTexture") < 0) {
        goto fail_exit;
    }

    return 0;

fail_exit:
    return -1;
}

void Texture:: Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
    if (LOG_ERROR_OPENGL("glBindTexture") < 0) {
        goto fail_exit;
    }

fail_exit:
    return;
}
