#include "Panddle.h"

Panddle::Panddle(int _x, int _y, int _width, int _height, int _speed, SDL_Color _color, int _lives) :
    GameObject(_x, _y, _width, _height,_speed, _color),
    lives(_lives)
    
{
    // El constructor ya maneja la inicialización de los valores pasados como parámetros
    movimiento = new Movimiento(bodyObject);
}

Panddle::Panddle():

	GameObject(400, 500, 100, 20, 5, { 42, 255, 100, 255 }),
	lives(3)
{
	// El constructor ya maneja la inicialización de los valores pasados como parámetros
	movimiento = new Movimiento(bodyObject);
}

Panddle::~Panddle() {
    // Si fuera necesario, liberar recursos aquí
}

void Panddle::update() {
    // Manejar entrada del usuario
    const Uint8* state = SDL_GetKeyboardState(nullptr);

    if (state[SDL_SCANCODE_LEFT]) {
        movimiento->mover(Movimiento::Direccion::IZQUIERDA, speed);
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        movimiento->mover(Movimiento::Direccion::DERECHA,speed);
    }

    // Verificar los límites de la pantalla
    if (bodyObject->x < 0) {
        bodyObject->x = 0; // Límite izquierdo
    }
    if (bodyObject->x + bodyObject->w > 800) {
        bodyObject->x = 800 - bodyObject->w; // Límite derecho
    }
}

void Panddle::render(SDL_Renderer* _renderer) {
    // Dibuja la barra en pantalla con el color especificado
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a); // Usar el color de la barra
    SDL_RenderFillRect(_renderer, bodyObject); // Dibuja el rectángulo
}
