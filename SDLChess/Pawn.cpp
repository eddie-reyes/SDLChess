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
	
	Position relativePos = getRelativePosition(projectedX, projectedY);

	if (isTargetSameTeam(projectedX, projectedY, pieces)) return false; //prevent self-attacks

	if (pieces[gridPosition.x][projectedY] != nullptr && relativePos.x == 0) return false; //prevent straight-on attacks

	for (Position& validPos : possibleMoves) {

		if (relativePos.x == validPos.x && (relativePos.y * static_cast<int>(m_Team)) == validPos.y) { 
	
			if (validPos.y == 2) possibleMoves.pop_back(); //remove 2-space move after first use

			return true;
		}

	}
	
	return false;
}



