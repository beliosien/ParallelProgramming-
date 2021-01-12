#include "texture.h"
#include "log.h"

Texture::Texture(image_t* image)
{
    texture_id = 0;
    pixels     = image->pixels;
    width      = image->width;
    height     = image->height;
}

Texture::~Texture() {
    delete pixels;
    Unbind();
    glDeleteTextures(1, &texture_id);
}

int Texture::Bind(unsigned int slot) const {
    if (texture_id == 0) {
        glGenTextures(1, (GLuint* )&texture_id);
        if (LOG_ERROR_OPENGL("glGenTextures") < 0) {
            goto fail_exit;
        }
    }


    glBindTexture(GL_TEXTURE_2D, texture_id);
    if (LOG_ERROR_OPENGL("glBindTexture") < 0) {
        goto fail_exit;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
        goto fail_exit;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
        goto fail_exit;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
        goto fail_exit;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
        goto fail_exit;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 pixels);
    if (LOG_ERROR_OPENGL("glTexImage2D") < 0) {
        goto fail_exit;
    }

    glActiveTexture(GL_TEXTURE0 + slot);
    if (LOG_ERROR_OPENGL("GLTexture0") < 0) {
        goto fail_exit;
    }

    glBindTexture(GL_TEXTURE_2D, 0);
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
