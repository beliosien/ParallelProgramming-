#shader vertex
#version 330

layout(location = 0 ) in vec3 position;
void main()
{
	gl_Position = vec4(position.x, position.y, position.z, 1.0);
}


#shader fragment
#version 330

layout(location = 0 ) out vec3 color;

void main()
{
	color = vec3(1.0, 0.0, 0.0);
}