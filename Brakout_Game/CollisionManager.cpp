#include "CollisionManager.h"

bool CollisionManager::checkCollision(const GameObject* a, const GameObject* b) {
	if (a->getX() + a->getWidth() > b->getX() && a->getX() < b->getX() + b->getWidth() &&
		a->getY() + a->getHeight() > b->getY() && a->getY() < b->getY() + b->getHeight()) {
		//std::cout << " colision" << std::endl;
		return true;
	}
	return false;

}

void CollisionManager::handleCollision(const GameObject* a, const GameObject* b) {
    Ball* ball = nullptr;
    // Verificamos si la colisi�n es entre la pelota y el paddle
    if (a->getName() == "ball" && b->getName() == "paddle") {
        ball = (Ball*)a;  // Usamos casting para acceder al objeto Ball
    }else{
        ball = (Ball*)b;  // Usamos casting para acceder al objeto Ball
    }
    // Si se encontr� un objeto Ball, llamamos a su m�todo de colisi�n
    if (ball != nullptr) {
        ball->rebote(false, true);  // Llamamos al m�todo espec�fico de la Ball
    }
}

