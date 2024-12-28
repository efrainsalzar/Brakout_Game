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

public:
	Ball(int _x, int _y, int _width, int _height, int  _speed, SDL_Color _color);
	Ball();
	~Ball();

	void update() override;
	void render(SDL_Renderer* _renderer) override;
	void handleInput(SDL_Event& _event) override {}
	std::string getName() const override { return "ball"; };

	void rebote(bool _invertX, bool _invertY);
};
