#include "Board.h"
#include <iostream>

Board::Board()
{

	m_Window = SDL_CreateWindow("SDLChess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Constants::WINDOW_SIZE, Constants::WINDOW_SIZE, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	currentPiece = nullptr;
	

	//pawns


	for (int i = 0; i < 8; i++) {

		Pieces[i][1] = new Pawn(Renderer, Team::BLACK_TEAM, {i, 1});
		Pieces[i][6] = new Pawn(Renderer, Team::WHITE_TEAM, {i, 6});

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
	for (int i = 0; i < Pieces.size(); i++) {

		for (int j = 0; j < Pieces[i].size(); j++) {

			transformInfo = { i * Constants::TILE_SIZE, j * Constants::TILE_SIZE, Constants::TILE_SIZE, Constants::TILE_SIZE };

			if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)) { //overlay checkered pattern

				SDL_RenderFillRect(Renderer, &transformInfo);

			}

			if (Pieces[i][j] != nullptr && Pieces[i][j] != currentPiece) { //render static pieces

				SDL_RenderCopy(Renderer, Pieces[i][j]->getTexture(), NULL, &transformInfo);

			}
		}
	}

	//render interacted piece
	if (currentPiece) {

		transformInfo = { mousePos.x - (Constants::TILE_SIZE / 2), mousePos.y - (Constants::TILE_SIZE / 2), Constants::TILE_SIZE, Constants::TILE_SIZE };
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

	int projectedX = mousePos.x / Constants::TILE_SIZE;
	int projectedY = mousePos.y / Constants::TILE_SIZE;

	if (Pieces[projectedX][projectedY] != nullptr) {

		currentPiece = Pieces[projectedX][projectedY];

	}

}

void Board::OnInteractionEnded()
{

	//std::cout << currentPiece->validMove(Pieces, mousePos);

	if (currentPiece->validMove(Pieces, mousePos)) {

		EvaluateMove();

	}

	currentPiece = nullptr;

}

void Board::EvaluateMove()
{

	int projectedX = mousePos.x / Constants::TILE_SIZE;
	int projectedY = mousePos.y / Constants::TILE_SIZE;

	if (Pieces[projectedX][projectedY] != nullptr) {

		delete Pieces[projectedX][projectedY];
			
	}

	Position oldPos = { currentPiece->gridPosition.x, currentPiece->gridPosition.y };
	
	Pieces[projectedX][projectedY] = currentPiece;
	Pieces[oldPos.x][oldPos.y] = nullptr;
	
	currentPiece->gridPosition = { projectedX, projectedY };


}

