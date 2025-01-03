#pragma once
#include "GameObject.h"
class Brick :
    public GameObject
{
private:
    bool isDestroyed;
public:
    // Constructor y destructor
    Brick(int _x, int _y, int _width, int _height, SDL_Color _color);
    Brick();
    ~Brick();

    // Métodos principales
    void update() override;                                
    void render(SDL_Renderer* _renderer) override;         
    void handleInput(SDL_Event& _event) override;
    void handleCollision(Side* _side) override;


    void setPosition(int _x, int _y);
    void setSize(int _width, int _height);

    bool getIsDestroyed() override { return isDestroyed; }
};

