#pragma once
#include <SDL.h>
#include <iostream>	
#include "Window.h"
class GameObject
{
private:

protected:
	SDL_Rect* bodyObject;
	SDL_Renderer* renderer;
	int x;
	int y;
	int width;
	int height;

	SDL_Color color;


public:

	enum class Side {
		TOP,
		BOTTOM,
		LEFT,
		RIGHT,
		NONE  // Para el caso en que no se pueda determinar un lado
	};

	GameObject(int _x, int _y, int _width, int _height, SDL_Color _color);
	virtual ~GameObject();

	virtual void update() = 0;
	virtual void render(SDL_Renderer* _renderer) = 0;
	virtual void handleInput(SDL_Event& _event) = 0;
	virtual void handleCollision(Side* _side ) =0;
	virtual bool getIsDestroyed() = 0;


	//Metodo de acceso
	SDL_Rect* getBody()  { return bodyObject; }
	int getX()  { return bodyObject->x; }
	int getY()  { return bodyObject->y; }
	int getWidth()  { return bodyObject->w; }
	int getHeight()  { return bodyObject->h; }
	SDL_Color getColor()  { return color; }
};

