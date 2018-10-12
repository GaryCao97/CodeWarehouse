#include <glad/glad.h>
#include <GLFW/glfw3.h> 
#include <iostream>
void drawShape(GLenum mode,int pointNum,GLfloat point[][3]);
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
		GLfloat point1[][3] = {{-0.8f,1.0f,0.0},{-0.6f,0.5f,0.0},{-1.0f,0.5f,0.0}};
		GLfloat point2[][3] = {{0.0f,0.0f,0.0}};
		GLfloat point3[][3] = {{-0.4f,1.0f,0.0},{-0.4f,-0.8f,0.0}};
		GLfloat point4[][3] = {{-0.1f,1.0f,0.0},{-0.05f,0.9f,0.0},{-0.0f,0.95f,0.0}};
		GLfloat point5[][3] = {{-0.15f,0.8f,0.0},{-0.1f,0.85f,0.0},{0.0f,0.75f,0.0}};
		GLfloat point6[][3] = {{-0.8f,-1.0f,0.0},{-0.6f,-0.5f,0.0},{-1.0f,-0.5f,0.0},{-0.8f,-0.3f,0.0}};
		GLfloat point7[][3] = {{-1.0f,0.2f,0.0},{-0.8f,0.0f,0.0},{-0.6f,0.1f,0.0},{-0.56f,0.3f,0.0}};
		GLfloat point8[][3] = {{1.0f,-0.2f,0.0},{0.8f,-0.0f,0.0},{0.6f,-0.1f,0.0},{0.56f,-0.3f,0.0}};
		GLfloat point9[][3] = {{0.8f,1.0f,0.0},{0.6f,0.5f,0.0},{1.0f,0.5f,0.0},{0.8f,0.3f,0.0}};
		GLfloat point10[][3] = {{0.8f,-1.0f,0.0},{0.6f,-0.5f,0.0},{0.8f,-0.3f,0.0},{1.0f,-0.5f,0.0}};
		drawShape(GL_TRIANGLES,3,point1);
		drawShape(GL_POINTS,1,point2);
		drawShape(GL_LINES,2,point3);
		drawShape(GL_LINE_STRIP,3,point4);
		drawShape(GL_LINE_LOOP,3,point5);
		drawShape(GL_TRIANGLE_STRIP,4,point6);
		drawShape(GL_TRIANGLE_FAN,4,point7);
		drawShape(GL_QUADS,4,point8);
		drawShape(GL_QUAD_STRIP,4,point9);
		drawShape(GL_POLYGON,4,point10);
		glfwSwapBuffers(window); 
		glfwPollEvents(); 
	}
	glfwTerminate(); 
	return 0; 
}
void drawShape(GLenum mode,int pointNum,GLfloat point[][3]){
	switch(mode){
	case GL_POINTS: glPointSize(100.0f);glColor3f(1.0, 1.0, 0.0);break;
	case GL_LINES: glLineWidth(3.0f);glColor3f(1.0, 0.0, 1.0);break;
	case GL_LINE_STRIP: glLineWidth(5.0f);glColor3f(0.0, 0.0, 1.0); break;
	case GL_LINE_LOOP: glLineWidth(5.0f);glColor3f(1.0, 0.0, 0.0); break;
	case GL_TRIANGLES: glLineWidth(2.0f);glColor3f(1.0, 1.0, 1.0); break;
	case GL_TRIANGLE_STRIP: glLineWidth(2.0f);glColor3f(1.0, 0.50, 1.0); break;
	case GL_TRIANGLE_FAN: glLineWidth(2.0f);glColor3f(0.5, 0.50, 0.5); break;
	case GL_QUADS: glLineWidth(2.0f);glColor3f(0.4, 0.8, 0.3); break;
	case GL_QUAD_STRIP: glLineWidth(2.0f);glColor3f(0.5, 0.50, 1.0); break;
	case GL_POLYGON: glLineWidth(2.0f);glColor3f(0, 1.0, 0); break;
	}
	glBegin(mode); 
		for(int i = 0;i < pointNum;i++){
			glVertex3f(point[i][0], point[i][1], point[i][2]);
		}
	glEnd();
}