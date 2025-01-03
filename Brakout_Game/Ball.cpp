#include "Ball.h"

Ball::Ball(int _x, int _y, int _width, int _height, int _speed, SDL_Color _color) :
	GameObject(_x, _y, _width, _height, _color),
	speed(_speed),
	dirX(1),
	dirY(-1),
	reboteH(false),
	reboteV(false),
	isAttachedToPaddle(true),
	banderaColision(false)
{
	movimiento = new Movimiento(bodyObject);
}

Ball::Ball() :
	GameObject(300,				// Posición x
		300,					// Posición y
		10,						// Ancho
		10,						// Alto
		{ 255, 255, 255, 255 }),// Color 
	speed(2),
	dirX(1),
	dirY(-1),
	reboteH(false),
	reboteV(false),
	isAttachedToPaddle(true),
	banderaColision(false)
{
	movimiento = new Movimiento(bodyObject);
}

Ball::~Ball() {
	// Si fuera necesario, liberar recursos aquí
	delete movimiento;
}

void Ball::update() {
	if (isAttachedToPaddle) {
		// Mantener la bola encima de la barra (posición ajustable)
		movimiento->moverPaddle(currentKeyStates, 5);
		return;
	}

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
	SDL_RenderFillRect(_renderer, bodyObject); // Dibuja el rectángulo
}

void Ball::handleInput(SDL_Event& _event)
{
	if (isAttachedToPaddle && _event.type == SDL_KEYDOWN && _event.key.keysym.sym == SDLK_SPACE) {
		// Liberar la bola al presionar la barra espaciadora
		isAttachedToPaddle = false;
	}
}

void Ball::rebote(Side side) {

	switch (side) {
	case Side::LEFT:
	case Side::RIGHT:
		dirX = -dirX;  // Cambiar la dirección horizontal cuando colisiona con los lados
		break;
	case Side::TOP:
	case Side::BOTTOM:
		dirY = -dirY;  // Cambiar la dirección vertical cuando colisiona con la parte superior o inferior
		break;
	default:
		break;
	}
}

void Ball::handleCollision(Side* _side)
{
	//_side = nullptr;
	rebote(*_side);
}

void Ball::attachToPaddle(GameObject* paddle)
{
	// Ajustar la posición de la bola para que quede encima de la barra
	bodyObject->x = paddle->getX() + (paddle->getWidth() - getWidth()) / 2;
	bodyObject->y = paddle->getY() - getHeight();
	isAttachedToPaddle = true;
}
