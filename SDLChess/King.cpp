#include "King.h"

King::King(SDL_Renderer* renderer, Team team, Position pos) : Piece(renderer, team, pos)
{

	switch (team) {

		case Team::WHITE_TEAM:
			m_Texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/white-king.bmp"));
			break;

		case Team::BLACK_TEAM:
			m_Texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/black-king.bmp"));
			break;

		default: break;
	}

}

bool King::validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos) {

	int projectedX = mousePos.x / Constants::TILE_SIZE;
	int projectedY = mousePos.y / Constants::TILE_SIZE;

	Position relativePos = getRelativePosition(projectedX, projectedY);

	if (isTargetSameTeam(projectedX, projectedY, pieces)) return false; //prevent self-attacks

	return (abs(relativePos.x) <= 1 && abs(relativePos.y) <= 1);  //if relative position is 1 away from starting position
	
}

