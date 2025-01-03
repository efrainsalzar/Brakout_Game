# Breakout Game 🎮

¡Bienvenido a mi implementación básica del clásico juego Breakout! Este proyecto utiliza **SDL2** para manejar gráficos y entrada, y está diseñado para ser una introducción a la programación de videojuegos.

## 🎯 Objetivo del juego

El objetivo del juego es controlar una barra para golpear una bola y romper todos los ladrillos en la pantalla. Si la bola cae fuera de la pantalla, pierdes una vida. Gana el juego rompiendo todos los ladrillos.

---

## 🛠️ Tecnologías utilizadas

- **C++**: Lenguaje principal del proyecto.
- **SDL2**: Biblioteca para gráficos 2D, entrada del usuario y control del tiempo.
- **Visual Studio** (u otro IDE): Para escribir y compilar el código.

---

## 🚀 Instalación y configuración

### Prerrequisitos

Antes de comenzar, asegúrate de tener instalados:

1. Un compilador que soporte C++11 o superior.
2. La biblioteca **SDL2** y las librerías necesarias:
   - SDL2
   - SDL2_image (opcional, si planeas usar texturas)
   - SDL2_ttf (opcional, si agregas texto al juego)
3. Una herramienta de compilación como `Make`, `CMake` o un IDE como Visual Studio o Code::Blocks.

### Pasos de instalación

1. **Clona el repositorio**:
   ```bash
   git clone https://github.com/efrainsalzar/Breakout_Game.git
   cd breakout-sdl
   ```

2. **Instala las dependencias**:
   - En Windows, descarga y configura SDL2 desde [SDL2 Download](https://www.libsdl.org/).

3. **Compila el proyecto**:
   - Si usas un IDE, abre el proyecto y compílalo.
   - Si usas la terminal, compila el proyecto con un comando similar:
     ```bash
     g++ -o breakout main.cpp -lSDL2
     ```

4. **Ejecuta el juego**:
   ```bash
   ./breakout
   ```

---

## 🕹️ Controles del juego

- **← / →**: Mover la barra hacia la izquierda o derecha.
- **Espacio**: Liberar la bola para iniciar el juego.
- **Esc**: Salir del juego.

---

## ✨ Funcionalidades actuales

- [x] Bola que rebota y destruye ladrillos.
- [x] Colisiones con los bordes, barra y ladrillos.
- [x] Termina el juego si la bola cae fuera de la pantalla.
- [ ] Mejora del diseño con texturas y efectos.
- [ ] Sistema de puntuación.

---

## 🤝 Contribuciones

¡Contribuciones son bienvenidas! Si encuentras un problema o tienes una idea para mejorar el proyecto, por favor crea un **issue** o envía un **pull request**.

---

## 🖍️ Licencia

Este proyecto está licenciado bajo la [MIT License](LICENSE). Siéntete libre de usarlo y modificarlo.

