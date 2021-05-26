#include "viewer.h"

viewer *viewer::_viewer = 0;

viewer::viewer()
{
    curr_pos = 0;
}

viewer::~viewer()
{
    if (!_images.empty())
    {
        _images.clear();
    }
}

/**
 * add image 
 * 
 * @param img the image we want to add
*/
void viewer::addImage(image& img)
{
    _images.push_back(img);
}


int viewer::display_init()
{
    _width = WIDTH;
    _height = HEIGHT;
    _window_id = 0;
    _texture = 0;
    _enabled = true;

    return 0;

}

int viewer::pre_display()
{
    glViewport(0, 0, _viewer->getWidth(), _viewer->getHeight());
    if (LOG_ERROR_OPENGL("glViewport") < 0) {
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    if (LOG_ERROR_OPENGL("glClearColor") < 0) {
        return -1;
    }


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (LOG_ERROR_OPENGL("glClear") < 0) {
        return -1;
    }

    return 0;
}


void viewer::callback_display() 
{
    if (pre_display() < 0) {
        LOG_ERROR("pre-display failed");
    }

    if (display() < 0) {
        LOG_ERROR("display failed");
    }

    post_display();
}

void viewer::callback_idle()
{
    viewer* v = v->getInstance();
    glutSetWindow(v->getWindowId());
    glutPostRedisplay();
}

void viewer::callback_keyboard(unsigned char key, int x, int y)
{
    // TODO change: zoom in, zoom out, avancer, rentrer
    switch (key) {
    case 'q':
        printf("Closing application\n");
        glutLeaveMainLoop();
        break;

    case '1':
        printf("Selected serial implementation\n");
        break;

    case '2':
        printf("Selected openmp implementation\n");
        break;

    case '3':
        printf("Selected opencl implementation\n");
        break;

    case ' ':
        printf("Rendering %s\n", _viewer->_enabled ? "disabled" : "enabled");
        _viewer->_enabled = !_viewer->_enabled;
        break;

    default:
        break;
    }
}

void viewer::callback_reshape(int width, int height) 
{
    viewer* v = v->getInstance();
    glutSetWindow(v->getWindowId());
    glutReshapeWindow(width, height);

    v->setWidth(width);
    v->setHeight(height);
}

int viewer::display_open()
{
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    int x_pos = (glutGet(GLUT_SCREEN_WIDTH) - _width) / 2;
    int y_pos = (glutGet(GLUT_SCREEN_HEIGHT) - _height) / 2;

    glutInitWindowPosition(x_pos, y_pos);

    glutInitWindowSize(_width, _height);
    _window_id = glutCreateWindow("Viewer");
    
    glutDisplayFunc(callback_display);
    glutIdleFunc(callback_idle);
    glutKeyboardFunc(callback_keyboard);

    glutReshapeFunc(callback_reshape);
    glewInit();
    glXSwapIntervalMESA(0);

    glutMainLoop();
    return 0;
}

void viewer::post_display() 
{
    glutSwapBuffers();
}


int viewer::display()
{
    viewer* v = v->getInstance();
    unsigned int VBO, VAO, EBO;
    shader myShader("../res/shaders/basic.glsl");
    image img = v->_images[v->curr_pos];
    
    if (v == NULL)
    {
        LOG_ERROR("viewer has not been initialized");
        goto fail_exit;
    }

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    
    myShader.Bind();

    if (display == NULL)
    {
        LOG_ERROR("display has not been initialized");
        goto fail_exit;
    }

    glGenTextures(1, &v->_texture);
    glBindTexture(GL_TEXTURE_2D, v->_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) 
    {
        goto fail_exit;
    }
    	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) 
    {
        goto fail_exit;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) 
    {
        goto fail_exit;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (LOG_ERROR_OPENGL("glTexParameteri") < 0) 
    {
        goto fail_exit;
    }

    if (img.getPixels() != NULL)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, img.getWidth(), img.getHeight(), 0, 
                    GL_RED, GL_UNSIGNED_BYTE, img.getPixels());
        
        if (LOG_ERROR_OPENGL("glTexImage2D") < 0)
        {
           goto fail_exit;
        }

        glGenerateMipmap(GL_TEXTURE_2D);
        if (LOG_ERROR_OPENGL("glGenerateMipmap") < 0) 
        {
           goto fail_exit;
        }
        
    }
    else
    {
        LOG_ERROR("Failed to load pixels");
    }

    if (v->_enabled) 
    {
        glBindTexture(GL_TEXTURE_2D, v->_texture);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);
    }

    return 0;

fail_exit:
    return -1;
}

unsigned int viewer::getWidth()
{
    return _width;
}
unsigned int viewer::getHeight()
{
    return _height;
}

unsigned int viewer::getWindowId()
{
    return _window_id;
}

void viewer::setWidth(int width)
{
    _width = width;
}

void viewer::setHeight(int height)
{
    _height = height;
}