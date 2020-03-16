#pragma once

#include "Screen.h"
#include "Interfaces/Updatable.h"
#include <vector>

class Engine : Updatable
{
private:

	std::vector<Updatable*> updatables;

	Screen* screen;

	bool gamePaused;

	float totalGameTimeInSec;

	void ProcessInput();

	void Update();

	void Draw();

public:

	Engine();

	void Run();

	float GetTotalTime() const;
};