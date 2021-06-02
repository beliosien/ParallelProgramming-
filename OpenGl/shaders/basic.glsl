#shader vertex
#version 330 core

attribute vec3 aPos;
attribute vec2 aText;

varying vec2 texcoord0;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    texcoord0 = aText;
}


#shader fragment
#version 330 core

varying vec2 texcoord0;
uniform sampler2D diffuse;

void main()
{
    gl_FragColor = texture2D(diffuse, texcoord0);
}