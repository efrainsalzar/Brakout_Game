#pragma once

#include <SDL.h>
#include <iostream>
#include <string>

class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	static Window* instance;

	std::string title;
	int screenWidth;
	int screenHeight;

public:

	Window(std::string _title, int _screenWidth, int _screenHeight);
	Window();	
	~Window();



	bool create(); //crea la ventana wondows
	SDL_Renderer* getRenderer(); //obtiene el renderer
	void clear();	//limpia la pantalla
	void present(); //bufer de presentacion
	void clean();	//destruir SDL

	//metodos de acceso
	int getScreenWidth() const { return screenWidth; }
	int getScreenHeight() const { return screenHeight; }

	static Window* getInstance();
};

