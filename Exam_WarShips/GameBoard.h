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

		int LargeShipsPos[3];
		int MediumShipsPos[2][3];
		int ShipsPos[3][3];
		int SmallShipsPos[4][3];
		int BoatsPos[5][2];
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
	void showShadowBoard();
	void shoot(bool* SuccessShoot);
	void CompShoot(bool* SuccessShoot, int* xPrev, int* yPrev,int*directionPrev,int* missShot);
	void BoardCheckShoot(int x,int y);


	//				ONLY FOR DEBUG!!!!!!!


	void ShowPos();
};