#pragma once
#include "GameObject.h" // Aseg�rate de que esta clase est� definida correctamente
#include <iostream>
#include "Ball.h"
class CollisionManager
{
private:
    static bool isColision;
public:

    // M�todo est�tico para verificar la colisi�n entre dos objetos
     static bool checkCollision(const GameObject* a, const GameObject* b);

    // Manejar la colisi�n entre dos objetos (puedes personalizar esto)
     static void handleCollision(const GameObject* a, const GameObject* b);


     static bool isCollision();
     static void resetCollision();
     static void setCollision( bool _isColision);
};

