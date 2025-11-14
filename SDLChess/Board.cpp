#include "Board.h"

Board::Board()
{

	m_Window = SDL_CreateWindow("SDLChess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowSize, m_windowSize, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	SQUARE_SIZE = m_windowSize / 8;
	currentPiece = nullptr;

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
	
	SDL_SetRenderDrawColor(Renderer, BG_Color.r, BG_Color.g, BG_Color.b, SDL_ALPHA_OPAQUE); //background color

	SDL_RenderClear(Renderer);

	SDL_SetRenderDrawColor(Renderer, FG_Color.r, FG_Color.g, FG_Color.b, SDL_ALPHA_OPAQUE); //tile color

	updateMousePosition();

	SDL_Rect transformInfo; 

	//render tiles
	for (int i = 0; i < m_Pieces.size(); i++) {

		for (int j = 0; j < m_Pieces[i].size(); j++) {

			transformInfo = { i * SQUARE_SIZE, j * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE };

			if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)) { //overlay checkered pattern

				SDL_RenderFillRect(Renderer, &transformInfo);

			}

			if (m_Pieces[i][j] != nullptr && m_Pieces[i][j] != currentPiece) { //draw static pieces

				SDL_RenderCopy(Renderer, m_Pieces[i][j]->getTexture(), NULL, &transformInfo);

			}
		}
	}

	//render current piece
	if (currentPiece) {

		transformInfo = { mousePos.x - (SQUARE_SIZE / 2), mousePos.y - (SQUARE_SIZE / 2), SQUARE_SIZE, SQUARE_SIZE };
		SDL_RenderCopy(Renderer, currentPiece->getTexture(), NULL, &transformInfo);

	}


	SDL_RenderPresent(Renderer);
	
}

void Board::updateMousePosition()
{
	SDL_GetMouseState(&mousePos.x, &mousePos.y);

}

void Board::OnInteractionStarted()
{

	int projectedX = mousePos.x / SQUARE_SIZE;
	int projectedY = mousePos.y / SQUARE_SIZE;

	if (m_Pieces[projectedX][projectedY] != nullptr) {

		currentPiece = m_Pieces[projectedX][projectedY];

	}

}

void Board::OnInteractionEnded()
{

	currentPiece = nullptr;

}

