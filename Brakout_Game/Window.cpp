#include "Window.h"

Window::Window(const char* _title, int _screenWidth, int _screenHeight):
	window(nullptr),
	renderer(nullptr), 
	screenWidth(_screenWidth), 
	screenHeight(_screenHeight) {}

Window::~Window() {
	clean();
}

bool Window::create() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if (!window) {
		std::cerr << "Error al crear la ventana: " << SDL_GetError() << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cerr << "Error al crear el renderizador: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

SDL_Renderer* Window::getRenderer(){
	return renderer;
}

void Window::clear() {
	if (renderer) {
		SDL_RenderClear(renderer);
	}
	else {
		std::cerr << "Error: renderer es un puntero nulo." << std::endl;
	}
}

void Window::present() {
	if (renderer) {
		SDL_RenderPresent(renderer);
	}
	else {
		std::cerr << "Error: renderer es un puntero nulo." << std::endl;
	}
}

void Window::clean() { 
	if (renderer) SDL_DestroyRenderer(renderer);
	if (window) SDL_DestroyWindow(window);
	SDL_Quit();
}