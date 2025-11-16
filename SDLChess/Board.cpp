#include "Board.h"
#include <iostream>

Board::Board()
{

	m_Window = SDL_CreateWindow("SDLChess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Constants::WINDOW_SIZE, Constants::WINDOW_SIZE, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);


	//pawns
	for (int i = 0; i < 8; i++) {

		Pieces[i][1] = new Pawn(Renderer, Team::BLACK_TEAM, { i, 1 });
		Pieces[i][6] = new Pawn(Renderer, Team::WHITE_TEAM, { i, 6 });

	}

	//knights
	Pieces[1][0] = new Knight(Renderer, Team::BLACK_TEAM, { 1, 0 });
	Pieces[6][0] = new Knight(Renderer, Team::BLACK_TEAM, { 6, 0 });
	Pieces[1][7] = new Knight(Renderer, Team::WHITE_TEAM, { 1, 7 });
	Pieces[6][7] = new Knight(Renderer, Team::WHITE_TEAM, { 6, 7 });

	//bishops
	Pieces[2][0] = new Bishop(Renderer, Team::BLACK_TEAM, { 2, 0 });
	Pieces[5][0] = new Bishop(Renderer, Team::BLACK_TEAM, { 5, 0 });
	Pieces[2][7] = new Bishop(Renderer, Team::WHITE_TEAM, { 2, 7 });
	Pieces[5][7] = new Bishop(Renderer, Team::WHITE_TEAM, { 5, 7 });

	//rooks
	Pieces[0][0] = new Rook(Renderer, Team::BLACK_TEAM, { 0, 0 });
	Pieces[7][0] = new Rook(Renderer, Team::BLACK_TEAM, { 7, 0 });
	Pieces[0][7] = new Rook(Renderer, Team::WHITE_TEAM, { 0, 7 });
	Pieces[7][7] = new Rook(Renderer, Team::WHITE_TEAM, { 7, 7 });

	//kings
	Pieces[4][0] = new King(Renderer, Team::BLACK_TEAM, { 4, 0 });
	Pieces[4][7] = new King(Renderer, Team::WHITE_TEAM, { 4, 7 });

	//queens
	Pieces[3][0] = new Queen(Renderer, Team::BLACK_TEAM, { 3,0 });
	Pieces[3][7] = new Queen(Renderer, Team::WHITE_TEAM, { 3,7 });

	m_WhiteWin = SDL_CreateTextureFromSurface(Renderer, SDL_LoadBMP("assets/white-wins.bmp"));
	m_BlackWin = SDL_CreateTextureFromSurface(Renderer, SDL_LoadBMP("assets/black-wins.bmp"));
	
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
	
	if (gameOver) ShowGameOverScreen();

	SDL_RenderPresent(Renderer);
	
}

void Board::updateMousePosition()
{
	SDL_GetMouseState(&mousePos.x, &mousePos.y);

}

void Board::OnInteractionStarted()
{

	if (gameOver) return;

	int projectedX = mousePos.x / Constants::TILE_SIZE;
	int projectedY = mousePos.y / Constants::TILE_SIZE;

	Piece* selectedPiece = Pieces[projectedX][projectedY];


	if (selectedPiece != nullptr) {

		currentPiece = selectedPiece;

	}

}

void Board::OnInteractionEnded()
{
	//bounds check
	if (mousePos.x < 0 || mousePos.x > Constants::WINDOW_SIZE || mousePos.y < 0 || mousePos.y > Constants::WINDOW_SIZE) return;

	if (currentPiece == nullptr || currentPiece->getTeam() != m_CurrentTurn) return;

	if (currentPiece->validMove(Pieces, mousePos)) {

		EvaluateMove();

	}

}

void Board::EvaluateMove()
{

	int projectedX = mousePos.x / Constants::TILE_SIZE;
	int projectedY = mousePos.y / Constants::TILE_SIZE;

	if (Pieces[projectedX][projectedY] != nullptr) {

		if (typeid(*Pieces[projectedX][projectedY]) == typeid(King)) {
			
			gameOver = true;
			
		}

		delete Pieces[projectedX][projectedY];
			
	}

	Position oldPos = { currentPiece->gridPosition.x, currentPiece->gridPosition.y };
	
	Pieces[projectedX][projectedY] = currentPiece;
	Pieces[oldPos.x][oldPos.y] = nullptr;
	
	currentPiece->gridPosition = { projectedX, projectedY };

	if (gameOver) return;

	m_CurrentTurn = (m_CurrentTurn == Team::WHITE_TEAM ? Team::BLACK_TEAM : Team::WHITE_TEAM);


}

void Board::ShowGameOverScreen()
{

	SDL_SetRenderDrawBlendMode(Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE / 1.5); //background color
	SDL_Rect BG{ 0, 0, Constants::WINDOW_SIZE, Constants::WINDOW_SIZE };
	SDL_RenderFillRect(Renderer, &BG);

	SDL_Rect winBoundingRect{(Constants::WINDOW_SIZE / 2) - Constants::TILE_SIZE * 2, (Constants::WINDOW_SIZE / 2) - (Constants::TILE_SIZE / 2), Constants::TILE_SIZE * 4, Constants::TILE_SIZE};

	switch (m_CurrentTurn) {

	case Team::BLACK_TEAM:
		SDL_RenderCopy(Renderer, m_BlackWin, NULL, &winBoundingRect);
		break;

	case Team::WHITE_TEAM:
		SDL_RenderCopy(Renderer, m_WhiteWin, NULL, &winBoundingRect);
		break;

	default:
		break;
	}

}

