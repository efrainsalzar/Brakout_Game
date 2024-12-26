#pragma once
#include "GameObject.h" // Asegúrate de que esta clase esté definida correctamente
class CollisionManager
{
public:
    // Método estático para verificar la colisión entre dos objetos
     bool checkCollision(const GameObject* a, const GameObject* b);

    // Manejar la colisión entre dos objetos (puedes personalizar esto)
     void handleCollision(const GameObject* a, const GameObject* b);
};

