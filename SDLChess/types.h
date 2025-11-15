#pragma once
struct Color {

	int r;
	int g;
	int b;

};

struct Position {

	int x;
	int y;

};

enum class Team {
	//indicates direction of movement
	WHITE_TEAM = -1, //up
	BLACK_TEAM = 1 //down

};