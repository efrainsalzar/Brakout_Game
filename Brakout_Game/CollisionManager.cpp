#include "CollisionManager.h"

bool CollisionManager::isColision = false;

bool CollisionManager::checkCollision(const GameObject* a, const GameObject* b) {
    if (a->getX() + a->getWidth() > b->getX() &&  // A derecha > B izquierda
        a->getX() < b->getX() + b->getWidth() &&  // A izquierda < B derecha
        a->getY() + a->getHeight() > b->getY() && // A abajo > B arriba
        a->getY() < b->getY() + b->getHeight())   // A arriba < B abajo
    {
        return true;
    }
    resetCollision();
    return false;
}

void CollisionManager::handleCollision(const GameObject* a, const GameObject* b) {
    Ball* ball = (Ball*)b;
    if (!isCollision()) {
        std::cout << "Colisión detectada entre " << a->getName() << " y " << b->getName() << std::endl;

        ball->rebote(GameObject::Side::BOTTOM);
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
