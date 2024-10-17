#include <iostream>
#include <Windows.h>

#include "GameBoard.h"


using namespace std;

int main() {
	srand(time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	GameBoard PlayerBoard;
	bool autoPlaceShip;

	cout << "Ви хочете у ручну виставляти кораблі чи автоматично?(1 для автоматичного розташування 0 для ручного)|\n|:";
	cin >> autoPlaceShip;
	cout << endl;

	while (PlayerBoard.ShipCount != 35) {
		PlayerBoard.placeShip(autoPlaceShip);
	}

	PlayerBoard.BoardChangeStatus();
	PlayerBoard.showBoard();
	cout << "Well Done" << endl;
}