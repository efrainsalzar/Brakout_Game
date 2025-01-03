#pragma once
#include "Window.h"
#include "GameObject.h"

#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "BrickFactory.h"

#include "CollisionManager.h"

#include <vector>

class Game
{
private:
	Paddle* paddle;  // Referencia al Paddle
	Window* window;
	bool running;
	SDL_Event event;

	std::vector<GameObject*> gameObjects;

	CollisionManager* collisionManager;

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

