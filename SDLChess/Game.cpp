#include "Game.h"
#include "Board.h"

void Game::Run()
{

	SDL_Init(SDL_INIT_VIDEO);
	Board board;

	bool isRunning = true;

	while (isRunning) {

		board.Draw();

		SDL_Event event;

		while (SDL_PollEvent(&event)) {

			ProcessEvent(event);

		}
		

	}

	SDL_Quit();
	

}

void Game::ProcessEvent(SDL_Event& event) {

	if (event.type == SDL_MOUSEBUTTONDOWN) {

		

	}

}

