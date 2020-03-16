#pragma once

#include "Engine.h"

void Engine::ProcessInput()
{
}

void Engine::Update()
{	
}

void Engine::Draw()
{
}

Engine::Engine()
{
	gamePaused = false;

	totalGameTimeInSec = 0;

	screen = new Screen();

	updatables.push_back(screen);
}

void Engine::Run()
{
	while (!glfwWindowShouldClose(screen->mainWindow))
	{
		for (size_t i = 0; i < updatables.size(); i++)
		{
			updatables[i]->Update();
		}
	}
}

float Engine::GetTotalTime() const
{
	return totalGameTimeInSec;
}


