#pragma once
class GameBoard
{
	static const int width = 10;
	static const int height = 10;
	int LogicBoard[width][height]{ 0 };
	char Board[width][height];
public:
	void showBoard();
	void BoardChangeStatus();
	void putShip(int x, int y, bool horizontal,bool autoPlaceShips);
};

