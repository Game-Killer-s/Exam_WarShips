#include <iostream>
#include "GameBoard.h"

using namespace std;

void GameBoard::showBoard() {
	cout << "|Дошка гравця|\n|Кораблів живих:" << "|Дуже великих|" << Ships.LargeShips << "|Великих|" << Ships.MediumShips << "|Середніх|" << Ships.Ships << "|Маленьких|" << Ships.SmallShips << "|Крихітних|" << Ships.Boats << "|" << endl << endl;
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
				cin >> x >> y >> horizontal;
				if (x < 0 || x>9 || y < 0 || y>9) {
					cout << "Введіть коректні значення" << endl;
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::LargeShip; i++) {
							if (LogicBoard[y + i][x] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
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
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::LargeShip; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.LargeShips++;
				}
			}
			else if (Ships.MediumShips != 2) {
				BoardChangeStatus();
				showBoard();
				cout << "Напишіть \'x\' та \'y\' координати куди поставити кораблі та 0 для вертикального розміщення чи 1 для горизонтального|\n|:";
				cin >> x >> y >> horizontal;
				cout << endl;
				if (x < 0 || x>9 || y < 0 || y>9) {
					cout << "Введіть коректні значення" << endl;
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::MediumShip; i++) {
							if (LogicBoard[y + i][x] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
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
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::MediumShip; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.MediumShips++;
				}
			}
			else if (Ships.Ships != 3) {
				BoardChangeStatus();
				showBoard();
				cout << "Напишіть \'x\' та \'y\' координати куди поставити кораблі та 0 для вертикального розміщення чи 1 для горизонтального|\n|:";
				cin >> x >> y >> horizontal;
				cout << endl;
				if (x < 0 || x>9 || y < 0 || y>9) {
					cout << "Введіть коректні значення" << endl;
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::Ship; i++) {
							if (LogicBoard[y + i][x] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
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
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::Ship; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.Ships++;
				}
			}
			else if (Ships.SmallShips != 4) {
				BoardChangeStatus();
				showBoard();
				cout << "Напишіть \'x\' та \'y\' координати куди поставити кораблі та 0 для вертикального розміщення чи 1 для горизонтального|\n|:";
				cin >> x >> y >> horizontal;
				cout << endl;
				if (x < 0 || x>9 || y < 0 || y>9) {
					cout << "Введіть коректні значення" << endl;
					return;
				}
				else {
					if (horizontal == false) {
						for (int i = 0; i < GameBoard::ShipsSizeStr::SmallShip; i++) {
							if (LogicBoard[y + i][x] == 1) {
								cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
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
								return;
							}
						}
						for (int i = 0; i < GameBoard::ShipsSizeStr::SmallShip; i++) {
							LogicBoard[y][x + i] = 1;
							ShipCount++;
						}
					}
					Ships.SmallShips++;
				}
			}
			else if (Ships.Boats != 5) {
				BoardChangeStatus();
				showBoard();
				cout << "Напишіть \'x\' та \'y\' координати куди поставити кораблі\n|:";
				cin >> x >> y;
				cout << endl;
				if (x < 0 || x>9 || y < 0 || y>9) {
					cout << "Введіть коректні значення" << endl;
					return;
				}
				else {
					for (int i = 0; i < GameBoard::ShipsSizeStr::Boat; i++) {
						if (LogicBoard[y][x + i] == 1) {
							cout << "Ви не можете поставити корабель у місце де він вже присутній" << endl;
							return;
						}
					}
					for (int i = 0; i < GameBoard::ShipsSizeStr::Boat; i++) {
						LogicBoard[y][x + i] = 1;
						ShipCount++;
					}
					Ships.Boats++;
				}
			}
		}
	}
}