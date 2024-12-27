#pragma once
#include "GameObject.h" // Asegúrate de que esta clase esté definida correctamente
#include <iostream>
#include "Panddle.h"
#include "Ball.h"
#include "Movimiento.h"
class CollisionManager
{
private:
	Ball* ball;
	Panddle* panddle;
    Movimiento* movimiento;

    bool collisionY;
	bool collisionX;
public:

    // Método estático para verificar la colisión entre dos objetos
     bool checkCollision(const GameObject* a, const GameObject* b);

    // Manejar la colisión entre dos objetos (puedes personalizar esto)
     void handleCollision(const GameObject* a, const GameObject* b);
     
     using Direccion = Movimiento::Direccion;
};

