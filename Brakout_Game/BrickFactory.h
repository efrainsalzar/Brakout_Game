#pragma once
#include "Brick.h"
#include <vector>
#include "Window.h"

class BrickFactory {
public:
    static void createBricks(std::vector<GameObject*>& _object) {
		Window* window = Window::getInstance();
        // Tamaño de los ladrillos
        int brickWidth = 30;  // Ancho de cada ladrillo
        int brickHeight = 15; // Alto de cada ladrillo
        int spacing = 1;      // Espaciado entre ladrillos

        // Obtener el ancho y alto de la pantalla
        int screenWidth = window->getScreenWidth();
        int screenHeight = window->getScreenHeight();

        // Calcular el número de columnas y filas necesarias
        int cols = screenWidth / (brickWidth + spacing);
        int rows = 11; // Usar la mitad de la altura de la pantalla

        // Crear los ladrillos y organizarlos con un espaciado de 5 px entre ellos
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int x = col * (brickWidth + spacing);  // Posición X del ladrillo
                int y = row * (brickHeight + spacing); // Posición Y del ladrillo

                // Asignar un color diferente a cada fila
                SDL_Color color;
                switch (row % 6) {
                    case 0: color = { 255, 0, 0, 255 }; break; // Rojo
                    case 1: color = { 255, 165, 0, 255 }; break; // Naranja
                    case 2: color = { 255, 255, 0, 255 }; break; // Amarillo
                    case 3: color = { 0, 128, 0, 255 }; break; // Verde
                    case 4: color = { 0, 0, 255, 255 }; break; // Azul
                    case 5: color = { 75, 0, 130, 255 }; break; // Índigo
                    default: color = { 220, 26, 218, 255 }; break; // Color predeterminado
                }

                _object.push_back(new Brick(x, y, brickWidth, brickHeight, color));
            }
        }
    }
};
