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
	virtual std::string getName() const = 0;
	virtual Side getCollisionSide(const SDL_Rect* other) const = 0;


	//Metodo de acceso
	SDL_Rect* getBody() const { return bodyObject; }
	int getX() const { return bodyObject->x; }
	int getY() const { return bodyObject->y; }
	int getWidth() const { return bodyObject->w; }
	int getHeight() const { return bodyObject->h; }
	SDL_Color getColor() const { return color; }
};

