#pragma once
#include "GameObject.h" // Aseg�rate de que esta clase est� definida correctamente
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
#include "Movimiento.h"
class CollisionManager
{
private:
	Ball* ball;
	Paddle* panddle;
    Movimiento* movimiento;

    bool collisionY;
	bool collisionX;
public:

    // M�todo est�tico para verificar la colisi�n entre dos objetos
     bool checkCollision(const GameObject* a, const GameObject* b);

    // Manejar la colisi�n entre dos objetos (puedes personalizar esto)
     void handleCollision(const GameObject* a, const GameObject* b);
     
     using Direccion = Movimiento::Direccion;
};

