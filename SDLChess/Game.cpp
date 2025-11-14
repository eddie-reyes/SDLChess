#include "Game.h"
#include <iostream>

void Game::Run()
{

	SDL_Init(SDL_INIT_VIDEO);
	Board board;

	bool isRunning = true;

	while (isRunning) {

		board.Draw();

		SDL_Event event;

		while (SDL_PollEvent(&event)) {

			ProcessEvent(event, board);

		}
		
	}

	SDL_Quit();
	

}

void Game::ProcessEvent(SDL_Event& event, Board& board) {

	if (event.type == SDL_MOUSEBUTTONDOWN) {

		board.OnInteractionStarted();
	}

	if (event.type == SDL_MOUSEBUTTONUP) {

		board.OnInteractionEnded();

	}

}

