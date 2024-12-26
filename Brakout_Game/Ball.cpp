#include "Ball.h"

Ball::Ball(int _x, int _y, int _width, int _height, int _speed, SDL_Color _color) :
	GameObject(_x, _y, _width, _height, _speed, _color)
{
	movimiento = new Movimiento(bodyObject);
}

Ball::Ball() :
	GameObject(400, // Posición x
		300, // Posición y
		20, // Ancho
		20, // Alto
		2, // Velocidad
		{ 255, 255, 255, 255 }) // Color 
{
	
	movimiento = new Movimiento(bodyObject);

	direccion = Movimiento::Direccion::DIAGONAL_ABAJO_DERECHA;
}

Ball::~Ball() {
	// Si fuera necesario, liberar recursos aquí
	delete movimiento;
}

void Ball::update() {
	// Aquí irá la lógica de la bola
	movimiento->mover(direccion, speed);
	// Verificar los límites de la pantalla
	if (bodyObject->x < 0) {
		//bodyObject.x = 0; // Límite izquierdo
		rebote(direccion,Choque::IZQUIERDA);
	}
	if (bodyObject->x + bodyObject->w > 800) {
		//bodyObject.x = 800 - bodyObject.w; // Límite derecho
		rebote(direccion, Choque::DERECHA);
	}
	if (bodyObject->y < 0) {
		//bodyObject.y = 0; // Límite superior
		rebote(direccion, Choque::ARRIBA);
	}
	if (bodyObject->y + bodyObject->h > 600) {
		//bodyObject.y = 600 - bodyObject.h; // Límite inferior
		rebote(direccion, Choque::ABAJO);

	}

}

void Ball::render(SDL_Renderer* _renderer) {
	// Dibuja la bola en pantalla con el color especificado
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a); // Usar el color de la bola


	SDL_RenderFillRect(_renderer, bodyObject); // Dibuja el rectángulo
}

//void Ball::drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, SDL_Color color) {
//	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
//	for (int w = 0; w < radius * 2; w++) {
//		for (int h = 0; h < radius * 2; h++) {
//			int dx = radius - w; // Distancia horizontal al centro
//			int dy = radius - h; // Distancia vertical al centro
//			if ((dx * dx + dy * dy) <= (radius * radius)) {
//				SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
//			}
//		}
//	}
//}


void Ball::rebote(Movimiento::Direccion _direccion, Choque _choque) {

	switch (_direccion) {
	case Movimiento::Direccion::DIAGONAL_ABAJO_IZQUIERDA:
		if (_choque == Choque::ABAJO) {
			direccion = Movimiento::Direccion::DIAGONAL_ARRIBA_IZQUIERDA;
		}
		else if (_choque == Choque::IZQUIERDA) {
			direccion = Movimiento::Direccion::DIAGONAL_ABAJO_DERECHA;
		}
		break;
	case Movimiento::Direccion::DIAGONAL_ABAJO_DERECHA:
		if (_choque == Choque::ABAJO) {
			direccion = Movimiento::Direccion::DIAGONAL_ARRIBA_DERECHA;
		}
		else if (_choque == Choque::DERECHA) {
			direccion = Movimiento::Direccion::DIAGONAL_ABAJO_IZQUIERDA;
		}
		break;
	case Movimiento::Direccion::DIAGONAL_ARRIBA_IZQUIERDA:
		if (_choque == Choque::ARRIBA) {
			direccion = Movimiento::Direccion::DIAGONAL_ABAJO_IZQUIERDA;
		}
		else if (_choque == Choque::IZQUIERDA) {
			direccion = Movimiento::Direccion::DIAGONAL_ARRIBA_DERECHA;
		}
		break;
	case Movimiento::Direccion::DIAGONAL_ARRIBA_DERECHA:
		if (_choque == Choque::ARRIBA) {
			direccion = Movimiento::Direccion::DIAGONAL_ABAJO_DERECHA;
		}
		else if (_choque == Choque::DERECHA) {
			direccion = Movimiento::Direccion::DIAGONAL_ARRIBA_IZQUIERDA;
		}
		break;
	}
}