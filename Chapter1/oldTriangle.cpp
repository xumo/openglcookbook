#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

//screen size
const int WIDTH  = 1280;
const int HEIGHT = 960;

//OpenGL initialization 
void OnInit() {
	//set clear color to red
	glClearColor(1,0,1,0);
	cout<<"Initialization successfull"<<endl;
}

//release all allocated resources
void OnShutdown() {
	cout<<"Shutdown successfull"<<endl;
}

//handle resize event
void OnResize(int nw, int nh) {

}

//display callback function
void OnRender() {
	//clear colour and depth buffers
	    
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}


int main(int argc, char** argv) {
	
	glewExperimental = GL_TRUE;

	GLFWwindow* window;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    
	GLenum err = glewInit();
	if (GLEW_OK != err)	{
		cerr<<"Error: "<<glewGetErrorString(err)<<endl;
	} else {
		if (GLEW_VERSION_3_3)
		{
			cout<<"Driver supports OpenGL 3.3\nDetails:"<<endl;
		}
	}

	//print information on screen
	cout<<"\tUsing GLEW "<<glewGetString(GLEW_VERSION)<<endl;
	cout<<"\tVendor: "<<glGetString (GL_VENDOR)<<endl;
	cout<<"\tRenderer: "<<glGetString (GL_RENDERER)<<endl;
	cout<<"\tVersion: "<<glGetString (GL_VERSION)<<endl;
	cout<<"\tGLSL: "<<glGetString (GL_SHADING_LANGUAGE_VERSION)<<endl;

	//initialization of OpenGL
	//OnInit();


	while (!glfwWindowShouldClose(window))
	    {
	        float ratio;
	        int width, height;
	        glfwGetFramebufferSize(window, &width, &height);
	        ratio = width / (float) height;
	        glViewport(0, 0, width, height);
	        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		    glMatrixMode(GL_PROJECTION);
	        glLoadIdentity();
	        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	        glMatrixMode(GL_MODELVIEW);
	        glLoadIdentity();
	        OnRender();
	        glfwSwapBuffers(window);
	        glfwPollEvents();
	    }
	    glfwDestroyWindow(window);
	    glfwTerminate();
	    exit(EXIT_SUCCESS);	
   

	return 0;
}