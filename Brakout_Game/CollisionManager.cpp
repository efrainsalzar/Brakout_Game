#include "CollisionManager.h"

bool CollisionManager::checkCollision(const GameObject* a, const GameObject* b) {
	if (a->getX() + a->getWidth() > b->getX() && a->getX() < b->getX() + b->getWidth() &&
		a->getY() + a->getHeight() > b->getY() && a->getY() < b->getY() + b->getHeight()) {
		return true;
	}
	return false;


	//bool collisionX = a->getX() + a->getWidth() > b->getX() && a->getX() < b->getX() + b->getWidth();
	//bool collisionY = a->getY() + a->getHeight() > b->getY() && a->getY() < b->getY() + b->getHeight();
	//return collisionX && collisionY;
}

void CollisionManager::handleCollision(const GameObject* a, const GameObject* b) {
	// Manejar la colisión entre los objetos a y b
	// Aquí puedes personalizar la lógica de colisión
	//std::cout << "Colisión detectada" << std::endl;
	// Por ejemplo,
}