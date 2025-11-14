#include "Board.h"


Board::Board()
{

	m_Window = SDL_CreateWindow("SDLChess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowSize, m_windowSize, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	SQUARE_SIZE = m_windowSize / 8;

	//pawns


	for (size_t i = 0; i < 8; i++) {

		m_Pieces[i][1] = new Pawn(Renderer, Team::BLACK_TEAM);
		m_Pieces[i][6] = new Pawn(Renderer, Team::WHITE_TEAM);

	}

	
};

Board::~Board() {

	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(m_Window);

}

void Board::Draw()
{
	
	SDL_SetRenderDrawColor(Renderer, 248, 231, 187, SDL_ALPHA_OPAQUE); //background color

	SDL_RenderClear(Renderer);

	SDL_SetRenderDrawColor(Renderer, 251, 245, 222, SDL_ALPHA_OPAQUE); //tile color

	//render tiles
	for (size_t i = 0; i < 8; i++) {

		for (size_t j = 0; j < 8; j++) {

			if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)) { //overlay checkered pattern

				SDL_Rect currentSquare = { i * SQUARE_SIZE, j * SQUARE_SIZE, SQUARE_SIZE , SQUARE_SIZE };
				SDL_RenderFillRect(Renderer, &currentSquare);


			}

			if (m_Pieces[i][j] != nullptr) {

				SDL_Rect transformInfo = { i * SQUARE_SIZE, j * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE};
				SDL_RenderCopy(Renderer, m_Pieces[i][j]->getTexture(), NULL, &transformInfo);


			}
		}
	}

	SDL_RenderPresent(Renderer);
	
}

