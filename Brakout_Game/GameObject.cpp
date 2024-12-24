#include "GameObject.h"
GameObject::GameObject(int _x, int _y, int _width, int _height) :
	x(_x),
	y(_y),
	width(_width),
	height(_height),
	bodyObject{_x, _y, _width, _height } {
}

GameObject::~GameObject() {
}