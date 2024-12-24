#pragma once
#include <SDL.h>
#include <iostream>	
class GameObject
{
private:
	
protected:
	SDL_Rect bodyObject;
	SDL_Renderer* renderer;
	int x;
	int y;
	int width;
	int height;

public:
	GameObject(int _x, int _y, int _width, int _height);
	virtual ~GameObject();

	virtual void update() = 0;
	virtual void render(SDL_Renderer* _renderer) = 0;

	//Metodo de acceso
	int getX() const { return x; }
	int getY() const { return y; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }


};

