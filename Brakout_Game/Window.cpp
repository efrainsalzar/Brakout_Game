#include "Window.h"
#include <iostream>

Window* Window::instance = nullptr;

Window::Window(std::string _title, int _screenWidth, int _screenHeight) :
	window(nullptr),
	renderer(nullptr),
	title(_title),
	screenWidth(_screenWidth),
	screenHeight(_screenHeight) {
	std::cout << "Window constructor called witch parents" << std::endl;
	instance = this;
}

Window::Window() :
	
	window(nullptr),
	renderer(nullptr),
	title("Breackout"),
	screenWidth(808),
	screenHeight(600) {
	std::cout << "Window constructor called s/n parents" << std::endl;
	instance = this;
}

Window::~Window() {
	std::cout << "Window destructor called" << std::endl;
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
		SDL_Quit();
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cerr << "Error al crear el renderizador: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}

	return true;
}

SDL_Renderer* Window::getRenderer() {
	if (renderer == nullptr) {
		std::cerr << "Error: puntero renderer nulo" << std::endl;
	}
	return renderer;
}

void Window::clear() {
	if (renderer) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	}
	else {
		std::cerr << "Error: renderer es un puntero nulo en clear()." << std::endl;
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
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

Window* Window::getInstance()
{
	if (instance == nullptr) {
		instance = new Window();  // Crear la instancia si no existe
	}
	return instance;
}
