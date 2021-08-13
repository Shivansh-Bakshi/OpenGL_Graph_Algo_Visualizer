#include <iostream>

#include "../../external/include/GL/glew.h"

#include "../../external/include/GL/glfw3.h"
GLFWwindow* window;

#include "../../external/include/GL/glm/glm.hpp"
using namespace glm;

int main( void )
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		std::cerr << "Failed to initialize GLFW\n";
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
	
	if( window == NULL ){
		std::cerr << "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* renderer = glGetString(GL_RENDER);

	std::cout << vendor << std::endl;
	std::cout << renderer << std::endl;

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW\n";
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	do{
		// Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
		glClear( GL_COLOR_BUFFER_BIT );

		// Draw nothing, see you in tutorial 2 !

		
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}