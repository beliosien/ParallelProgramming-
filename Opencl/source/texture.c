#include "texture.h"
#include "log.h"

texture_t* init_texture(image_t* image)
{
    texture_t* texture = malloc(sizeof(texture_t));

    if(image == NULL)
    {
        LOG_ERROR("image has not been initialised");
        goto fail_exit;
    }

    texture->texture_id = 0;
    texture->pixels = image->pixels;
    texture->width = image->width;
    texture->height = image->height;

    return texture;

fail_exit:
    return NULL;
}


void destroy_texture(texture_t* texture)
{
    if (texture != NULL)
    {
        free(texture->pixels);
        free(texture);
        glDeleteTextures(1, &texture->texture_id);
    }
}

int Bind(unsigned int slot, texture_t* texture)
{
    if (texture->texture_id == 0){
        glGenTextures(1, &texture->texture_id);
        if (LOG_ERROR_OPENGL("glGenTextures") < 0) {
            goto fail_exit;
        }
    }

    glBindTexture(GL_TEXTURE_2D, texture->texture_id);
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

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
        goto fail_exit;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) {
        goto fail_exit;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA,
                     GL_UNSIGNED_BYTE, texture->pixels);
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


int UnBind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
    if (LOG_ERROR_OPENGL("glBindTexture") < 0) {
        goto fail_exit;
    }

    return 0;

fail_exit:
    return -1;
}


