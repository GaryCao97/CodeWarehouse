#include <glad/glad.h>
#include <GLFW/glfw3.h> 
#include <iostream>

int main() { 
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(800, 600, "HelloWindow", NULL, NULL); 
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { 
		std::cout << "Failed to initialize GLAD" << std::endl; 
		return -1; 
	}
	while (!glfwWindowShouldClose(window)) { 
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); 
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES); 
		glColor3f(1.0, 0.0, 0.0); 
		glVertex3f(0.0, 1.0, 0.0); 
		glColor3f(0.0, 1.0, 0.0); 
		glVertex3f(-1.0, -1.0, 0.0); 
		glColor3f(0.0, 0.0, 1.0); 
		glVertex3f(1.0, -1.0, 0.0); 
		glEnd();
		glfwSwapBuffers(window); 
		glfwPollEvents(); 
	}
	glfwTerminate(); 
	return 0; 
}