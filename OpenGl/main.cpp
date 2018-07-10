#include<iostream>
#include<math.h>
#include<Gl/glew.h>
#include<GLFW/glfw3.h>
#define GlEW_STATIC


const GLuint WIDTH = 4000, HEIGHT = 4000;

void Grass1(float x,float y) {
	glColor3f(0.16, 0.41, 0.17);
	glBegin(GL_POLYGON);
	{
		glVertex2f(x,y-0.041666667);
		glVertex2f(x+0.0625,y);
		glVertex2f(x+0.0625,y+ 0.0833333333);
		glVertex2f(x,y+0.041666667);
	}
	glEnd();
	glColor3f(0.28, 0.54, 0.13);
	glBegin(GL_POLYGON);
	{
		glVertex2f(x, y - 0.041666667);
		glVertex2f(x - 0.0625, y);
		glVertex2f(x - 0.0625, y + 0.0833333333);
		glVertex2f(x, y + 0.041666667);
	}
	glEnd();
	glColor3f(0.41, 0.64, 0.22);
	glBegin(GL_POLYGON);
	{
		glVertex2f(x, y + 0.041666667);
		glVertex2f(x - 0.0625, y + 0.0833333333);
		glVertex2f(x , y + 0.1250000003);
		glVertex2f(x + 0.0625, y + 0.0833333333);
	}
	glEnd();
}




void proceessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void TopGrass() {
	glColor3f(0.0, 0.89803922, 0.0);
	glBegin(GL_POLYGON);
	{
		glVertex2f(0.0, 0.2499999999);
		glVertex2f(0.9375, -0.3333333);
		glVertex2f(0, -0.9166666663);
		glVertex2f(-0.9375, -0.3333333);
	}
	glEnd();
}


void TopBorder() {
	glColor3f(0.15686275, 0.41176471, 0.16078431);
	glBegin(GL_POLYGON);
	{
		glVertex2f(0.0, 0.1666666666);
		glVertex2f(0.8125, -0.3333333);
		glVertex2f(0.7455, -0.375);
		glVertex2f(0.0, 0.083333333333);
		glVertex2f(-0.7455, -0.375);
		glVertex2f(-0.8125, -0.3333333);
	}
	glEnd();
}

void bombField() {
	glColor3f(0.0, 0.17647059, 0.0);
	glBegin(GL_POLYGON);
	{
		glVertex2f(0.0, 0.1666666666);
		glVertex2f(0.8125, -0.3333333);
		glVertex2f(0, -0.833333333);
		glVertex2f(-0.8125, -0.3333333);
	}
	glEnd();
}

void BTMBorder() {
	glColor3f(0.15686275, 0.41176471, 0.16078431);
	glBegin(GL_POLYGON);
	{
		glVertex2f(0, -0.9166666663);
		glVertex2f(0.9375, -0.3333333);
		glVertex2f(0.9375, -0.416666666667);
		glVertex2f(0, -1);
		glVertex2f(-0.9375, -0.416666666667);
		glVertex2f(-0.9375, -0.3333333);
	}
	glEnd();
}





int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_ANY_PROFILE);
	GLFWwindow*window = glfwCreateWindow(WIDTH, HEIGHT, "FUll screen", nullptr, nullptr);
	glfwWindowHint(GLFW_MAXIMIZED, true);
	glfwMakeContextCurrent(window);


	while (!glfwWindowShouldClose(window)) {

		proceessInput(window);
		glPointSize(10);
		glColor3f(1, 0, 0);
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		float delta = glfwGetTime();

		
		
		TopGrass();
		bombField();
		TopBorder();
		BTMBorder();
		Grass1( 0,		    -0.125);
		Grass1( 0.1875,-0.25);
		Grass1(-0.1875,-0.25);
		Grass1(0.375,-0.375);
		Grass1(-0.375, -0.375);
		Grass1(0, -0.375);
		Grass1(0.1875, -0.5);
		Grass1(-0.1875, -0.5);
		Grass1(0, -0.625);
		glfwSwapBuffers(window);
		glfwPollEvents();




	}
	glfwTerminate();
	return EXIT_SUCCESS;

}