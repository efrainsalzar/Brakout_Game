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

	SDL_RenderClear(renderer);
}

void Window::present() {
	SDL_RenderPresent(renderer);
}

void Window::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	
}