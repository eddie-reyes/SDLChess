#pragma once
struct Color {

	int r;
	int g;
	int b;

};

//represents 2d coordinates or grid position
struct Position {

	int x;
	int y;

};

enum class Team {

	//value indicates direction of movement

	WHITE_TEAM = -1, //up
	BLACK_TEAM = 1 //down

};