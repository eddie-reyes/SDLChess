#include "Knight.h"



Knight::Knight(SDL_Renderer* renderer, Team team, Position pos) : Piece(renderer, team, pos)
{

	switch (team) {

	case Team::WHITE_TEAM:
		m_Texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/white-knight.bmp"));
		break;

	case Team::BLACK_TEAM:
		m_Texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/black-knight.bmp"));
		break;

	default: break;
	}

}

bool Knight::validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos)
{
	int projectedX = mousePos.x / Constants::TILE_SIZE;
	int projectedY = mousePos.y / Constants::TILE_SIZE;

	Position relativePos{ projectedX - gridPosition.x, projectedY - gridPosition.y };

	for (Position& validPos : possibleMoves) {

		if (relativePos.x == validPos.x && relativePos.y == validPos.y) {

			if (pieces[projectedX][projectedY] != nullptr && pieces[projectedX][projectedY]->getTeam() == m_Team) break; //prevent self-attacks

			return true;

		}

	}

	return false;
}



