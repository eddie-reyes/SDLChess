#include "Pawn.h"



Pawn::Pawn(SDL_Renderer* renderer, Team team, Position pos) : Piece(renderer, team, pos)
{

	switch (team) {

		case Team::WHITE_TEAM:
			m_Texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/white-pawn.bmp"));
			break;

		case Team::BLACK_TEAM:
			m_Texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/black-pawn.bmp"));
			break;

		default: break;
	}

}

bool Pawn::validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos)
{
	int projectedX = mousePos.x / Constants::TILE_SIZE;
	int projectedY = mousePos.y / Constants::TILE_SIZE;
	
	Position relativePos{ projectedX - gridPosition.x, projectedY - gridPosition.y};

	for (Position& validPos : possibleMoves) {

		if (relativePos.x == validPos.x && (relativePos.y * static_cast<int>(m_Team)) == validPos.y) { 

			if (pieces[gridPosition.x][projectedY] != nullptr && relativePos.x == 0) break; //prevent straight-on attacks

			if (pieces[projectedX][projectedY] != nullptr && pieces[projectedX][projectedY]->getTeam() == m_Team) break; //prevent self-attacks
	
			if (validPos.y == 2) possibleMoves.pop_back(); //first move flag

			return true;
		}

	}
	
	return false;
}



