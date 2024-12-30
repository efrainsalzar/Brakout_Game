#pragma once
#include "GameObject.h"
#include "Movimiento.h"
class Ball :
    public GameObject
{
private:
	Movimiento* movimiento;
	int speed;

	int dirX;
	int dirY;
	bool reboteH;
	bool reboteV;
	bool banderaColision;

public:
	Ball(int _x, int _y, int _width, int _height, int  _speed, SDL_Color _color);
	Ball();
	~Ball();

	void update() override;
	void render(SDL_Renderer* _renderer) override;
	void rebote(Side side);



	void handleInput(SDL_Event& _event) override {}
	std::string getName() const override { return "ball"; };

	GameObject::Side getCollisionSide(const SDL_Rect* other) const override;

	bool isCollision() const { return banderaColision; };
	void setCollision(bool _collision) { banderaColision = _collision; }


};
