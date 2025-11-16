#include "Rook.h"

Rook::Rook(SDL_Renderer* renderer, Team team, Position pos) : Piece(renderer, team, pos)
{

	switch (team) {

		case Team::WHITE_TEAM:
			m_Texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/white-rook.bmp"));
			break;

		case Team::BLACK_TEAM:
			m_Texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("assets/black-rook.bmp"));
			break;

		default: break;
	}
}

bool Rook::validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos)
{
	int projectedX = mousePos.x / Constants::TILE_SIZE;
	int projectedY = mousePos.y / Constants::TILE_SIZE;

	Position relativePos = getRelativePosition(projectedX, projectedY);

	if (isTargetSameTeam(projectedX, projectedY, pieces)) return false; //prevent self-attacks

	if (relativePos.x == 0 || relativePos.y == 0) { //check if move is along vertical or horizontal

		while (relativePos.x != 0 || relativePos.y != 0) {

			if (relativePos.x != 0 ) {
			
				relativePos.x > 0 ? relativePos.x-- : relativePos.x++;
			}

			if (relativePos.y != 0) {

				relativePos.y > 0 ? relativePos.y-- : relativePos.y++;

			}

			Piece* temp = pieces[gridPosition.x + relativePos.x][gridPosition.y + relativePos.y];

			if (temp != nullptr && temp != this) return false; //if vertical/horizontal contains a piece other than itself, invalid move


		}

		return true;

	}

	else { // not vertical or horizonal 

		return false;

	}
}