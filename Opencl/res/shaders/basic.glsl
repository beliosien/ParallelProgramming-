#shader vertex
#version 410

layout(location = 0 ) in vec3 position;
void main()
{
	gl_Position = vec4(position.x, position.y, position.z, 1.0);
}


#shader fragment
#version 410

layout(location = 0 ) out vec4 color;

void main()
{
	color = vec4(0.0, 0.0, 0.0, 0.0);
}