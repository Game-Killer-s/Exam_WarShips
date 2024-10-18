#include <iostream>
#include "GameBoard.h"

using namespace std;

void GameBoard::showBoard() {
	cout << "|Дошка гравця|\n|Кораблів живих:" << "|Дуже великих|" << Ships.LargeShips << "|Великих|" << Ships.MediumShips << "|Середніх|" << Ships.Ships << "|Маленьких|" << Ships.SmallShips << "|Крихітних|" << Ships.Boats << "|Усього клітин з кораблями|" << ShipCount << "|" << endl << endl;
	//cout << "|Player Board|\n|Ships alive:" << "|Large ships|" << Ships.LargeShips << "|Medium ships|" << Ships.MediumShips << "|Ships|" << Ships.Ships << "|Small ships|" << Ships.SmallShips << "|Boats|" << Ships.Boats << "|All squares with ships|" << ShipCount << "|" << endl << endl;
	cout << "  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |" << endl;
	cout << "--|---|---|---|---|---|---|---|---|---|---|" << endl;
	for (int i = 0; i < width; i++) {
		cout << i;
		for (int j = 0; j < height; j++) {
			if (j == 0) {
				cout << " |";
			}
			cout << " ";
			cout << Board[i][j] << " |";
		}
		cout << endl << "--|---|---|---|---|---|---|---|---|---|---|" << endl;
	}
	cout << endl;
}

void GameBoard::showShadowBoard() {
	cout << "|Дошка компьютера|\n|Кораблів живих:" << "|Дуже великих|" << Ships.LargeShips << "|Великих|" << Ships.MediumShips << "|Середніх|" << Ships.Ships << "|Маленьких|" << Ships.SmallShips << "|Крихітних|" << Ships.Boats << "|Усього клітин з кораблями|" << ShipCount << "|" << endl << endl;
	//cout << "|Computer`s Board|\n|Ships alive:" << "|Large ships|" << Ships.LargeShips << "|Medium ships|" << Ships.MediumShips << "|Ships|" << Ships.Ships << "|Small ships|" << Ships.SmallShips << "|Boats|" << Ships.Boats << "|All squares with ships|" << ShipCount << "|" << endl << endl;
	cout << "  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |" << endl;
	cout << "--|---|---|---|---|---|---|---|---|---|---|" << endl;
	for (int i = 0; i < width; i++) {
		cout << i;
		for (int j = 0; j < height; j++) {
			if (j == 0) {
				cout << " |";
			}
			cout << " ";
			if (Board[i][j] == 'S') {
				cout << " " << " |";
			}
			else {
				cout << Board[i][j] << " |";
			}
		}
		cout << endl << "--|---|---|---|---|---|---|---|---|---|---|" << endl;
	}
	cout << endl;
}

void GameBoard::BoardChangeStatus() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			switch (LogicBoard[i][j])
			{
			case(0):
				Board[i][j] = ' ';
				break;
			case(1):
				Board[i][j] = 'S';
				break;
			case(2):
				Board[i][j] = 'H';
				break;
			case(3):
				Board[i][j] = 'M';
				break;
			case(4):
				Board[i][j] = 'F';
				break;
			default:
				break;
			}

		}
	}
}

