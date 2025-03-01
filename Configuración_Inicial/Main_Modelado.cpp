/*
Práctica 4:  Modelado Boxel art
Rodriguez Garcia Javier Antonio
319277485
Fecha de entrega: 28/02/2025
*/

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Shaders
#include "Shader.h"

void Inputs(GLFWwindow *window);


const GLint WIDTH = 800, HEIGHT = 600;
float movX=0.0f;
float movY=0.0f;
float movZ=-5.0f;
float rot = 0.0f;
int main() {
	glfwInit();
	//Verificación de compatibilidad 
	// Set all the required options for GLFW
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 4:  Modelado Boxel art , Rodriguez Javier, 319277485, 28 / 02 / 2025", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Verificación de errores de creacion  ventana
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}


	// Define las dimensiones del viewport
	glViewport(0, 0, screenWidth, screenHeight);


	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Build and compile our shader program
	Shader ourShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers



	// vectores cubo rosa
	float vertices[] = {
		-0.5f, -0.5f, 0.5f, 0.9725f, 0.4117f,0.5490f,//Front
		0.5f, -0.5f, 0.5f,  0.9725f, 0.4117f,0.5490f,
		0.5f,  0.5f, 0.5f, 0.9725f, 0.4117f,0.5490f,
		0.5f,  0.5f, 0.5f,  0.9725f, 0.4117f,0.5490f,
		-0.5f,  0.5f, 0.5f, 0.9725f, 0.4117f,0.5490f,
		-0.5f, -0.5f, 0.5f, 0.9725f, 0.4117f,0.5490f,

		-0.5f, -0.5f,-0.5f,0.9725f, 0.4117f,0.5490f,//Back
		 0.5f, -0.5f,-0.5f, 0.9725f, 0.4117f,0.5490f,
		 0.5f,  0.5f,-0.5f, 0.9725f, 0.4117f,0.5490f,
		 0.5f,  0.5f,-0.5f, 0.9725f, 0.4117f,0.5490f,
		-0.5f,  0.5f,-0.5f, 0.9725f, 0.4117f,0.5490f,
		-0.5f, -0.5f,-0.5f,0.9725f, 0.4117f,0.5490f,

		 0.5f, -0.5f,  0.5f,  0.9725f, 0.4117f,0.5490f,
		 0.5f, -0.5f, -0.5f,  0.9725f, 0.4117f,0.5490f,
		 0.5f,  0.5f, -0.5f,  0.9725f, 0.4117f,0.5490f,
		 0.5f,  0.5f, -0.5f,  0.9725f, 0.4117f,0.5490f,
		 0.5f,  0.5f,  0.5f,  0.9725f, 0.4117f,0.5490f,
		 0.5f,  -0.5f, 0.5f, 0.9725f, 0.4117f,0.5490f,

		-0.5f,  0.5f,  0.5f,  0.9725f, 0.4117f,0.5490f,
		-0.5f,  0.5f, -0.5f,  0.9725f, 0.4117f,0.5490f,
		-0.5f, -0.5f, -0.5f,  0.9725f, 0.4117f,0.5490f,
		-0.5f, -0.5f, -0.5f,  0.9725f, 0.4117f,0.5490f,
		-0.5f, -0.5f,  0.5f,  0.9725f, 0.4117f,0.5490f,
		-0.5f,  0.5f,  0.5f,  0.9725f, 0.4117f,0.5490f,

		-0.5f, -0.5f, -0.5f, 0.9725f, 0.4117f,0.5490f,
		0.5f, -0.5f, -0.5f,  0.9725f, 0.4117f,0.5490f,
		0.5f, -0.5f,  0.5f,  0.9725f, 0.4117f,0.5490f,
		0.5f, -0.5f,  0.5f,  0.9725f, 0.4117f,0.5490f,
		-0.5f, -0.5f,  0.5f, 0.9725f, 0.4117f,0.5490f,
		-0.5f, -0.5f, -0.5f, 0.9725f, 0.4117f,0.5490f,

		-0.5f,  0.5f, -0.5f, 0.9725f, 0.4117f,0.5490f,
		0.5f,  0.5f, -0.5f,  0.9725f, 0.4117f,0.5490f,
		0.5f,  0.5f,  0.5f,  0.9725f, 0.4117f,0.5490f,
		0.5f,  0.5f,  0.5f,  0.9725f, 0.4117f,0.5490f,
		-0.5f,  0.5f,  0.5f, 0.9725f, 0.4117f,0.5490f,
		-0.5f,  0.5f, -0.5f, 0.9725f, 0.4117f,0.5490f,
	};
	//vectores cubo blanco (ojos)
	float verticesB[] = {
		-0.5f, -0.5f, 0.5f, 0.9490f, 0.9098f,0.7764f,//Front
		0.5f, -0.5f, 0.5f,  0.9490f, 0.9098f,0.7764f,
		0.5f,  0.5f, 0.5f, 0.9490f, 0.9098f,0.7764f,
		0.5f,  0.5f, 0.5f,  0.9490f, 0.9098f,0.7764f,
		-0.5f,  0.5f, 0.5f, 0.9490f, 0.9098f,0.7764f,
		-0.5f, -0.5f, 0.5f, 0.9490f, 0.9098f,0.7764f,

		-0.5f, -0.5f,-0.5f,0.9490f, 0.9098f,0.7764f,//Back
		 0.5f, -0.5f,-0.5f,0.9490f, 0.9098f,0.7764f,
		 0.5f,  0.5f,-0.5f, 0.9490f, 0.9098f,0.7764f,
		 0.5f,  0.5f,-0.5f, 0.9490f, 0.9098f,0.7764f,
		-0.5f,  0.5f,-0.5f, 0.9490f, 0.9098f,0.7764f,
		-0.5f, -0.5f,-0.5f,0.9490f, 0.9098f,0.7764f,

		 0.5f, -0.5f,  0.5f,  0.9490f, 0.9098f,0.7764f,
		 0.5f, -0.5f, -0.5f, 0.9490f, 0.9098f,0.7764f,
		 0.5f,  0.5f, -0.5f,  0.9490f, 0.9098f,0.7764f,
		 0.5f,  0.5f, -0.5f,  0.9490f, 0.9098f,0.7764f,
		 0.5f,  0.5f,  0.5f,  0.9490f, 0.9098f,0.7764f,
		 0.5f,  -0.5f, 0.5f, 0.9490f, 0.9098f,0.7764f,

		-0.5f,  0.5f,  0.5f,  0.9490f, 0.9098f,0.7764f,
		-0.5f,  0.5f, -0.5f,  0.9490f, 0.9098f,0.7764f,
		-0.5f, -0.5f, -0.5f,  0.9490f, 0.9098f,0.7764f,
		-0.5f, -0.5f, -0.5f,  0.9490f, 0.9098f,0.7764f,
		-0.5f, -0.5f,  0.5f,  0.9490f, 0.9098f,0.7764f,
		-0.5f,  0.5f,  0.5f,0.9490f, 0.9098f,0.7764f,

		-0.5f, -0.5f, -0.5f, 0.9490f, 0.9098f,0.7764f,
		0.5f, -0.5f, -0.5f, 0.9490f, 0.9098f,0.7764f,
		0.5f, -0.5f,  0.5f,  0.9490f, 0.9098f,0.7764f,
		0.5f, -0.5f,  0.5f,  0.9490f, 0.9098f,0.7764f,
		-0.5f, -0.5f,  0.5f, 0.9490f, 0.9098f,0.7764f,
		-0.5f, -0.5f, -0.5f, 0.9490f, 0.9098f,0.7764f,

		-0.5f,  0.5f, -0.5f, 0.9490f, 0.9098f,0.7764f,
		0.5f,  0.5f, -0.5f,  0.9490f, 0.9098f,0.7764f,
		0.5f,  0.5f,  0.5f,  0.9490f, 0.9098f,0.7764f,
		0.5f,  0.5f,  0.5f,  0.9490f, 0.9098f,0.7764f,
		-0.5f,  0.5f,  0.5f, 0.9490f, 0.9098f,0.7764f,
		-0.5f,  0.5f, -0.5f, 0.9490f, 0.9098f,0.7764f,
	};

	float verticesvER[] = {
	-0.5f, -0.5f, 0.5f, 0.4941f, 0.8117f,0.5411f,//Front
	0.5f, -0.5f, 0.5f, 0.4941f, 0.8117f,0.5411f,
	0.5f,  0.5f, 0.5f, 0.4941f, 0.8117f,0.5411f,
	0.5f,  0.5f, 0.5f,  0.4941f, 0.8117f,0.5411f,
	-0.5f,  0.5f, 0.5f, 0.4941f, 0.8117f,0.5411f,
	-0.5f, -0.5f, 0.5f, 0.4941f, 0.8117f,0.5411f,

	-0.5f, -0.5f,-0.5f,0.4941f, 0.8117f,0.5411f,//Back
	 0.5f, -0.5f,-0.5f,0.4941f, 0.8117f,0.5411f,
	 0.5f,  0.5f,-0.5f, 0.4941f, 0.8117f,0.5411f,
	 0.5f,  0.5f,-0.5f, 0.4941f, 0.8117f,0.5411f,
	-0.5f,  0.5f,-0.5f, 0.4941f, 0.8117f,0.5411f,
	-0.5f, -0.5f,-0.5f,0.4941f, 0.8117f,0.5411f,

	 0.5f, -0.5f,  0.5f,  0.4941f, 0.8117f,0.5411f,
	 0.5f, -0.5f, -0.5f, 0.4941f, 0.8117f,0.5411f,
	 0.5f,  0.5f, -0.5f, 0.4941f, 0.8117f,0.5411f,
	 0.5f,  0.5f, -0.5f,  0.4941f, 0.8117f,0.5411f,
	 0.5f,  0.5f,  0.5f,  0.4941f, 0.8117f,0.5411f,
	 0.5f,  -0.5f, 0.5f, 0.4941f, 0.8117f,0.5411f,

	-0.5f,  0.5f,  0.5f, 0.4941f, 0.8117f,0.5411f,
	-0.5f,  0.5f, -0.5f, 0.4941f, 0.8117f,0.5411f,
	-0.5f, -0.5f, -0.5f,  0.4941f, 0.8117f,0.5411f,
	-0.5f, -0.5f, -0.5f, 0.4941f, 0.8117f,0.5411f,
	-0.5f, -0.5f,  0.5f,  0.4941f, 0.8117f,0.5411f,
	-0.5f,  0.5f,  0.5f,0.4941f, 0.8117f,0.5411f,

	-0.5f, -0.5f, -0.5f, 0.4941f, 0.8117f,0.5411f,
	0.5f, -0.5f, -0.5f, 0.4941f, 0.8117f,0.5411f,
	0.5f, -0.5f,  0.5f,  0.4941f, 0.8117f,0.5411f,
	0.5f, -0.5f,  0.5f, 0.4941f, 0.8117f,0.5411f,
	-0.5f, -0.5f,  0.5f,0.4941f, 0.8117f,0.5411f,
	-0.5f, -0.5f, -0.5f, 0.4941f, 0.8117f,0.5411f,

	-0.5f,  0.5f, -0.5f, 0.4941f, 0.8117f,0.5411f,
	0.5f,  0.5f, -0.5f, 0.4941f, 0.8117f,0.5411f,
	0.5f,  0.5f,  0.5f, 0.4941f, 0.8117f,0.5411f,
	0.5f,  0.5f,  0.5f,  0.4941f, 0.8117f,0.5411f,
	-0.5f,  0.5f,  0.5f, 0.4941f, 0.8117f,0.5411f,
	-0.5f,  0.5f, -0.5f, 0.4941f, 0.8117f,0.5411f,
	};

	float verticesRoj[] = {
	-0.5f, -0.5f, 0.5f, 0.8156f, 0.3176f,0.3058f,//Front
	0.5f, -0.5f, 0.5f, 0.8156f, 0.3176f,0.3058f,
	0.5f,  0.5f, 0.5f, 0.8156f, 0.3176f,0.3058f,
	0.5f,  0.5f, 0.5f,  0.8156f, 0.3176f,0.3058f,
	-0.5f,  0.5f, 0.5f, 0.8156f, 0.3176f,0.3058f,
	-0.5f, -0.5f, 0.5f, 0.8156f, 0.3176f,0.3058f,

	-0.5f, -0.5f,-0.5f,0.8156f, 0.3176f,0.3058f,//Back
	 0.5f, -0.5f,-0.5f,0.8156f, 0.3176f,0.3058f,
	 0.5f,  0.5f,-0.5f, 0.8156f, 0.3176f,0.3058f,
	 0.5f,  0.5f,-0.5f, 0.8156f, 0.3176f,0.3058f,
	-0.5f,  0.5f,-0.5f,0.8156f, 0.3176f,0.3058f,
	-0.5f, -0.5f,-0.5f,0.8156f, 0.3176f,0.3058f,

	 0.5f, -0.5f,  0.5f,  0.8156f, 0.3176f,0.3058f,
	 0.5f, -0.5f, -0.5f, 0.8156f, 0.3176f,0.3058f,
	 0.5f,  0.5f, -0.5f, 0.8156f, 0.3176f,0.3058f,
	 0.5f,  0.5f, -0.5f, 0.8156f, 0.3176f,0.3058f,
	 0.5f,  0.5f,  0.5f, 0.8156f, 0.3176f,0.3058f,
	 0.5f,  -0.5f, 0.5f, 0.8156f, 0.3176f,0.3058f,

	-0.5f,  0.5f,  0.5f, 0.8156f, 0.3176f,0.3058f,
	-0.5f,  0.5f, -0.5f, 0.8156f, 0.3176f,0.3058f,
	-0.5f, -0.5f, -0.5f, 0.8156f, 0.3176f,0.3058f,
	-0.5f, -0.5f, -0.5f,0.8156f, 0.3176f,0.3058f,
	-0.5f, -0.5f,  0.5f, 0.8156f, 0.3176f,0.3058f,
	-0.5f,  0.5f,  0.5f,0.8156f, 0.3176f,0.3058f,

	-0.5f, -0.5f, -0.5f, 0.8156f, 0.3176f,0.3058f,
	0.5f, -0.5f, -0.5f,  0.8156f, 0.3176f,0.3058f,
	0.5f, -0.5f,  0.5f,  0.8156f, 0.3176f,0.3058f,
	0.5f, -0.5f,  0.5f, 0.8156f, 0.3176f,0.3058f,
	-0.5f, -0.5f,  0.5f,0.8156f, 0.3176f,0.3058f,
	-0.5f, -0.5f, -0.5f, 0.8156f, 0.3176f,0.3058f,

	-0.5f,  0.5f, -0.5f, 0.8156f, 0.3176f,0.3058f,
	0.5f,  0.5f, -0.5f, 0.8156f, 0.3176f,0.3058f,
	0.5f,  0.5f,  0.5f,0.8156f, 0.3176f,0.3058f,
	0.5f,  0.5f,  0.5f, 0.8156f, 0.3176f,0.3058f,
	-0.5f,  0.5f,  0.5f, 0.8156f, 0.3176f,0.3058f,
	-0.5f,  0.5f, -0.5f, 0.8156f, 0.3176f,0.3058f,
	};

	float verticesNA[] = {
	-0.5f, -0.5f, 0.5f, 0.9215f, 0.5098f,0.4117f,//Front
	0.5f, -0.5f, 0.5f, 0.9215f, 0.5098f,0.4117f,
	0.5f,  0.5f, 0.5f, 0.9215f, 0.5098f,0.4117f,
	0.5f,  0.5f, 0.5f,  0.9215f, 0.5098f,0.4117f,
	-0.5f,  0.5f, 0.5f, 0.9215f, 0.5098f,0.4117f,
	-0.5f, -0.5f, 0.5f, 0.9215f, 0.5098f,0.4117f,

	-0.5f, -0.5f,-0.5f,0.9215f, 0.5098f,0.4117f,//Back
	 0.5f, -0.5f,-0.5f,0.9215f, 0.5098f,0.4117f,
	 0.5f,  0.5f,-0.5f,0.9215f, 0.5098f,0.4117f,
	 0.5f,  0.5f,-0.5f,0.9215f, 0.5098f,0.4117f,
	-0.5f,  0.5f,-0.5f,0.9215f, 0.5098f,0.4117f,
	-0.5f, -0.5f,-0.5f,0.9215f, 0.5098f,0.4117f,

	 0.5f, -0.5f,  0.5f,0.9215f, 0.5098f,0.4117f,
	 0.5f, -0.5f, -0.5f,0.9215f, 0.5098f,0.4117f,
	 0.5f,  0.5f, -0.5f,0.9215f, 0.5098f,0.4117f,
	 0.5f,  0.5f, -0.5f,0.9215f, 0.5098f,0.4117f,
	 0.5f,  0.5f,  0.5f,0.9215f, 0.5098f,0.4117f,
	 0.5f,  -0.5f, 0.5f,0.9215f, 0.5098f,0.4117f,

	-0.5f,  0.5f,  0.5f,0.9215f, 0.5098f,0.4117f,
	-0.5f,  0.5f, -0.5f,0.9215f, 0.5098f,0.4117f,
	-0.5f, -0.5f, -0.5f,0.9215f, 0.5098f,0.4117f,
	-0.5f, -0.5f, -0.5f,0.9215f, 0.5098f,0.4117f,
	-0.5f, -0.5f,  0.5f,0.9215f, 0.5098f,0.4117f,
	-0.5f,  0.5f,  0.5f,0.9215f, 0.5098f,0.4117f,

	-0.5f, -0.5f, -0.5f,0.9215f, 0.5098f,0.4117f,
	0.5f, -0.5f, -0.5f, 0.9215f, 0.5098f,0.4117f,
	0.5f, -0.5f,  0.5f, 0.9215f, 0.5098f,0.4117f,
	0.5f, -0.5f,  0.5f, 0.9215f, 0.5098f,0.4117f,
	-0.5f, -0.5f,  0.5f,0.9215f, 0.5098f,0.4117f,
	-0.5f, -0.5f, -0.5f,0.9215f, 0.5098f,0.4117f,

	-0.5f,  0.5f, -0.5f,0.9215f, 0.5098f,0.4117f,
	0.5f,  0.5f, -0.5f, 0.9215f, 0.5098f,0.4117f,
	0.5f,  0.5f,  0.5f,0.9215f, 0.5098f,0.4117f,
	0.5f,  0.5f,  0.5f,0.9215f, 0.5098f,0.4117f,
	-0.5f,  0.5f,  0.5f,0.9215f, 0.5098f,0.4117f,
	-0.5f,  0.5f, -0.5f,0.9215f, 0.5098f,0.4117f,
	};

	float verticesG[] = {
-0.5f, -0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f, // Front
 0.5f, -0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f,  0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f,  0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f,  0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f, -0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,

-0.5f, -0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f, // Back
 0.5f, -0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f,  0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f,  0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f,  0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f, -0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,

 0.5f, -0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f, // Right
 0.5f, -0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f,  0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f,  0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f,  0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f, -0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,

-0.5f,  0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f, // Left
-0.5f,  0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f, -0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f, -0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f, -0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f,  0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,

-0.5f, -0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f, // Bottom
 0.5f, -0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f, -0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f, -0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f, -0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f, -0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,

-0.5f,  0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f, // Top
 0.5f,  0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f,  0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
 0.5f,  0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f,  0.5f,  0.5f, 0.4941f, 0.4941f, 0.4941f,
-0.5f,  0.5f, -0.5f, 0.4941f, 0.4941f, 0.4941f
	};

	float verticesNegro[] = {
-0.5f, -0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f, // Front 
 0.5f, -0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f,  0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f,  0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f,  0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f, -0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,

-0.5f, -0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f, // Back
 0.5f, -0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f,  0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f,  0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f,  0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f, -0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,

 0.5f, -0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f, // Right
 0.5f, -0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f,  0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f,  0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f,  0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f, -0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,

-0.5f,  0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f, // Left
-0.5f,  0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f, -0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f, -0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f, -0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f,  0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,

-0.5f, -0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f, // Bottom
 0.5f, -0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f, -0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f, -0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f, -0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f, -0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,

-0.5f,  0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f, // Top
 0.5f,  0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f,  0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
 0.5f,  0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f,  0.5f,  0.5f, 0.0313f, 0.0313f, 0.0313f,
-0.5f,  0.5f, -0.5f, 0.0313f, 0.0313f, 0.0313f
	};


	//CUBO ROSA
	
		GLuint VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		//glGenBuffers(1, &EBO);

		// Enlazar  Vertex Array Object
		glBindVertexArray(VAO);

		//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
		/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

		// 4. Despues colocamos las caracteristicas de los vertices

		//Posicion
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		//Color
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	// blanco
	GLuint VBO_B, VAO_B;
	glGenVertexArrays(1, &VAO_B);
	glGenBuffers(1, &VBO_B);

	glBindVertexArray(VAO_B);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_B);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesB), verticesB, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//verde
	GLuint VBO_verde, VAO_verde;
	glGenVertexArrays(1, &VAO_verde);
	glGenBuffers(1, &VBO_verde);

	glBindVertexArray(VAO_verde);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_verde);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesvER), verticesvER, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	//rojo
	GLuint VBO_rojo, VAO_rojo;
	glGenVertexArrays(1, &VAO_rojo);
	glGenBuffers(1, &VBO_rojo);

	glBindVertexArray(VAO_rojo);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_rojo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesRoj), verticesRoj, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//naranja
	GLuint VBO_naranja, VAO_naranja;
	glGenVertexArrays(1, &VAO_naranja);
	glGenBuffers(1, &VBO_naranja);

	glBindVertexArray(VAO_naranja);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_naranja);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesNA), verticesNA, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// Declaración de VAOs y VBOs para los diferentes colores

	
	

	

	// Cubo Gris (G)
	GLuint VBO_G, VAO_G;
	glGenVertexArrays(1, &VAO_G);
	glGenBuffers(1, &VBO_G);

	glBindVertexArray(VAO_G);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_G);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesG), verticesG, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// Cubo Negro (Negro)

	GLuint VBO_Negro, VAO_Negro;
	glGenVertexArrays(1, &VAO_Negro);
	glGenBuffers(1, &VBO_Negro);

	glBindVertexArray(VAO_Negro);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_Negro);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesNegro), verticesNegro, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	
	glm::mat4 projection=glm::mat4(1);

	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	//projection = glm::ortho(0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f);//Izq,Der,Fondo,Alto,Cercania,Lejania
	while (!glfwWindowShouldClose(window))
	{

		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glm::mat4 model = glm::mat4(1);
		glm::mat4 view = glm::mat4(1);


		view = glm::translate(view, glm::vec3(movX, movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");


		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));


		glBindVertexArray(VAO);


		// partes rosas
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(3.0f, 2.0f, 1.5f));
		model = glm::translate(model, glm::vec3(0.0f, 0.25f, -1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.5f, 2.5f, 1.5f));
		model = glm::translate(model, glm::vec3(0.0f, -0.5f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
				
		// tetaculo frente izquierdo
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.3f));
		model = glm::translate(model, glm::vec3(-1.0f, -5.5f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 1.0f, 0.2f));
		model = glm::translate(model, glm::vec3(-1.0f, -1.9f, 10.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.1f, 0.4f));
		model = glm::translate(model, glm::vec3(-1.0f, -14.5f, 5.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//tentaculo frente derecho
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.3f));
		model = glm::translate(model, glm::vec3(1.0f, -5.5f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 1.2f, 0.2f));
		model = glm::translate(model, glm::vec3(1.0f, -1.5f, 10.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.1f, 0.4f));
		model = glm::translate(model, glm::vec3(1.0f, -12.5f, 5.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//tentaculo derecho enfrente
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.1f, 0.4f, 0.4f));
		model = glm::translate(model, glm::vec3(1.0f, -5.5f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 1.2f, 0.4f));
		model = glm::translate(model, glm::vec3(8.7f, -1.5f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.1f, 0.4f));
		model = glm::translate(model, glm::vec3(5.0f, -12.5f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//tentaculo derecho atras
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.1f, 0.4f, 0.4f));
		model = glm::translate(model, glm::vec3(1.0f, -5.5f, -1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 1.0f, 0.4f));
		model = glm::translate(model, glm::vec3(8.7f, -1.9f, -1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.1f, 0.4f));
		model = glm::translate(model, glm::vec3(5.0f, -14.5f, -1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//tentaculo izquierod enfrente
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.1f, 0.4f, 0.4f));
		model = glm::translate(model, glm::vec3(-1.0f, -5.5f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 1.2f, 0.4f));
		model = glm::translate(model, glm::vec3(-8.7f, -1.5f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		

		//tentaculo izquiedo atras
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.1f, 0.4f, 0.4f));
		model = glm::translate(model, glm::vec3(-1.0f, -5.5f, -1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 1.4f, 0.4f));
		model = glm::translate(model, glm::vec3(-8.7f, -1.2f, -1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.1f, 0.4f));
		model = glm::translate(model, glm::vec3(-5.0f, -10.2f, -1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		// tetaculo atras izquierdo
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.3f));
		model = glm::translate(model, glm::vec3(-1.0f, -5.5f, -1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 1.2f, 0.2f));
		model = glm::translate(model, glm::vec3(-1.0f, -1.5f, -10.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.1f, 0.4f));
		model = glm::translate(model, glm::vec3(-1.0f, -12.3f, -5.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//tentaculo atras derecho
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.3f));
		model = glm::translate(model, glm::vec3(1.0f, -5.5f, -1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 1.2f, 0.2f));
		model = glm::translate(model, glm::vec3(1.0f, -1.5f, -10.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.1f, 0.4f));
		model = glm::translate(model, glm::vec3(1.0f, -12.3f, -5.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

	
//


		//Partes blancas


		glBindVertexArray(VAO_B);

		// ojo derecho
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(1.0f, 0.0f, 1.8f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Ojo Izquierdo

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, 1.75f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//venda patita

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.1f, 0.5f));
		model = glm::translate(model, glm::vec3(-4.5f, -13.2f,0.8f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.1f, 0.5f));
		model = glm::translate(model, glm::vec3(-4.5f, -15.2f, 0.8f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

//
		////partes negras
		glBindVertexArray(VAO_Negro);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(4.0f, 1.5f, 1.5f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		// ojo derecho
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 4.2f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Ojo Izquierdo

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.45f, 0.45f, 0.45f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-2.0f, 0.0f, 4.2f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//audifonos

		glBindVertexArray(VAO_Negro);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(3.5f, 0.25f, 0.25f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(0.0f, 6.5f, 0.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.25f, 2.0f, 0.25f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-7.0f, 0.25f, 0.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.25f, 2.0f, 0.25f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(7.0f, 0.25f, 0.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		//partes grises

		glBindVertexArray(VAO_G);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(5.0f, 1.0f, 1.0f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
//
		////partes naranjas
		
		glBindVertexArray(VAO_naranja);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-9.5f, -10.0f, 2.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-9.5f, -10.0f, -2.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-9.5f, -7.0f, -2.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(9.5f, -9.0f, -2.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);



		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(9.5f, -11.0f, -2.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(9.5f, -8.0f, 2.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(9.5f, -10.0f, 2.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//izquierda frente

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(2.0f, -8.0f, 11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(2.0f, -10.0f, 11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//derecha frente

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-2.0f, -9.0f, 11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-2.0f, -11.0f, 11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		//izquierda frente

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(2.0f, -8.0f, -11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(2.0f, -10.0f, -11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//derecha frente

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-2.0f, -8.0f, -11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

;
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-2.0f, -10.0f, -11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		//izquierda frente

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(2.0f, -8.0f, 11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(2.0f, -10.0f, 11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//derecha frente

		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-2.0f, -9.0f, 11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);


		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-2.0f, -11.0f, 11.0f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Partes verdes
		glBindVertexArray(VAO_verde);
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 1.0f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(-4.5f, 0.0f, 1.7f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Partes rojas
		glBindVertexArray(VAO_rojo);

		// ojo derecho
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 1.0f));  // Tamaño del cubo
		model = glm::translate(model, glm::vec3(4.0f, 0.0f, 1.4f)); // Posición del cubo en la escena
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glDeleteVertexArrays(1, &VAO_B);
	glDeleteBuffers(1, &VBO_B);

	glDeleteVertexArrays(1, &VAO_verde);
	glDeleteBuffers(1, &VBO_verde);

	glDeleteVertexArrays(1, &VAO_rojo);
	glDeleteBuffers(1, &VBO_rojo);

	glDeleteVertexArrays(1, &VAO_naranja);
	glDeleteBuffers(1, &VBO_naranja);

	glDeleteVertexArrays(1, &VAO_G);
	glDeleteBuffers(1, &VBO_G);

	glDeleteVertexArrays(1, &VAO_Negro);
	glDeleteBuffers(1, &VBO_Negro);

	glfwTerminate();
	return EXIT_SUCCESS;
 }

 void Inputs(GLFWwindow *window) {
	 if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		 glfwSetWindowShouldClose(window, true);
	 if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		 movX += 0.008f;
	 if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		 movX -= 0.008f;
	 if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		 movY += 0.008f;
	 if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		 movY -= 0.008f;
	 if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 movZ -= 0.008f;
	 if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		 movZ += 0.008f;
	 if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		 rot += 0.04f;
	 if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		 rot -= 0.04f;
 }


