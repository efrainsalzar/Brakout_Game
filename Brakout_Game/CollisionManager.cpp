#include "CollisionManager.h"

bool CollisionManager::checkCollision(const GameObject* a, const GameObject* b) {
	if (a->getX() + a->getWidth() > b->getX() && a->getX() < b->getX() + b->getWidth() &&
		a->getY() + a->getHeight() > b->getY() && a->getY() < b->getY() + b->getHeight()) {
		/*ball->rebote(Direccion::DIAGONAL_ABAJO_DERECHA, Ball::Choque::ABAJO);*/
		return true;
	}
	return false;

}

void CollisionManager::handleCollision(const GameObject* a, const GameObject* b) {
	//Movimiento::Direccion dir1 = Movimiento::Direccion::DIAGONAL_ABAJO_DERECHA;
	//Movimiento::ChoqueBorde dir2 = Movimiento::ChoqueBorde::ABAJO;
	//movimiento->rebote(dir1, dir2);
}
