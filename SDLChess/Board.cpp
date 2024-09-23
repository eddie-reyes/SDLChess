#include "Board.h"

void Board::EventLoop()
{

	

}

void Board::Draw()
{
	SDL_SetRenderDrawColor(m_Renderer, 248, 231, 187, 0);
	SDL_RenderClear(m_Renderer); //draw backdrop

	for (size_t i = 0; i < 8; i++) {

		for (size_t j = 0; j < 8; j++) {

			if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)) { //overlay checkered pattern

				SDL_Rect currentSquare = { i * m_windowSize / 8, j * m_windowSize / 8, m_windowSize / 8 , m_windowSize / 8 };
				SDL_SetRenderDrawColor(m_Renderer, 251, 245, 222, 0);
				SDL_RenderFillRect(m_Renderer, &currentSquare);

			}
		}
	}

	SDL_RenderPresent(m_Renderer);
	
	SDL_Delay(10000);
}

