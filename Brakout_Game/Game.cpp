#include "Game.h"

Game::Game(): 
	window(nullptr),
	running(false) {
	
}

Game::~Game() {
	//std::cout << "Game destructor called" << std::endl;
	clean();
}

bool Game::init() {
	window = Window::getInstance();
	if (window==nullptr || !window->create()) {
		std::cerr << "Error al inicializar la ventana" << std::endl;
		return false;
	}

	paddle = new Paddle();
	gameObjects.push_back(paddle);

	// Crear la bola, adjuntarla al Paddle y agregarla a los objetos del juego
	Ball* ball = new Ball();
	ball->attachToPaddle(paddle); // Adjuntar la bola al Paddle
	gameObjects.push_back(ball);  // Agregar la bola a los objetos del juego

	// Crear ladrillos usando BrickFactory y agregarlos a gameObjects
	BrickFactory::createBricks(gameObjects);


	running = true;
	return true;
}

void Game::handleEvents() {
	
	while (SDL_PollEvent(&event)){
		if (event.type == SDL_QUIT) {
			running = false;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				running = false;
			}
		}
		for (GameObject* obj : gameObjects) {
			obj->handleInput(event);
		}
	}
}

void Game::update() {
	// actualizar objectos
	for (GameObject* obj : gameObjects) {
		obj->update();
	}

	// validar colisiones
	for (size_t i = 0; i < gameObjects.size(); ++i) {
		for (size_t j = i + 1; j < gameObjects.size(); ++j) {
			if (collisionManager->checkCollision(gameObjects[i], gameObjects[j])) {
				collisionManager->handleCollision(gameObjects[i], gameObjects[j]);
			}
		}
	}

	for (auto it = gameObjects.begin(); it != gameObjects.end(); ) {
		if ((*it)->getIsDestroyed()) {
			delete* it;  // Elimina el objeto
			it = gameObjects.erase(it);  // Elimina el objeto de la lista
		}
		else {
			++it;
		}
	}
}

void Game::render() {
		window->clear();

		// Aquí irá el código para renderizar los objetos.
		for (GameObject* obj : gameObjects) {
			obj->render(window->getRenderer());
		}


		window->present();
}

bool Game::isRunning() const {
	return running;
}

// Limpieza de recursos ---------------------------------
void Game::clean() {

	for (GameObject* obj : gameObjects) {
		delete obj;
	}
	gameObjects.clear();

	if (window) {
		delete window;
	}
}