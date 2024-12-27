#include "Game.h"

Game::Game(): 
	window(nullptr),
	panddle(nullptr),
	running(false) { }

Game::~Game() {
	std::cout << "Game destructor called" << std::endl;
	clean();
}

bool Game::init() {
	window = Window::getInstance();
	if (!window->create()) {
		std::cerr << "Error al inicializar la ventana" << std::endl;
		return false;
	}

	panddle = new Panddle();
	ball = new  Ball();
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
	//Aqu� ir� la l�gica del juego m�s adelante.
	panddle->update();
	ball->update();

	// Colisi�n entre bola y panddle
	CollisionManager  colision;
	if (colision.checkCollision(ball, panddle)) {
		//std::cout << "Colisi�n detectada entre bola y panddle" << std::endl;
		//colision.handleCollision(ball, panddle);
	}
}

void Game::render() {
	if (window) {
		window->clear();
		// Aqu� ir� el c�digo para renderizar los objetos.
		panddle->render(window->getRenderer()); // Renderizamos la barra
		ball->render(window->getRenderer()); // Renderizamos la bola
		//ball->drawCircle(window->getRenderer(), ball->getX(), ball->getY(), ball->getWidth(), ball->getColor());
		
		window->present();
	}
}

bool Game::isRunning() const {
	return running;
}

// Limpieza de recursos ---------------------------------
void Game::clean() {
	//delete window;
	delete panddle;
	delete ball;
}