#include "Piece.h"


Piece::Piece(SDL_Renderer* renderer, Team team, Position pos) : m_Team(team), m_Texture(nullptr), gridPosition(pos) {}

Piece::~Piece()
{

	SDL_DestroyTexture(m_Texture);

};


SDL_Texture * Piece::getTexture() const
{
	return m_Texture;
}

Team Piece::getTeam() const
{
	return m_Team;
}

