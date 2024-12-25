#include "GameObject.h"
GameObject::GameObject(int _x, int _y, int _width, int _height, int _speed, SDL_Color _color) :
	x(_x),
	y(_y),
	width(_width),
	height(_height),
	speed(_speed),
	color(_color),
	bodyObject{_x, _y, _width, _height } {
}

GameObject::~GameObject() {
}