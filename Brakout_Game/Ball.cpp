#include "Ball.h"

Ball::Ball(int _x, int _y, int _width, int _height, int _speed, SDL_Color _color) :
	GameObject(_x, _y, _width, _height, _color)
{
	movimiento = new Movimiento(bodyObject);
}

Ball::Ball() :
	GameObject(200,				// Posici�n x
		200,					// Posici�n y
		15,						// Ancho
		15,						// Alto
		{ 255, 255, 255, 255 }),// Color 
	speed(2),
	dirX(1),
	dirY(-1),
	reboteH(false),
	reboteV(false),
	banderaColision(false)
{
	movimiento = new Movimiento(bodyObject);
}

Ball::~Ball() {
	// Si fuera necesario, liberar recursos aqu�
	delete movimiento;
}

void Ball::update() {

	movimiento->moverBall(dirX, dirY, speed);
	movimiento->validarLimitesBall(reboteH, reboteV);

	if (reboteH) {
		rebote(Side::LEFT);  // Llamar con Side::LEFT para el rebote horizontal
	}
	if (reboteV) {
		rebote(Side::TOP);  // Llamar con Side::TOP para el rebote vertical
	}

}

void Ball::render(SDL_Renderer* _renderer) {
	// Dibuja la bola en pantalla con el color especificado
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a); // Usar el color de la bola
	SDL_RenderFillRect(_renderer, bodyObject); // Dibuja el rect�ngulo
}

void Ball::rebote(Side side) {

	switch (side) {
	case Side::LEFT:
	case Side::RIGHT:
		dirX = -dirX;  // Cambiar la direcci�n horizontal cuando colisiona con los lados
		break;
	case Side::TOP:
	case Side::BOTTOM:
		dirY = -dirY;  // Cambiar la direcci�n vertical cuando colisiona con la parte superior o inferior
		break;
	default:
		break;
	}
}

GameObject::Side Ball::getCollisionSide(const SDL_Rect* other) const {
	return Side::NONE;
}