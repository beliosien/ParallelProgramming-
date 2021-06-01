#shader vertex
#version 330 core

attribute vec3 aPos;

void main()
{
    gl_Position = vec4(aPos, 1.0);
}


#shader fragment
#version 330 core


void main()
{
    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}