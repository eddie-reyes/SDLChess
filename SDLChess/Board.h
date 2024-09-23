#include "Game.h"
#include <SDL.h>
#include <array>


class Board {

public:
	//listener for mouse events
	void EventLoop();

	void Draw();

private:

	//size of board
	int m_windowSize = 1024;
	// Create our window
	SDL_Window* m_Window = SDL_CreateWindow("SDLChess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowSize, m_windowSize, SDL_WINDOW_SHOWN);
	// Surface of board to draw on
	SDL_Renderer* m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	//container for all chess pieces
	std::array<int, 64> m_Pieces;


};