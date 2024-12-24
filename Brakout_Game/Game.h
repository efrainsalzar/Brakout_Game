#pragma once
#include "Window.h"
#include "Panddle.h"

class Game
{
private:
	Window* window;
	bool running;

	Panddle* panddle;

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

