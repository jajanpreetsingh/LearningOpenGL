#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Screen.h"
#include <iostream>

const unsigned int Screen::WIDTH = 1280;
const unsigned int Screen::HEIGHT = 720;

Screen::Screen()
{
	height = HEIGHT;
	width = WIDTH;

	InitializeGLFW();

	InitializeGLEW();

	CreateTriagle();
}

void Screen::Update()
{
	glfwPollEvents(); // for input and stuff

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	tris->Draw();

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
	tris = new Tris(Vec3(-1, -1, 0), Vec3(1, -1, 0), Vec3(0, 1, 0));

	shader = tris->ConstructShader();
}