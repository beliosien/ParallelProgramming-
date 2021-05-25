#ifndef INCLUDE_LOG_H_
#define INCLUDE_LOG_H_

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>

#define LOG_ERROR(msg, args...) fprintf(stderr, "%s:%d: " msg "\n", __FILE__, __LINE__, ##args)
#define LOG_ERROR_ERRNO(msg) LOG_ERROR("%s (%s)", msg, strerror(errno))
#define LOG_ERROR_NULL_PTR(...) LOG_ERROR("NULL pointer received")
#define LOG_ERROR_OPENGL(msg)                                 \
    ({                                                        \
        GLenum error;                                         \
        while ((error = glGetError()) != GL_NO_ERROR) {       \
            LOG_ERROR("%s (%s)", msg, gluErrorString(error)); \
        }                                                     \
        int ret = (error == GL_NO_ERROR) ? 0 : -1;            \
        ret;                                                  \
    })

#endif /* INCLUDE_LOG_H_ */