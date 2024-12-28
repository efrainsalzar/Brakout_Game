#pragma once
#include "GameObject.h" // Asegúrate de que esta clase esté definida correctamente
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
class CollisionManager
{
private:
    
public:

    // Método estático para verificar la colisión entre dos objetos
     static bool checkCollision(const GameObject* a, const GameObject* b);

    // Manejar la colisión entre dos objetos (puedes personalizar esto)
     static void handleCollision(const GameObject* a, const GameObject* b);


     void collisionBall_Paddle();
     void collisionBall_Brick();

};

