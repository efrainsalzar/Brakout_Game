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
	// Agregamos lo objetos a nuestro vector
	gameObjects.push_back(new Paddle());
	gameObjects.push_back(new Ball());


	running = true;
	return true;
}

void Game::handleEvents() {
	
	while (SDL_PollEvent(&event)){
		if (event.type == SDL_QUIT) {
			running = false;
		}
		//for (GameObject* obj : gameObjects) {
		//	obj->handleInput(event);
		//}
	}
}

void Game::update() {
	for (GameObject* obj : gameObjects) {
		obj->update();
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