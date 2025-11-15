#pragma once
#include <SDL.h>
#include <array>
#include "types.h"
#include "constants.h"

class Piece {

public:

	Piece(SDL_Renderer* renderer, Team team, Position pos);

	~Piece();

	SDL_Texture  * getTexture() const;

	Team getTeam() const;

	virtual bool validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos) = 0;

	Position gridPosition;

protected:

	Team m_Team;

	SDL_Texture* m_Texture;


};