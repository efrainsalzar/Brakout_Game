#include "Brick.h"

Brick::Brick(int _x, int _y, int _width, int _height, SDL_Color _color):
	GameObject(_x,_y,_width,_height,_color)
{
}

Brick::Brick() :
	GameObject(400,				// Posición x
		300,					// Posición y
		40,						// Ancho
		20,						// Alto
		{ 220, 26, 218, 255 }) // Color 
{ }

Brick::~Brick()
{
}

void Brick::update()
{
}

void Brick::render(SDL_Renderer* _renderer)
{
	// Dibuja la bola en pantalla con el color especificado
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a); // Usar el color de la bola
	SDL_RenderFillRect(_renderer, bodyObject); // Dibuja el rectángulo

}

void Brick::handleInput(SDL_Event& _event)
{
}

void Brick::setPosition(int _x, int _y) {
    bodyObject->x = _x; // Actualiza la posición x
    bodyObject->y = _y; // Actualiza la posición y
}

void Brick::setSize(int _width, int _height) {
    bodyObject->w = _width; // Actualiza el ancho
    bodyObject->h = _height; // Actualiza el alto
}

void Brick::handleCollision(Side* _side)
{

  // Call the destructor and delete the brick
	isDestroyed = true;

}
