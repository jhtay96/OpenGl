#include<iostream>
#include<math.h>
#include<Gl/glew.h>
#include<GLFW/glfw3.h>
#define GlEW_STATIC

float xr =0,yr=0;

void display(GLFWwindow* window) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(200 + xr, 100 + yr);
	glVertex2f(300 + xr, 100 + yr);
	glVertex2f(300 + xr, 200 + yr);
	glVertex2f(200 + xr, 200 + yr);
	glEnd();
	glfwSwapBuffers(window);
}

void specialkey(int key, int x, int y) {
	switch(key) {
		case GLFW_KEY_R:
			yr++;
			
				break;
	}
}
int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_ANY_PROFILE);
	GLFWwindow*window = glfwCreateWindow(600, 600, "FUll screen", nullptr, nullptr);
	glfwWindowHint(GLFW_MAXIMIZED, true);
	glfwMakeContextCurrent(window);


	while (!glfwWindowShouldClose(window)) {

		glPointSize(10);
		glColor3f(1, 0, 0);
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		float delta = glfwGetTime();


		display(window);

		

		glfwSwapBuffers(window);
		glfwPollEvents();




	}
	glfwTerminate();
	return EXIT_SUCCESS;

}