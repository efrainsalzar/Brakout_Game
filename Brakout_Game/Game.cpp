#include "Game.h"

Game::Game(): 
	window(nullptr),
	panddle(nullptr),
	running(false) { }

Game::~Game() {
	std::cout << "Game destructor called" << std::endl;
	clean();
}

bool Game::init(const char* _title, int _screenWidth, int _screenHeight) {
	window = new Window(_title, _screenWidth, _screenHeight);
	if (!window->create()) {
		std::cerr << "Error al inicializar la ventana" << std::endl;
		return false;
	}

	panddle = new Panddle(400, 500, 100, 20, 5, 3, { 255, 0, 0, 255 });
	running = true;
	return true;
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
	panddle->update();
}

void Game::render() {
	if (window) {
		window->clear();
		// Aquí irá el código para renderizar los objetos.
		panddle->render(window->getRenderer()); // Renderizamos la barra
		
		window->present();
	}
}

bool Game::isRunning() const {
	return running;
}

// Limpieza de recursos ---------------------------------
void Game::clean() {
	delete window;
	delete panddle;
}