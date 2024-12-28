#include "Ball.h"

Ball::Ball(int _x, int _y, int _width, int _height, int _speed, SDL_Color _color) :
	GameObject(_x, _y, _width, _height, _color)
{
	movimiento = new Movimiento(bodyObject);
}

Ball::Ball() :
	GameObject(400,				// Posición x
		300,					// Posición y
		15,						// Ancho
		15,						// Alto
		{ 255, 255, 255, 255 }),// Color 
	speed(3),
	dirX(1),
	dirY(-1),
	reboteH(false),
	reboteV(false)
{
	movimiento = new Movimiento(bodyObject);
}

Ball::~Ball() {
	// Si fuera necesario, liberar recursos aquí
	delete movimiento;
}

void Ball::update() {

	movimiento->moverBall(dirX, dirY, speed);


	movimiento->validarLimitesBall(reboteH, reboteV);

	rebote(reboteH, reboteV);
}

void Ball::render(SDL_Renderer* _renderer) {
	// Dibuja la bola en pantalla con el color especificado
	SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a); // Usar el color de la bola
	SDL_RenderFillRect(_renderer, bodyObject); // Dibuja el rectángulo
}

void Ball::rebote(bool _invertX, bool _invertY) {
	if (_invertX) {
		dirX = -dirX; // Cambiar dirección horizontal
	}
	if (_invertY) {
		dirY = -dirY; // Cambiar dirección vertical
	}
}