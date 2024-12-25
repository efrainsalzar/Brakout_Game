#pragma once

#include "GameObject.h"
#include "Movimiento.h"

class Panddle :
    public GameObject
{
private:
    int lives;

    Movimiento* movimiento;

public:
    // Constructor y destructor
    Panddle(int _x, int _y, int _width, int _height, int _speed, SDL_Color _color, int lives);
    Panddle();
    ~Panddle();

    // Métodos principales
    void update() override;                                // Actualiza la posición basada en la entrada del usuario
    void render(SDL_Renderer* _renderer) override;         // Dibuja la barra en pantalla
};

