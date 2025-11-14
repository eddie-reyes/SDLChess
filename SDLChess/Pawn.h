#include "Piece.h"
#include <array>

class Pawn : public Piece  {

public:
	Pawn(SDL_Renderer* renderer, Team team);

	//bool evaluateMove(Board& pieces);

	std::array<valid_move, 2> possibleMoves = {{ {0, 1}, {0,2} }};

};