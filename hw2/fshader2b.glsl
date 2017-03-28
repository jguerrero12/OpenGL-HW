#version 330 core

in  vec4 v_Color;		// varying variable for passing color from vertex shader
out vec4 fragColor;

void main() 
{
    fragColor = v_Color;
}
