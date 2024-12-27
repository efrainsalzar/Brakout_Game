#include "Ball.h"

Ball::Ball(int _x, int _y, int _width, int _height, int _speed, SDL_Color _color) :
	GameObject(_x, _y, _width, _height, _speed, _color)
{
	movimiento = new Movimiento(bodyObject);
}

Ball::Ball() :
	GameObject(400, // Posición x
		300, // Posición y
		15, // Ancho
		15, // Alto
		2, // Velocidad
		{ 255, 255, 255, 255 }) // Color 
{
	
	movimiento = new Movimiento(bodyObject);
	direccion = Movimiento::Direccion::DIAGONAL_ARRIBA_DERECHA;
}

Ball::~Ball() {
	// Si fuera necesario, liberar recursos aquí
	delete movimiento;
}

void Ball::update() {
	// Aquí irá la lógica de la bola
	movimiento->mover(direccion, speed);

	movimiento->validarLimites(direccion);
	//// Verificar los límites de la pantalla
	//if (bodyObject->x < 0) {
	//	//bodyObject.x = 0; // Límite izquierdo
	//	movimiento->rebote(direccion, Movimiento::ChoqueBorde::IZQUIERDA);
	//}
	//if (bodyObject->x + bodyObject->w > 800) {
	//	//bodyObject.x = 800 - bodyObject.w; // Límite derecho
	//	movimiento->rebote(direccion, Movimiento::ChoqueBorde::DERECHA);
	//}
	//if (bodyObject->y < 0) {
	//	//bodyObject.y = 0; // Límite superior
	//	movimiento->rebote(direccion, Movimiento::ChoqueBorde::ARRIBA);
	//}
	//if (bodyObject->y + bodyObject->h > 600) {
	//	//bodyObject.y = 600 - bodyObject.h; // Límite inferior
	//	movimiento->rebote(direccion, Movimiento::ChoqueBorde::ABAJO);

	//}
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
