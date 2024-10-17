#pragma once
class GameBoard
{
	struct ShipsSizeStr
	{
		static const int LargeShip = 5;
		static const int MediumShip = 4;
		static const int Ship = 3;
		static const int SmallShip = 2;
		static const int Boat = 1;
	};

	struct ShipsStr
	{
		int LargeShips = 0;
		int MediumShips = 0;
		int Ships = 0;
		int SmallShips = 0;
		int Boats = 0;
	};

	ShipsStr Ships;

	static const int width = 10;
	static const int height = 10;
	int LogicBoard[width][height]{ 0 };
	char Board[width][height];
	

public:

	int ShipCount = 0;
	void showBoard();
	void BoardChangeStatus();
	void placeShip(bool autoPlaceShips);

};

