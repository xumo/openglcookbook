#version 330 core
  
layout(location=0) in vec3 vVertex;		//object space vertex position

//uniforms
uniform mat4 MVP;		//combined modelview projection matrix
uniform float time;		//elapsed time 

smooth out vec4 vSmoothColor;		//smooth colour to fragment shader


//shader constants
const float amplitude = 0.125;
const float frequency = 4;
const float PI = 3.14159;

void main()
{ 
	//get the Euclidean distance of the current vertex from the center of the mesh
	vec3 origen = vec3(1.5,1.5,2);
	float distance = length(vVertex - origen);  
	//create a sin function using the distance, multiply frequency and add the elapsed time
	float y = amplitude*sin(-PI*distance*frequency+time);		
	//multiply the MVP matrix with the new position to get the clipspace position
	vSmoothColor = vec4(1,1-sin(-PI*distance*frequency+time),sin(-PI*distance*frequency+time),1);
	gl_Position = MVP*vec4(vVertex.x, y, vVertex.z,1);
}