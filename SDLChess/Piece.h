#pragma once
#include <SDL.h>
#include <array>
#include "types.h"
#include "constants.h"

//base class for each piece
//describes underlying functionality for each piece


class Piece {

public:

	//init piece with respective texture and team enum
	Piece(SDL_Renderer* renderer, Team team, Position pos);

	//handles destruction of texture
	~Piece();

	//getters
	SDL_Texture  * getTexture() const;
	Team getTeam() const;
	Position getRelativePosition(int x, int y);

	//calulates validity of move based on the rules of chess, should be overriden
	virtual bool validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos) = 0;

	//helper function
	bool isTargetSameTeam(int targetX, int targetY, std::array<std::array<Piece*, 8>, 8>& pieces);

	//holds x, y position on board
	Position gridPosition;

protected:

	//ref to team
	Team m_Team;
	
	//ref to texture
	SDL_Texture* m_Texture;


};