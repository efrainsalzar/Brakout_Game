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
	int speed;

	SDL_Color color;

public:
	GameObject(int _x, int _y, int _width, int _height, int _speed, SDL_Color _color);
	virtual ~GameObject();

	virtual void update() = 0;
	virtual void render(SDL_Renderer* _renderer) = 0;

	//Metodo de acceso
	int getX() const { return bodyObject->x; }
	int getY() const { return bodyObject->y; }
	int getWidth() const { return bodyObject->w; }
	int getHeight() const { return bodyObject->h; }
	int getSpeed() const { return speed; }
	SDL_Color getColor() const { return color; }


};

