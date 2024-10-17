#include <iostream>
#include "GameBoard.h"

using namespace std;

void GameBoard::showBoard() {
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

void GameBoard::putShip(int x, int y, bool horizontal, bool autoPlaceShips) {

}