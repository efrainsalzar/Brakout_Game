#pragma once
#include "Window.h"

class Game
{
private:
	Window* window;
	bool running;

public:
	Game();
	~Game();

	bool init(const char* _title, int _width, int _height);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool isRunning() const;

};

