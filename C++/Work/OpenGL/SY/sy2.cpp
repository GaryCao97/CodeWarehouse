#include <glad/glad.h>
#include <GLFW/glfw3.h> 
#include <iostream>
//��Ļ��� 
void render1(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  
	glClear(GL_COLOR_BUFFER_BIT);  
	glColor3f(1.0, 0.0, 0.0); 
	glPointSize(30); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	glEnable(GL_BLEND); 
	glEnable(GL_POINT_SMOOTH); 
	glBegin(GL_POINTS);    
	glVertex3f(0.5, 0.5, 0.0);  
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);       
	glVertex3f(0.5, -0.5, 0.0);
	glEnd(); 
	glFlush();
}

//�ߵĻ��� 
void render2(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(10);
	glLineStipple(1, 0xFF00);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glEnd();
	glFlush();
}

//���ߵĻ��� 
void render3(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(10);
	glLineStipple(1, 0xFF00);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glEnd();
	glFlush();
}

//ѭ�����ߵĻ��� 
void render4(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(10);
	glLineStipple(1, 0xFF00);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glEnd();
	glFlush();
}

//�����εĻ��� 
void render5(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(-0.9, -0.5, 0.0);
	glVertex3f(-0.1, -0.5, 0.0);
	glVertex3f(0.4, 0.5, 0.0);
	glVertex3f(-0.4, 0.5, 0.0);
	glVertex3f(0.0, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.1, -0.5, 0.0); 
	glVertex3f(0.9, -0.5, 0.0); 
	glEnd();
	glFlush();
}

//���Ǵ������� 
void render6(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(5);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.9, -0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(-0.1, -0.5, 0.0);
	glVertex3f(0.4, 0.5, 0.0);
	glVertex3f(0.9, -0.5, 0.0);
	glEnd();
	glFlush();
}

//�����ȵ����� 
void render7(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(5);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 0.9, 0.0);
	glVertex3f(-0.9, -0.5, 0.0);
	glVertex3f(-0.5, -0.9, 0.0);
	glVertex3f(0, -0.5, 0.0);
	glVertex3f(0.5, -0.9, 0.0);
	glVertex3f(0.9, -0.5, 0.0);
	glEnd();
	glFlush();
}

//�ı��ε����� 
void render8(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10);
	glEnable(GL_POINT_SMOOTH);
	glLineWidth(5);
	glPolygonMode(GL_FRONT, GL_FILL);
	glBegin(GL_QUADS);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glEnd();
	glFlush();
}

//�ı��δ������� 
void render9(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10);
	glEnable(GL_POINT_SMOOTH);
	glLineWidth(5);
	glPolygonMode(GL_FRONT, GL_FILL);
	glBegin(GL_QUAD_STRIP);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glEnd();
	glFlush();
}

//����ε����� 
void render10(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10);
	glEnable(GL_POINT_SMOOTH);
	glLineWidth(5);
	glPolygonMode(GL_FRONT, GL_FILL);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0.9, 0.0);
	glVertex3f(-0.9, 0.2, 0.0);
	glVertex3f(-0.7, -0.8, 0.0);
	glVertex3f(0.7, -0.8, 0.0);
	glVertex3f(0.9, 0.2, 0.0);
	glEnd();
	glFlush();
}



int main() {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(800, 600, "sy2", NULL, NULL);
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	while (!glfwWindowShouldClose(window)) {

		render10();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}