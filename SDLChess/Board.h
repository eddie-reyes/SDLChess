#include <SDL.h>
#include <array>
#include "Pawn.h"



class Board {

public:

	void Draw();

	Board();
	
	~Board();

	// Surface of board to draw on
	SDL_Renderer* Renderer;

	int SQUARE_SIZE;

private:


	//size of board
	int m_windowSize = 1024;

	// Create our window
	SDL_Window* m_Window;
	//container for all chess pieces
	std::array<std::array<Piece*, 8>, 8> m_Pieces;


};