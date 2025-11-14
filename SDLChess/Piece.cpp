#include "Piece.h"


Piece::Piece(SDL_Renderer * renderer, Team team) {

	m_Team = team;
	m_Texture = nullptr;

}




SDL_Texture * Piece::getTexture() const
{
	return m_Texture;
}

