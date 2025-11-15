#include "Bishop.h"


Bishop::Bishop(SDL_Renderer* renderer, Team team, Position pos) : Piece(renderer, team, pos)
{

	switch (team) {

	case Team::WHITE_TEAM:
		m_Texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/white-bishop.bmp"));
		break;

	case Team::BLACK_TEAM:
		m_Texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/black-bishop.bmp"));
		break;

	default: break;
	}

}

bool Bishop::validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos)
{
	int projectedX = mousePos.x / Constants::TILE_SIZE;
	int projectedY = mousePos.y / Constants::TILE_SIZE;

	Position relativePos{ projectedX - gridPosition.x, projectedY - gridPosition.y };

	if (pieces[projectedX][projectedY] != nullptr && pieces[projectedX][projectedY]->getTeam() == m_Team) return false; //prevent self-attacks


	if (abs(relativePos.x) == abs(relativePos.y)) { //check if move is diagonal

		while (abs(relativePos.x) > 0) { //check all positions along diagonal

			relativePos.x > 0 ? relativePos.x-- : relativePos.x++;

			relativePos.y > 0 ? relativePos.y-- : relativePos.y++;

			Piece * temp = pieces[gridPosition.x + relativePos.x][gridPosition.y + relativePos.y];

			if (temp != nullptr && temp != this) return false; //if diagonal contains a piece other than itself, invalid move

		}

		return true;

	}

	else { // not diagonal

		return false;

	}
}