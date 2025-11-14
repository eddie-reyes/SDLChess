#pragma once
#include <SDL.h>



enum class Team {

	WHITE_TEAM,
	BLACK_TEAM

};

struct valid_move {

	int x;
	int y;

};

class Piece {

public:

	Piece(SDL_Renderer* renderer, Team team);

	SDL_Texture  * getTexture() const;

private:


	Team m_Team;

protected:

	SDL_Texture* m_Texture;

};