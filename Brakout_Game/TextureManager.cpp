#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager() : texture(nullptr), width(0), height(0) {}

TextureManager::~TextureManager() {
    free();  // Liberar la textura si fue cargada
}

bool TextureManager::loadFromFile(const std::string& path, SDL_Renderer* renderer) {
    // Liberar cualquier textura previamente cargada
    free();

    // Crear la textura directamente desde el archivo
    texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP(path.c_str()));
    if (texture == nullptr) {
        std::cerr << "Unable to create texture from " << path << " SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Obtener las dimensiones de la imagen directamente desde la textura
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    return true;
}

void TextureManager::free() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = 0;
        height = 0;
    }
}

void TextureManager::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip) {
    SDL_Rect renderQuad = { x, y, width, height };

    // Si se pasa un clip, ajustamos la textura renderizada
    if (clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    // Renderizar la textura
    SDL_RenderCopy(renderer, texture, clip, &renderQuad);
}

int TextureManager::getWidth() const {
    return width;
}

int TextureManager::getHeight() const {
    return height;
}
