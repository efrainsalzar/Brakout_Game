#include "Movimiento.h"
#include <iostream>

Movimiento::Movimiento(SDL_Rect* _bodyObject) : 
    bodyObject(_bodyObject)
{
	
}

Movimiento::~Movimiento() {

}

void Movimiento::mover(Direccion _direccion, int _speed) {
    switch (_direccion) {
    case Direccion::ARRIBA:
        bodyObject->y -= _speed;
        break;
    case Direccion::ABAJO:
        bodyObject->y += _speed;
        break;
    case Direccion::IZQUIERDA:
        bodyObject->x -= _speed;
        break;
    case Direccion::DERECHA:
        bodyObject->x += _speed;
        break;
    case Direccion::DIAGONAL_ARRIBA_IZQUIERDA:
        bodyObject->x -= _speed;
        bodyObject->y -= _speed;
        break;
    case Direccion::DIAGONAL_ARRIBA_DERECHA:
        bodyObject->x += _speed;
        bodyObject->y -= _speed;
        break;
    case Direccion::DIAGONAL_ABAJO_IZQUIERDA:
        bodyObject->x -= _speed;
        bodyObject->y += _speed;
        break;
    case Direccion::DIAGONAL_ABAJO_DERECHA:
        bodyObject->x += _speed;
        bodyObject->y += _speed;
        break;
    }

}

void Movimiento::rebote(Direccion& _direccion, ChoqueBorde _choque) {

	switch (_direccion) {
	case Direccion::DIAGONAL_ABAJO_IZQUIERDA:
		if (_choque == ChoqueBorde::ABAJO) {
			_direccion = Movimiento::Direccion::DIAGONAL_ARRIBA_IZQUIERDA;
		}
		else if (_choque == ChoqueBorde::IZQUIERDA) {
			_direccion = Movimiento::Direccion::DIAGONAL_ABAJO_DERECHA;
		}
		break;
	case Direccion::DIAGONAL_ABAJO_DERECHA:
		if (_choque == ChoqueBorde::ABAJO) {
			_direccion = Movimiento::Direccion::DIAGONAL_ARRIBA_DERECHA;
		}
		else if (_choque == ChoqueBorde::DERECHA) {
			_direccion = Movimiento::Direccion::DIAGONAL_ABAJO_IZQUIERDA;
		}
		break;
	case Direccion::DIAGONAL_ARRIBA_IZQUIERDA:
		if (_choque == ChoqueBorde::ARRIBA) {
			_direccion = Movimiento::Direccion::DIAGONAL_ABAJO_IZQUIERDA;
		}
		else if (_choque == ChoqueBorde::IZQUIERDA) {
			_direccion = Movimiento::Direccion::DIAGONAL_ARRIBA_DERECHA;
		}
		break;
	case Direccion::DIAGONAL_ARRIBA_DERECHA:
		if (_choque == ChoqueBorde::ARRIBA) {
			_direccion = Movimiento::Direccion::DIAGONAL_ABAJO_DERECHA;
		}
		else if (_choque == ChoqueBorde::DERECHA) {
			_direccion = Movimiento::Direccion::DIAGONAL_ARRIBA_IZQUIERDA;
		}
		break;
	}
}

void Movimiento::validarLimites(Direccion& _direccion) {
	// Verificar los límites de la pantalla
	if (bodyObject->x < 0) {
		//bodyObject.x = 0; // Límite izquierdo
		rebote(_direccion, ChoqueBorde::IZQUIERDA);
	}
	if (bodyObject->x + bodyObject->w > 800) {
		//bodyObject.x = 800 - bodyObject.w; // Límite derecho
		rebote(_direccion, ChoqueBorde::DERECHA);
	}
	if (bodyObject->y < 0) {
		//bodyObject.y = 0; // Límite superior
		rebote(_direccion, ChoqueBorde::ARRIBA);
	}
	if (bodyObject->y + bodyObject->h > 600) {
		//bodyObject.y = 600 - bodyObject.h; // Límite inferior
		rebote(_direccion, ChoqueBorde::ABAJO);

	}
}	