#pragma once

#include <SDL.h>
#include <iostream>

class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	int screenWidth;
	int screenHeight;

public:

	Window(const char* _title, int _screenWidth, int _screenHeight);
	~Window();

	bool create(); //crea la ventana wondows
	SDL_Renderer* getRenderer(); //obtiene el renderer
	void clear();	//limpia la pantalla
	void present(); //bufer de presentacion
	void clean();	//destruir SDL
};

