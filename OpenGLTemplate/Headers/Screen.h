#pragma once

#include <Common/Tris.h>
#include <GLFW/glfw3.h>
#include <Interfaces/Updatable.h>

class Screen : public Updatable
{
public:

	static const unsigned int WIDTH;
	static const unsigned int HEIGHT;

	GLFWwindow* mainWindow;
	int bufferHeight = 0;
	int bufferWidth = 0;

	Tris* tris;
	Geometry* pyramid;

	Screen();

	void Update();

	~Screen();

private:
	int height = 0;
	int width = 0;

	int InitializeGLFW();

	int InitializeGLEW();

	void SwitchToThisWindow();

	void CreateTriagle();

	void CreatePyramid();

	void SetUniforms();
};