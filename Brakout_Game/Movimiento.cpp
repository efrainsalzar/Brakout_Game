#include "Movimiento.h"
#include <iostream>

Movimiento::Movimiento(SDL_Rect* _bodyObject) : 
    bodyObject(_bodyObject)
{
	window = Window::getInstance();
}

Movimiento::~Movimiento() {

}

void Movimiento::moverPaddle(const Uint8* currentKeyStates, int _speed) {
	if (currentKeyStates[SDL_SCANCODE_LEFT]) {
		bodyObject->x -= _speed;  // Mover a la izquierda
	}
	if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
		bodyObject->x += _speed;  // Mover a la derecha
	}
}

void Movimiento::validarLimites() {
	// L�mite izquierdo
	if (bodyObject->x < 0) {
		bodyObject->x = 0;
	} 
	// L�mite derecho
	if (bodyObject->x + bodyObject->w > window->getScreenWidth()) {
		bodyObject->x = window->getScreenWidth() - bodyObject->w;
	}
}	
void Movimiento::validarLimitesBall(bool& _bordeH, bool& _bordeV) {
	_bordeH = false;
	_bordeV = false;

	// L�mite izquierdo
	if (bodyObject->x < 0) {
		bodyObject->x = 0;
		_bordeH = true;
	}
	// L�mite derecho
	if (bodyObject->x + bodyObject->w > window->getScreenWidth()) {
		bodyObject->x = window->getScreenWidth() - bodyObject->w;
		_bordeH = true;
	}
	// L�mite superior
	if (bodyObject->y < 0) {
		bodyObject->y = 0;
		_bordeV = true;
	}
	// L�mite inferior
	if (bodyObject->y + bodyObject->h > window->getScreenHeight()) {
		bodyObject->y = window->getScreenHeight() - bodyObject->h;
		_bordeV = true;
	}
}

void Movimiento::moverBall(int dirX, int dirY, int speed) {
	bodyObject->x += dirX * speed;
	bodyObject->y += dirY * speed;
}