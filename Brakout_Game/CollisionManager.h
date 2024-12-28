#pragma once
#include "GameObject.h" // Aseg�rate de que esta clase est� definida correctamente
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
class CollisionManager
{
private:
    
public:

    // M�todo est�tico para verificar la colisi�n entre dos objetos
     static bool checkCollision(const GameObject* a, const GameObject* b);

    // Manejar la colisi�n entre dos objetos (puedes personalizar esto)
     static void handleCollision(const GameObject* a, const GameObject* b);


     void collisionBall_Paddle();
     void collisionBall_Brick();

};

