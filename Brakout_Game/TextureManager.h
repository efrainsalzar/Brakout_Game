#pragma once
#include <SDL.h>
#include <string>
class TextureManager
{
private:
    SDL_Texture* texture;  // Puntero a la textura de SDL
    int width, height;

public:
    TextureManager();  // Constructor
    ~TextureManager();  // Destructor

    bool loadFromFile(const std::string& path, SDL_Renderer* renderer);  // Cargar textura
    void free();  // Liberar textura
    void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = nullptr);  // Renderizar textura

    int getWidth() const;  // Obtener ancho
    int getHeight() const;  // Obtener altura
};

