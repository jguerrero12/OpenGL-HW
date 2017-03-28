#version 330 core

in	vec2	a_Position;	// attribute variable: position vector
in	vec3	a_Color;	// attribute variable: color vector

out	vec4	v_Color;	// varying variable for passing color to fragment shader

uniform	mat4	u_Modelview;	// uniform variable for passing modelview  matrix
uniform	mat4	u_Projection;	// uniform variable for passing projection matrix
uniform	float	u_Theta;	// Theta parameter
uniform	int	    u_Twist;	// Twist flag

vec2 rotTwist(vec2 p)
{
    float d = u_Twist == 1 ? sqrt(p[0]*p[0] + p[1]*p[1]) : 1;
    float sinTheta = sin(d*u_Theta);
    float cosTheta = cos(d*u_Theta);
    return vec2(p[0]*cosTheta - p[1]*sinTheta, p[0]*sinTheta + p[1]*cosTheta);
}

void main() 
{
    v_Color = vec4(a_Color, 1);
    gl_Position =   u_Projection * vec4(rotTwist(a_Position), 0, 1);
    
}
