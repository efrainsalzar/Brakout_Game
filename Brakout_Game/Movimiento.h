#pragma once
#include <SDL.h>

#include "Window.h"
class Movimiento
{
private:
	SDL_Rect* bodyObject;
	Window* window;

public:
	Movimiento(SDL_Rect* _bodyObjaect);
	~Movimiento();


	enum class Direccion
	{
		ARRIBA,
		ABAJO,
		IZQUIERDA,
		DERECHA,
	};

	enum class ChoqueBorde
	{
		HORIZONTAL_BORDES,
		VERTICAL_BORDES
	};

	
	void moverPaddle(const Uint8* currentKeyStates, int _speed);
	void validarLimites();
	void validarLimitesBall(bool& _bordeH, bool& _bordeV);
	void moverBall(int dirX, int dirY, int speed);


};

