#include "viewer_utilitary.h"

int viewer_open()
{
    viewer* v = v->getInstance();
    if (v == NULL)
    {
        LOG_ERROR("viewer has not been initialized");
        return -1;
    }


    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    int x_pos = (glutGet(GLUT_SCREEN_WIDTH) - v->getWidth()) / 2;
    int y_pos = (glutGet(GLUT_SCREEN_HEIGHT) - v->getHeight()) / 2;

    glutInitWindowPosition(x_pos, y_pos);

    glutInitWindowSize(v->getWidth(), v->getHeight());
    v->setWindowId(glutCreateWindow("Viewer"));
    
    glutDisplayFunc(callback_display);
    glutIdleFunc(callback_idle);
    glutKeyboardFunc(callback_keyboard);

    glutReshapeFunc(callback_reshape);
    glewInit();
    glXSwapIntervalMESA(0);

    glutMainLoop();
    return 0;
}

int pre_display()
{
    viewer* v = v->getInstance();

    if (v == NULL)
    {
        LOG_ERROR("viewer has not been initialized");
        goto fail_exit;
    }

    glViewport(0, 0, v->getWidth(), v->getHeight());
    if (LOG_ERROR_OPENGL("glViewport") < 0) {
        goto fail_exit;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    if (LOG_ERROR_OPENGL("glClearColor") < 0) {
        goto fail_exit;
    }


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (LOG_ERROR_OPENGL("glClear") < 0) {
        goto fail_exit;
    }

    return 0;
fail_exit:
    return -1;
}

int display()
{
    viewer* v = v->getInstance();
    unsigned int VBO, VAO, EBO;
    shader myShader("../res/shaders/basic.glsl");
    image img = image();
    GLuint texture;
    if (v == NULL)
    {
        LOG_ERROR("viewer has not been initialized");
        goto fail_exit;
    }

    if (v->getCurrpos() < v->getImages().size())
    {
        img = v->getImages()[v->getCurrpos()];
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

    texture = v->getTexture();
    
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

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
        
    }else
    {
        LOG_ERROR("No image to display");
    }

    if (v->getIsEnabled()) 
    {
        glBindTexture(GL_TEXTURE_2D, texture);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);
    }

    return 0;

fail_exit:
    return -1;
}

void post_display() 
{
    glutSwapBuffers();
}

void callback_display() 
{
    if (pre_display() < 0) {
        LOG_ERROR("pre-display failed");
    }

    if (display() < 0) {
        LOG_ERROR("display failed");
    }

    post_display();
}

void callback_idle()
{
    viewer* v = v->getInstance();
    glutSetWindow(v->getWindowId());
    glutPostRedisplay();
}

void callback_keyboard(unsigned char key, int x, int y)
{
    viewer* v = v->getInstance();
    if (v == NULL)
    {
        LOG_ERROR("viewer has not been initialized");
        glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);
        glutLeaveMainLoop();

    }

    switch (key) {
    case 'q':
        printf("Closing the viewer\n");
        v->setisInit(!v->getisInit());
        glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);
        glutLeaveMainLoop();
        break;

    case 'r':
        std::cout << "Next image" << std::endl;
        v->setCurrPos(v->getCurrpos() + 1);
        break;

    case 'l':
        std::cout << "Previous image" << std::endl;
        v->setCurrPos(v->getCurrpos() - 1);
        break;

    case ' ':
        printf("Rendering %s\n", v->getIsEnabled() ? "disabled" : "enabled");
        v->setIsEnable(!v->getIsEnabled());
        break;

    default:
        break;
    }
}

void callback_reshape(int width, int height) 
{
    viewer* v = v->getInstance();
    if (v == NULL)
    {
        LOG_ERROR("viewer has not been initialized");
        return;
    }

    glutSetWindow(v->getWindowId());
    glutReshapeWindow(width, height);

    v->setWidth(width);
    v->setHeight(height);
}
