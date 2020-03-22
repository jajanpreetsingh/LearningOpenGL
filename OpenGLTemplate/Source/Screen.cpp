#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Utils/LoadedAssets.h"
#include "Screen.h"
#include <iostream>
#include "Utils/Matrix/Matrix.h"
#include "gtc/type_ptr.hpp"
#include "Utils/Debug.h"

const unsigned int Screen::WIDTH = 1280;
const unsigned int Screen::HEIGHT = 720;

Screen::Screen()
{
	height = HEIGHT;
	width = WIDTH;

	new LoadedAssets();

	InitializeGLFW();

	InitializeGLEW();

	CreatePyramid();
}

void Screen::Update()
{
	glfwPollEvents(); // for input and stuff

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	pyramid->Update();

	glfwSwapBuffers(mainWindow);
}

Screen::~Screen()
{
}

int Screen::InitializeGLFW()
{
	if (!glfwInit())
	{
		std::cout << "Error Initializing GLFW!!!" << std::endl;
		glfwTerminate();
		return 1;
	}

	//Init GLFW window properties

	//OpenGL major/minor version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//opengl profile - core OR any
	//core is used so we dont use depricated api/ hence its not backward compatible
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//it should be forward compatible
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//create a window
	mainWindow = glfwCreateWindow(width, height, "Main Game", NULL, NULL);

	if (!mainWindow)
	{
		std::cout << "Error Creating GLFW Window!!!" << std::endl;
		glfwTerminate();
		return 1;
	}

	//initialize frame buffer size for openGL
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//make this window active- can be used for switching between windows
	SwitchToThisWindow();

	return 0;
}

int Screen::InitializeGLEW()
{
	//enable glew extensions
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error Initializing GLEW!!!" << std::endl;
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//enable z buffer test
	glEnable(GL_DEPTH_TEST);

	//setup viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	return 0;
}

void Screen::SwitchToThisWindow()
{
	glfwMakeContextCurrent(mainWindow);
}

void Screen::CreateTriagle()
{
	tris = new Tris(Vec3(-1, -1, 0), Vec3(1, -1, 0), Vec3(0, 0.8, 0));
}

void Screen::CreatePyramid()
{
	pyramid = new Geometry();

	std::vector<Vec3> verts =
	{
		Vec3(-1, -1, 0), //0
		Vec3(0, -1, 1),  //1
		Vec3(1, -1, 0),  //2
		Vec3(0, 1, 0)    //3
	};

	pyramid->SetVertices(verts);

	std::vector<GLuint> ind =
	{
		0,3,1,
		1,3,2,
		2,3,0,
		0,1,2
	};

	pyramid->SetIndices(ind);

	pyramid->GenerateVertexInfoHandle();
	pyramid->BindVertexArrayHandle();

	pyramid->GenerateIndexBufferHandle(); //binds handle and data as well
	pyramid->GenerateBufferDataHandle(); //binds handle and data as well

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	pyramid->UnBindBufferDataHandle();
	pyramid->UnbindIndexBufferHandle();
	pyramid->UnbindVertexArrayHandle();
}

void Screen::SetUniforms()
{
	glm::mat4 model = glm::mat4(1.0);

	model = Matrix::Rotate(model, 45 * (3.14159265f / 180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//model = glm::translate(model, glm::vec3(triOffset, 0.0f, 0.0f));

	model = Matrix::Scale(model, glm::vec3(0.4f, 0.4f, 1.0f));

	glUniformMatrix4fv(pyramid->shader->GetUniformLocation("model"), 1, GL_FALSE, glm::value_ptr(model));
}
