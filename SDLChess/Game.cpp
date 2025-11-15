#include "Game.h"

void Game::Run()
{

	SDL_Init(SDL_INIT_VIDEO);
	Board board;

	isRunning = true;

	while (isRunning) {

		SDL_Event event;

		while (SDL_PollEvent(&event)) {

			ProcessEvent(event, board);

		}

		board.Draw();
		
	}

	SDL_Quit();
	
}

void Game::ProcessEvent(SDL_Event& event, Board& board) {

	if (event.type == SDL_MOUSEBUTTONDOWN) {

		board.OnInteractionStarted();
	}

	else if (event.type == SDL_MOUSEBUTTONUP) {

		board.OnInteractionEnded();
		board.currentPiece = nullptr;

	}

	//else if (event.key.keysym.sym == SDLK_q) { //quit game

	//	isRunning = false;

	//}
}

