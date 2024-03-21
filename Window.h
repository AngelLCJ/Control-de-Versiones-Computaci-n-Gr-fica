#pragma once
#include<stdio.h>
#include<glew.h>
#include<glfw3.h>

class Window
{
public:
	Window();
	Window(GLint windowWidth, GLint windowHeight);
	int Initialise();
	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }
	bool getShouldClose() {
		return  glfwWindowShouldClose(mainWindow);}
	bool* getsKeys() { return keys; }
	GLfloat getXChange();
	GLfloat getYChange();
	void swapBuffers() { return glfwSwapBuffers(mainWindow); }
	GLfloat getrotay() { return rotay; }
	GLfloat getrotax() { return rotax; }
	GLfloat getrotaz() { return rotaz; }
	GLfloat getPiernaD1() { return anguloPDI; }
	GLfloat getPiernaD2() { return anguloPDD; }
	GLfloat getPiernaT1() { return anguloPTI; }
	GLfloat getPiernaT2() { return anguloPTD; }

	GLfloat getllanta1() { return angulollanta1; }
	GLfloat getllanta2() { return angulollanta2; }
	GLfloat getllanta3() { return angulollanta3; }
	GLfloat getllanta4() { return angulollanta4; }

	GLfloat getcofre() { return angulocofre; }

	~Window();
private: 
	GLFWwindow *mainWindow;
	GLint width, height;
	GLfloat rotax, rotay, rotaz;
	GLfloat anguloPDI = 0.0f;
	GLfloat anguloPDD = 0.0f;
	GLfloat anguloPTI = 0.0f;
	GLfloat anguloPTD = 0.0f;

	GLfloat angulollanta1 = 0.0f;
	GLfloat angulollanta2 = 0.0f;
	GLfloat angulollanta3 = 0.0f;
	GLfloat angulollanta4 = 0.0f;
	GLfloat angulocofre = 0.0f;
	GLfloat anguloc = 0.0f;

	bool keys[1024];
	GLint bufferWidth, bufferHeight;
	GLfloat lastX;
	GLfloat lastY;
	GLfloat xChange;
	GLfloat yChange;
	bool mouseFirstMoved;
	void createCallbacks();
	static void ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode);
	static void ManejaMouse(GLFWwindow* window, double xPos, double yPos);
};

