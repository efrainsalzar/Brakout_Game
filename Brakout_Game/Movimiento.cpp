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