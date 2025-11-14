
#include <SDL.h>
#include <array>
#include "Pawn.h"

struct Color {

	int r;
	int g;
	int b;

};

struct Position {

	int x;
	int y;

};

const Color BG_Color = { 248, 231, 187 };
const Color FG_Color = { 251, 245, 222 };

class Board {

public:

	void Draw();

	void updateMousePosition();

	void OnInteractionStarted();

	void OnInteractionEnded();

	Board();
	
	~Board();

	// Surface of board to draw on
	SDL_Renderer* Renderer;

	int SQUARE_SIZE;

	Piece* currentPiece;

	Position mousePos;

private:

	//size of board
	int m_windowSize = 1024;

	// Create our window
	SDL_Window* m_Window;

	//container for all chess pieces
	std::array<std::array<Piece*, 8>, 8> m_Pieces;


};