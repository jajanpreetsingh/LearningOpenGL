#version 330

layout(location = 0) in vec3 pos;

out vec4 vCol;

//uniform mat4 model;                          

void main()
{
	gl_Position = vec4(pos, 1.0);
	vCol = vec4(0.0, 0.5, 0.8, 1.0);
}