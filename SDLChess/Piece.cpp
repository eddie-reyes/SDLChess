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

Position Piece::getRelativePosition(int x, int y)
{

	return { x - gridPosition.x, y - gridPosition.y };

}

bool Piece::isTargetSameTeam(int targetX, int targetY, std::array<std::array<Piece*, 8>, 8>& pieces)
{
	return (pieces[targetX][targetY] != nullptr && pieces[targetX][targetY]->getTeam() == m_Team); //prevent self-attacks

}

