#include "Panddle.h"

Panddle::Panddle(int _x, int _y, int _width, int _height, int _speed, int _lives, SDL_Color _color) :
    GameObject(_x, _y, _width, _height), 
    speed(_speed), 
    lives(_lives), 
    color(_color)
{
    // El constructor ya maneja la inicialización de los valores pasados como parámetros
}

Panddle::~Panddle() {
    // Si fuera necesario, liberar recursos aquí
}

void Panddle::update() {
    // Actualiza la posición basada en la entrada del usuario
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_LEFT]) // Mover hacia la izquierda
        x -= speed;
    if (currentKeyStates[SDL_SCANCODE_RIGHT]) // Mover hacia la derecha
        x += speed;

    // Limitar el movimiento para que no salga de la pantalla
    if (x < 0)
        x = 0;
    if (x + width > 800) // Supongamos que el ancho de la ventana es 800
        x = 800 - width;

    // Actualizamos el rectángulo del cuerpo
    bodyObject = { x, y, width, height };
}

void Panddle::render(SDL_Renderer* _renderer) {
    // Dibuja la barra en pantalla con el color especificado
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a); // Usar el color de la barra
    SDL_RenderFillRect(_renderer, &bodyObject); // Dibuja el rectángulo
}
