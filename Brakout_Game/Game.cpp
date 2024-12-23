#include "Game.h"

Game::Game(): 
	window(nullptr),
	running(false) { }

Game::~Game() {
	clean();
}

bool Game::init(const char* _title, int _screenWidth, int _screenHeight) {
	window = new Window(_title, _screenWidth, _screenHeight);
	if (!window->create()) {
		std::cerr << "Error al inicializar la ventana" << std::endl;
		return false;
	}
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)){
		if (event.type == SDL_QUIT) {
			running = false;
		}
	}
}

void Game::update() {
	//Aquí irá la lógica del juego más adelante.

}

void Game::render() {
	window->clear();
	//Aquí irá el código para renderizar los objetos.

	window->present();
}

bool Game::isRunning() const {
	return running;
}

// Limpieza de recursos ---------------------------------
void Game::clean() {
	if (window) {
		window->clean();
		delete window;
	}
}