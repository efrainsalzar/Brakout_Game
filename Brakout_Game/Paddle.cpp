#include "Paddle.h"

Paddle::Paddle(int _x, int _y, int _width, int _height, SDL_Color _color, int _speed, int _lives) :
    GameObject(_x, _y, _width, _height, _color),
    speed(_speed),
    lives(_lives)
{
    movimiento = new Movimiento(bodyObject);
}

Paddle::Paddle():
    GameObject(400,         // Posición en X
    500,                    // Posición en Y
    100,                    // Ancho
    10,                     // Alto
    { 42, 255, 100, 255 }), // Color (RGBA)
    lives(3),               // Inicializa el número de vidas
    speed(5)

{
	movimiento = new Movimiento(bodyObject);
}

Paddle::~Paddle() {
    // Si fuera necesario, liberar recursos aquí
}

void Paddle::update() {

    movimiento->moverPaddle(currentKeyStates, speed);
    movimiento->validarLimites();

}

void Paddle::render(SDL_Renderer* _renderer) {
    // Dibuja la barra en pantalla con el color especificado
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a); // Usar el color de la barra
    SDL_RenderFillRect(_renderer, bodyObject); // Dibuja el rectángulo
}
void Paddle::handleInput(SDL_Event& _event) {
    //if (_event.type == SDL_KEYDOWN) {
    //    switch (_event.key.keysym.sym) {
    //    case SDLK_LEFT:
    //        movimiento->mover(Movimiento::Direccion::IZQUIERDA, speed);
    //        break;
    //    case SDLK_RIGHT:
    //        movimiento->mover(Movimiento::Direccion::DERECHA, speed);
    //        break;
    //    }
    //}
}

GameObject::Side Paddle::getCollisionSide(const SDL_Rect* other) const {

    return Side::NONE;
}
