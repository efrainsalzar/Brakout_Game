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

	bool isDestroyed;
	bool isAttachedToPaddle;

	const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);

public:
	Ball(int _x, int _y, int _width, int _height, int  _speed, SDL_Color _color);
	Ball();
	~Ball();

	void update() override;
	void render(SDL_Renderer* _renderer) override;
	void handleInput(SDL_Event& _event) override;
	void handleCollision(Side* _side) override;

	void attachToPaddle(GameObject* paddle);

	void rebote(Side side);
	bool isCollision() const { return banderaColision; };
	void setCollision(bool _collision) { banderaColision = _collision; }

	bool getIsDestroyed() override { return isDestroyed; }
};
