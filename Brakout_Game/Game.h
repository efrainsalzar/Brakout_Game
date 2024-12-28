#pragma once
#include "Window.h"
#include "GameObject.h"

#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "CollisionManager.h"

#include <vector>

class Game
{
private:
	Window* window;
	bool running;
	SDL_Event event;

	std::vector<GameObject*> gameObjects;

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

