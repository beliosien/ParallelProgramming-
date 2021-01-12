#shader vertex
#version 330

layout(location = 0 ) in vec4 position;
layout(location = 1)  in vec2 texCoord;

out vec2 v_TexCoord;
void main()
{
	gl_Position = vec4(position.x, position.y, position.z, 1.0);
	v_TexCoord = texCoord;
}


#shader fragment
#version 330

layout(location = 0 ) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_color;
uniform sample2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord) * u_color;
	color = texColor;
}