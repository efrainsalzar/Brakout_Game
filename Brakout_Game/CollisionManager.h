#pragma once
#include "GameObject.h" // Asegúrate de que esta clase esté definida correctamente
#include <iostream>
#include "Ball.h"
#include "Brick.h"

class CollisionManager
{
private:
    static bool isColision;
public:

    // Método estático para verificar la colisión entre dos objetos
     static bool checkCollision(GameObject* a, GameObject* b);

    // Manejar la colisión entre dos objetos (puedes personalizar esto)
     static void handleCollision(GameObject* a, GameObject* b);


     static bool isCollision();
     static void resetCollision();
     static void setCollision( bool _isColision);
};

