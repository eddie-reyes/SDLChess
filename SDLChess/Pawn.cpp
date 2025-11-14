#include "Pawn.h"


Pawn::Pawn(SDL_Renderer* renderer, Team team) : Piece(renderer, team)
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
