#pragma once

#include "GameObject.h"
#include "Movimiento.h"

class Paddle :
    public GameObject
{
private:
    int lives;
    int speed;
    Movimiento* movimiento;

    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);

public:
    // Constructor y destructor
    Paddle(int _x, int _y, int _width, int _height, SDL_Color _color, int _speed, int lives);
    Paddle();
    ~Paddle();

    // Métodos principales
    void update() override;                                // Actualiza la posición basada en la entrada del usuario
    void render(SDL_Renderer* _renderer) override;         // Dibuja la barra en pantalla
    void handleInput(SDL_Event& _event) override;
    std::string getName() const override { return "paddle"; };
};

