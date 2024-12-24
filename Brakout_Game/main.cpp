#include <iostream>
#include "Game.h"


int main(int argc, char* argv[]) {

	Game game;

	if (!game.init("Breackout", 800, 600)) {
		return -1;
	}

	while (game.isRunning()) {
		game.handleEvents();
		game.update();
		game.render();

		SDL_Delay(10);
	}

	

	return 0;
}