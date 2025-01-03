#include "CollisionManager.h"

bool CollisionManager::isColision = false;

bool CollisionManager::checkCollision(GameObject* a, GameObject* b) {
    SDL_Rect rectA = { a->getX(), a->getY(), a->getWidth(), a->getHeight() };
    SDL_Rect rectB = { b->getX(), b->getY(), b->getWidth(), b->getHeight() };

    if (SDL_HasIntersection(&rectA, &rectB)) {

        return true;
    }
    resetCollision();
    return false;
}


void CollisionManager::handleCollision(GameObject* a, GameObject* b) {

    if (!isCollision()) {
        SDL_Rect rectA = { a->getX(), a->getY(), a->getWidth(), a->getHeight() };
        SDL_Rect rectB = { b->getX(), b->getY(), b->getWidth(), b->getHeight() };

        
        // Calcular los bordes de ambos rectángulos
        int deltaX = (rectA.x + rectA.w / 2) - (rectB.x + rectB.w / 2);
        int deltaY = (rectA.y + rectA.h / 2) - (rectB.y + rectB.h / 2);
        int width = (rectA.w + rectB.w) / 2;
        int height = (rectA.h + rectB.h) / 2;
        int crossX = width * deltaY;
        int crossY = height * deltaX;

        // Crear un puntero para guardar el lado de la colisión
        GameObject::Side* side = nullptr;  // Inicializamos con nullptr

        if (abs(crossX) < abs(crossY)) {
            if (crossX < 0) {
               // std::cout << "Colisión en el lado derecho de A." << std::endl;
            side = new GameObject::Side(GameObject::Side::RIGHT);  // Asignar el lado derecho usando puntero
            }
            else {
                //std::cout << "Colisión en el lado izquierdo de A." << std::endl;
            side = new GameObject::Side(GameObject::Side::LEFT);  // Asignar el lado izquierdo usando puntero
            }
        }
        else {
            if (crossY < 0) {
               // std::cout << "Colisión en el lado inferior de A." << std::endl;
            side = new GameObject::Side(GameObject::Side::BOTTOM);  // Asignar el lado inferior usando puntero
            }
            else {
                //std::cout << "Colisión en el lado superior de A." << std::endl;
                side = new GameObject::Side(GameObject::Side::TOP);  // Asignar el lado superior usando puntero
            }
        }
        
        a->handleCollision(side);
        b->handleCollision(side);

        setCollision(true);
    }
    
}

bool CollisionManager::isCollision() {
    return isColision;
}

void CollisionManager::setCollision(bool _isColision) {
    isColision = _isColision;
}

void CollisionManager::resetCollision() {
    isColision = false;
}
