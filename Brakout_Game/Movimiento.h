#pragma once
#include <SDL.h>
class Movimiento
{
private:
	SDL_Rect* bodyObject;
public:
	Movimiento(SDL_Rect* _bodyObjaect);
	~Movimiento();

	enum class Direccion
	{
		ARRIBA,
		ABAJO,
		IZQUIERDA,
		DERECHA,
		DIAGONAL_ARRIBA_IZQUIERDA,
		DIAGONAL_ARRIBA_DERECHA,
		DIAGONAL_ABAJO_IZQUIERDA,
		DIAGONAL_ABAJO_DERECHA
	};

	void mover(Direccion direccion, int _speed);

};

