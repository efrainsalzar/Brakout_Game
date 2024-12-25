#pragma once
#include "Window.h"
#include "Panddle.h"
#include "Ball.h"

class Game
{
private:
	Window* window;
	bool running;

	Panddle* panddle; // Barra del jugador
	Ball* ball; // Bola del juego

public:
	Game();
	~Game();

	bool init();
	void handleEvents();
	void update();
	void render();
	void clean();
	bool isRunning() const;

};

