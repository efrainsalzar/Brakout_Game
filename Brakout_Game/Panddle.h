#pragma once

#include "GameObject.h"
class Panddle :
    public GameObject
{
private:
    int speed;
    //int direction;
    int lives;

    SDL_Color color;     
    //SDL_Texture* panddleTexture;

public:
    // Constructor y destructor
    Panddle(int _x, int _y, int _width, int _height, int _speed, int lives, SDL_Color _color);
    ~Panddle();

    // Métodos principales
    void update() override;              // Actualiza la posición basada en la entrada del usuario
    void render(SDL_Renderer* _renderer) override;         // Dibuja la barra en pantalla
};