void GameBoard::placeShip(bool autoPlaceShips) {
	int x, y;
	bool horizontal;
	if (autoPlaceShips) {
		while (Ships.LargeShips != 1 || Ships.MediumShips != 2 || Ships.Ships != 3 || Ships.SmallShips != 4 || Ships.Boats != 5) {
			if (Ships.LargeShips != 1) {
				BoardChangeStatus();
				x = rand() % 6;
				y = rand() % 6;
				horizontal = rand() % 2;
				if (x < 0 || x>9 || y < 0 || y>9) {
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::LargeShip; i++) {
							if (LogicBoard[y + i][x] == 1) {
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::LargeShip; i++) {
							LogicBoard[y + i][x] = 1;
							ShipCount++;
						}
					}
					else {
						for (int i = 0; i < GameBoard::ShipsSizeStr::LargeShip; i++) {
							if (LogicBoard[y][x + i] == 1) {
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::LargeShip; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.LargeShipsPos[0] = y;
					Ships.LargeShipsPos[1] = x;
					Ships.LargeShipsPos[2] = horizontal;
					Ships.LargeShips++;
				}
			}
			else if (Ships.MediumShips != 2) {
				BoardChangeStatus();
				x = rand() % 7;
				y = rand() % 7;
				horizontal = rand() % 2;
				if (x < 0 || x>9 || y < 0 || y>9) {
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::MediumShip; i++) {
							if (LogicBoard[y + i][x] == 1) {
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::MediumShip; i++) {
							LogicBoard[y + i][x] = 1;
							ShipCount++;
						}
					}
					else {
						for (int i = 0; i < GameBoard::ShipsSizeStr::MediumShip; i++) {
							if (LogicBoard[y][x + i] == 1) {
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::MediumShip; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.MediumShipsPos[Ships.MediumShips][0] = y;
					Ships.MediumShipsPos[Ships.MediumShips][1] = x;
					Ships.MediumShipsPos[Ships.MediumShips][2] = horizontal;
					Ships.MediumShips++;
				}
			}
			else if (Ships.Ships != 3) {
				BoardChangeStatus();
				x = rand() % 8;
				y = rand() % 8;
				horizontal = rand() % 2;
				if (x < 0 || x>9 || y < 0 || y>9) {
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::Ship; i++) {
							if (LogicBoard[y + i][x] == 1) {
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::Ship; i++) {
							LogicBoard[y + i][x] = 1;
							ShipCount++;
						}
					}
					else {
						for (int i = 0; i < GameBoard::ShipsSizeStr::Ship; i++) {
							if (LogicBoard[y][x + i] == 1) {
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::Ship; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.ShipsPos[Ships.Ships][0] = y;
					Ships.ShipsPos[Ships.Ships][1] = x;
					Ships.ShipsPos[Ships.Ships][2] = horizontal;
					Ships.Ships++;
				}
			}
			else if (Ships.SmallShips != 4) {
				BoardChangeStatus();
				x = rand() % 9;
				y = rand() % 9;
				horizontal = rand() % 2;
				if (x < 0 || x>9 || y < 0 || y>9) {
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::SmallShip; i++) {
							if (LogicBoard[y + i][x] == 1) {
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::SmallShip; i++) {
							LogicBoard[y + i][x] = 1;
							ShipCount++;
						}
					}
					else {
						for (int i = 0; i < GameBoard::ShipsSizeStr::SmallShip; i++) {
							if (LogicBoard[y][x + i] == 1) {
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::SmallShip; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.SmallShipsPos[Ships.SmallShips][0] = y;
					Ships.SmallShipsPos[Ships.SmallShips][1] = x;
					Ships.SmallShipsPos[Ships.SmallShips][2] = horizontal;
					Ships.SmallShips++;
				}
			}
			else if (Ships.Boats != 5) {
				BoardChangeStatus();
				x = rand() % 10;
				y = rand() % 10;
				horizontal = rand() % 2;
				if (x < 0 || x>9 || y < 0 || y>9) {
					return;
				}
				else {
					for (int i = 0; i < GameBoard::ShipsSizeStr::Boat; i++) {
						if (LogicBoard[y][x + i] == 1) {
							return;
						}
					}
					for (int i = 0; i < GameBoard::ShipsSizeStr::Boat; i++) {
						LogicBoard[y][x + i] = 1;
						ShipCount++;
					}
					Ships.BoatsPos[Ships.Boats][0] = y;
					Ships.BoatsPos[Ships.Boats][1] = x;
					Ships.Boats++;
				}
			}
		}
	}
	else {
		while (Ships.LargeShips != 1 || Ships.MediumShips != 2 || Ships.Ships != 3 || Ships.SmallShips != 4 || Ships.Boats != 5) {
			if (Ships.LargeShips != 1) {
				BoardChangeStatus();
				showBoard();
				cout << "Напишіть \'x\' та \'y\' координати куди поставити кораблі та 0 для вертикального розміщення чи 1 для горизонтального|\n|:";
				//cout << "Input \'x\' and \'y\' coordinate where to place ships and 0 for vertical placement or 1 for horizontal|\n|:";
				cin >> x >> y >> horizontal;
				if (x < 0 || x>9 || y < 0 || y>9) {
					cout << "Введіть коректні значення" << endl;
					//cout << "Input correct numbers" << endl;
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::LargeShip; i++) {
							if (LogicBoard[y + i][x] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
								//cout << "You cannot place ship in place where ship already placed" << endl;
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::LargeShip; i++) {
							LogicBoard[y+i][x] = 1;
							ShipCount++;
						}
					}
					else {
						for (int i = 0; i < GameBoard::ShipsSizeStr::LargeShip; i++) {
							if (LogicBoard[y][x + i] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
								//cout << "You cannot place ship in place where ship already placed" << endl;
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::LargeShip; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.LargeShipsPos[0] = y;
					Ships.LargeShipsPos[1] = x;
					Ships.LargeShipsPos[2] = horizontal;
					Ships.LargeShips++;
				}
			}
			else if (Ships.MediumShips != 2) {
				BoardChangeStatus();
				showBoard();
				cout << "Напишіть \'x\' та \'y\' координати куди поставити кораблі та 0 для вертикального розміщення чи 1 для горизонтального|\n|:";
				//cout << "Input \'x\' and \'y\' coordinate where to place ships and 0 for vertical placement or 1 for horizontal|\n|:";
				cin >> x >> y >> horizontal;
				cout << endl;
				if (x < 0 || x>9 || y < 0 || y>9) {
					cout << "Введіть коректні значення" << endl;
					//cout << "Input correct numbers" << endl;
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::MediumShip; i++) {
							if (LogicBoard[y + i][x] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
								//cout << "You cannot place ship in place where ship already placed" << endl;
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::MediumShip; i++) {
							LogicBoard[y + i][x] = 1;
							ShipCount++;
						}
					}
					else {
						for (int i = 0; i < GameBoard::ShipsSizeStr::MediumShip; i++) {
							if (LogicBoard[y][x + i] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
								//cout << "You cannot place ship in place where ship already placed" << endl;
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::MediumShip; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.MediumShipsPos[Ships.MediumShips][0] = y;
					Ships.MediumShipsPos[Ships.MediumShips][1] = x;
					Ships.MediumShipsPos[Ships.MediumShips][2] = horizontal;
					Ships.MediumShips++;
				}
			}
			else if (Ships.Ships != 3) {
				BoardChangeStatus();
				showBoard();
				cout << "Напишіть \'x\' та \'y\' координати куди поставити кораблі та 0 для вертикального розміщення чи 1 для горизонтального|\n|:";
				//cout << "Input \'x\' and \'y\' coordinate where to place ships and 0 for vertical placement or 1 for horizontal|\n|:";
				cin >> x >> y >> horizontal;
				cout << endl;
				if (x < 0 || x>9 || y < 0 || y>9) {
					cout << "Введіть коректні значення" << endl;
					//cout << "Input correct numbers" << endl;
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::Ship; i++) {
							if (LogicBoard[y + i][x] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
								//cout << "You cannot place ship in place where ship already placed" << endl;
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::Ship; i++) {
							LogicBoard[y + i][x] = 1;
							ShipCount++;
						}
					}
					else {
						for (int i = 0; i < GameBoard::ShipsSizeStr::Ship; i++) {
							if (LogicBoard[y][x + i] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
								//cout << "You cannot place ship in place where ship already placed" << endl;
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::Ship; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.ShipsPos[Ships.Ships][0] = y;
					Ships.ShipsPos[Ships.Ships][1] = x;
					Ships.ShipsPos[Ships.Ships][2] = horizontal;
					Ships.Ships++;
				}
			}
			else if (Ships.SmallShips != 4) {
				BoardChangeStatus();
				showBoard();
				cout << "Напишіть \'x\' та \'y\' координати куди поставити кораблі та 0 для вертикального розміщення чи 1 для горизонтального|\n|:";
				//cout << "Input \'x\' and \'y\' coordinate where to place ships and 0 for vertical placement or 1 for horizontal|\n|:";
				cin >> x >> y >> horizontal;
				cout << endl;
				if (x < 0 || x>9 || y < 0 || y>9) {
					cout << "Введіть коректні значення" << endl;
					//cout << "Input correct numbers" << endl;
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::SmallShip; i++) {
							if (LogicBoard[y + i][x] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
								//cout << "You cannot place ship in place where ship already placed" << endl;
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::SmallShip; i++) {
							LogicBoard[y + i][x] = 1;
							ShipCount++;
						}
					}
					else {
						for (int i = 0; i < GameBoard::ShipsSizeStr::SmallShip; i++) {
							if (LogicBoard[y][x + i] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
								//cout << "You cannot place ship in place where ship already placed" << endl;
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::SmallShip; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.SmallShipsPos[Ships.SmallShips][0] = y;
					Ships.SmallShipsPos[Ships.SmallShips][1] = x;
					Ships.SmallShipsPos[Ships.SmallShips][2] = horizontal;
					Ships.SmallShips++;
				}
			}
			else if (Ships.Boats != 5) {
				BoardChangeStatus();
				showBoard();
				cout << "Напишіть \'x\' та \'y\' координати куди поставити кораблі\n|:";
				//cout << "Input \'x\' and \'y\' coordinate where to place ships|\n|:";
				cin >> x >> y;
				cout << endl;
				if (x < 0 || x>9 || y < 0 || y>9) {
					cout << "Введіть коректні значення" << endl;
					//cout << "Input correct numbers" << endl;
					return;
				}
				else {
					for (int i = 0; i < GameBoard::ShipsSizeStr::Boat; i++) {
						if (LogicBoard[y][x + i] == 1) {
							cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
							//cout << "You cannot place ship in place where ship already placed" << endl;
							return;
						}
					}
					for (int i = 0; i < GameBoard::ShipsSizeStr::Boat; i++) {
						LogicBoard[y][x + i] = 1;
						ShipCount++;
					}
					Ships.BoatsPos[Ships.Boats][0] = y;
					Ships.BoatsPos[Ships.Boats][1] = x;
					Ships.Boats++;
				}
			}
		}
	}
}

void GameBoard::shoot(bool* SuccessShoot) {
	int x,
		y;
	while (true) {
		cout << "Введіть координати 'x' та 'y' для пострілу" << endl;
		//cout << "Input coordinate 'x' and 'y' for shoot" << endl;
		cin >> x >> y;
		if (x < 0 || x>9 || y < 0 || y>9) {
			cout << "Введіть коректні значення" << endl;
			//cout << "Input correct numbers" << endl;
			return;
		}
		else {
			switch (LogicBoard[y][x])
			{
			case(0):
				LogicBoard[y][x] = 3;
				*SuccessShoot = true;
				return;
			case(1):
				LogicBoard[y][x] = 2;
				BoardCheckShoot(y, x);
				*SuccessShoot = true;
				ShipCount--;
				return;
			default:
				cout << "Постріл не може бути зроблен у те саме місце" << endl;
				//cout << "Shoot cannot be done to a same position" << endl;
				return;
			}
		}
	}
}

void GameBoard::CompShoot(bool* SuccessShoot, int* xPrev, int* yPrev,int*directionPrev,int*missShot) {
	int x,
		y,
		direction=-1;
	while (true) {
		if (*missShot > 4) {
			*xPrev = -1;
			*yPrev = -1;
			*directionPrev = -1;
			*missShot = 0;
		}
		if (*xPrev<0||*xPrev>9||*yPrev<0||*yPrev>9) {
			x = rand() % 10;
			y = rand() % 10;
		}
		else {
			x = *xPrev;
			y = *yPrev;
			if (*directionPrev < 0 || *directionPrev>3) {
				while (true) {
					direction = rand() % 4;
					if (direction >= 0 && direction <= 3) {
						*missShot = 0;
						break;
					}
				}
			}
			else {
				direction = *directionPrev;
			}
			switch (direction)
			{
			case(0):
				y++;
				break;
			case(1):
				x--;
				break;
			case(2):
				y--;
				break;
			case(3):
				x++;
				break;
			default:
				break;
			}
		}
		if (x < 0 || x>9 || y < 0 || y>9) {
			if (direction > 0) {
				direction--;
				*directionPrev = direction;
			}
			else {
				direction++;
				*directionPrev = direction;
			}
			return;
		}
		else {
			switch (LogicBoard[y][x])
			{
			case(0):
				LogicBoard[y][x] = 3;
				*SuccessShoot = true;
				if (direction < 0 || direction>3) {
					return;
				}
				if (direction >= 2) {
					direction - 2;
				}
				else {
					direction + 2;
				}
				*directionPrev = direction;
				++*missShot;
				return;
			case(1):
				LogicBoard[y][x] = 2;
				BoardCheckShoot(y, x);
				*xPrev = x;
				*yPrev = y;
				*SuccessShoot = true;
				ShipCount--;
				if (direction < 0 || direction>4) {
					return;
				}
				else {
					*directionPrev = direction;
					return;
				}
			default:
				if (*directionPrev < 0 || *directionPrev>3) {
					return;
				}
				else {
					if (direction > 0) {
						direction--;
						*directionPrev = direction;
					}
					else {
						direction++;
						*directionPrev = direction;
					}
					++*missShot;
					return;
				}
			}
		}
	}
}

void GameBoard::BoardCheckShoot(int x, int y) { //Need to do in right way (Змінити локальні перевірки на комплексні перевірки кораблів)
	bool xCorr=false,
		yCorr=false,
		Flouded=false;
	while (true) {
		if (Ships.LargeShips > 0) {
			if (Ships.LargeShipsPos[0] == x) {
				xCorr = true;
			}
			if (Ships.LargeShipsPos[1] == y) {
				yCorr = true;
			}
			if (xCorr && yCorr) {
				if (Ships.LargeShipsPos[2] == 0) {
					for (int i = 0; i < ShipsSizeStr::LargeShip; i++) {
						if (LogicBoard[x + i][y] != 2) {
							break;
						}
						else {
							Flouded = true;
						}
					}
					if (Flouded) {
						for (int i = 0; i < ShipsSizeStr::LargeShip; i++) {
							LogicBoard[x + i][y] = 4;
							Ships.LargeShips--;
							return;
						}
					}
				}
				else {
					for (int i = 0; i < ShipsSizeStr::LargeShip; i++) {
						if (LogicBoard[x][y + i] != 2) {
							break;
						}
						else {
							Flouded = true;
						}
					}
					if (Flouded) {
						for (int i = 0; i < ShipsSizeStr::LargeShip; i++) {
							LogicBoard[x][y + i] = 4;
							Ships.LargeShips--;
							return;
						}
					}
				}
			}
			xCorr = false;
			yCorr = false;
		}
		if (Ships.MediumShips > 0) {
			for (int i = 0; i < 2; i++) {
				if (Ships.MediumShipsPos[i][0] == x) {
					xCorr = true;
				}
				if (Ships.MediumShipsPos[i][1] == y) {
					yCorr = true;
				}
				if (xCorr && yCorr) {
					break;
				}
				else {
					xCorr = false;
					yCorr = false;
				}
			}
			if (xCorr && yCorr) {
				for (int j = 0; j < 2; j++) {
					if (Ships.MediumShipsPos[j][2] == 0) {
						for (int i = 0; i < ShipsSizeStr::MediumShip; i++) {
							if (LogicBoard[x + i][y] != 2) {
								break;
							}
							else {
								Flouded = true;
							}
						}
						if (Flouded) {
							for (int i = 0; i < ShipsSizeStr::MediumShip; i++) {
								LogicBoard[x + i][y] = 4;
								Ships.MediumShips--;
								return;
							}
						}
					}
					else {
						for (int i = 0; i < ShipsSizeStr::MediumShip; i++) {
							if (LogicBoard[x][y + i] != 2) {
								break;
							}
							else {
								Flouded = true;
							}
						}
						if (Flouded) {
							for (int i = 0; i < ShipsSizeStr::MediumShip; i++) {
								LogicBoard[x][y + i] = 4;
								Ships.MediumShips--;
								return;
							}
						}
					}
				}
			}
		}
		if (Ships.Ships > 0) {
			for (int i = 0; i < 3; i++) {
				if (Ships.ShipsPos[i][0] == x) {
					xCorr = true;
				}
				if (Ships.ShipsPos[i][1] == y) {
					yCorr = true;
				}
				if (xCorr && yCorr) {
					break;
				}
				else {
					xCorr = false;
					yCorr = false;
				}
			}
			if (xCorr && yCorr) {
				for (int j = 0; j < 3; j++) {
					if (Ships.ShipsPos[j][2] == 0) {
						for (int i = 0; i < ShipsSizeStr::Ship; i++) {
							if (LogicBoard[x + i][y] != 2) {
								break;
							}
							else {
								Flouded = true;
							}
						}
						if (Flouded) {
							for (int i = 0; i < ShipsSizeStr::Ship; i++) {
								LogicBoard[x + i][y] = 4;
								Ships.Ships--;
								return;
							}
						}
					}
					else {
						for (int i = 0; i < ShipsSizeStr::Ship; i++) {
							if (LogicBoard[x][y + i] != 2) {
								break;
							}
							else {
								Flouded = true;
							}
						}
						if (Flouded) {
							for (int i = 0; i < ShipsSizeStr::Ship; i++) {
								LogicBoard[x][y + i] = 4;
								Ships.Ships--;
								return;
							}
						}
					}
				}
			}
		}
		if (Ships.SmallShips > 0) {
			for (int i = 0; i < 4; i++){
				if (Ships.SmallShipsPos[i][0] == x) {
					xCorr = true;
				}
				if (Ships.SmallShipsPos[i][1] == y) {
					yCorr = true;
				}
				if (xCorr && yCorr) {
					break;
				}
				else {
					xCorr = false;
					yCorr = false;
				}
			}
			if (xCorr && yCorr) {
				for (int j = 0; j < 4; j++) {
					if (Ships.SmallShipsPos[j][2] == 0) {
						for (int i = 0; i < ShipsSizeStr::SmallShip; i++) {
							if (LogicBoard[x + i][y] != 2) {
								break;
							}
							else {
								Flouded = true;
							}
						}
						if (Flouded) {
							for (int i = 0; i < ShipsSizeStr::SmallShip; i++) {
								LogicBoard[x + i][y] = 4;
								Ships.SmallShips--;
								return;
							}
						}
					}
					else {
						for (int i = 0; i < ShipsSizeStr::SmallShip; i++) {
							if (LogicBoard[x][y + i] != 2) {
								return;
							}
							else {
								Flouded = true;
							}
						}
						if (Flouded) {
							for (int i = 0; i < ShipsSizeStr::SmallShip; i++) {
								LogicBoard[x][y + i] = 4;
								Ships.SmallShips--;
								return;
							}
						}
					}
				}
			}
		}
		if (Ships.Boats > 0) {
			for (int i = 0; i < 5; i++) {
				if (Ships.BoatsPos[i][0] == x) {
					xCorr = true;
				}
				if (Ships.BoatsPos[i][1] == y) {
					yCorr = true;
				}
				if (xCorr && yCorr) {
					break;
				}
				else {
					xCorr = false;
					yCorr = false;
				}
			}
			if (xCorr && yCorr) {
				if (LogicBoard[x][y] != 2) {
					continue;
				}
				else {
					Flouded = true;
				}	
				if (Flouded) {
					LogicBoard[x][y] = 4;
					Ships.Boats--;
					return;
				}
			}
		}
		return;
	}
}

//						ONLY FOR DEBAG!!!!

void GameBoard::ShowPos() {
	for (int i = 0; i < 2; i++) {
		cout << Ships.BoatsPos[0][i] << " ";
	}
	cout << endl;
}