#include <iostream>
#include <Windows.h>

#include "GameBoard.h"


using namespace std;

int main() {
	srand(time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	GameBoard PlayerBoard,
		ComputerBoard;
	bool autoPlaceShip,
		PlayerSuccessShoot=false,
		ComputerSuccessShoot=false;
	int CompShootX,
		CompShootY,
		CompShootDirection,
		CompMissShot;

	cout << "Ви хочете у ручну виставляти кораблі чи автоматично?(1 для автоматичного розташування 0 для ручного)|\n|:";
	//cout << "You want to place ship by hand or automatic?(1 for automatic placement and 0 for placement by hand)|\n|:";
	cin >> autoPlaceShip;
	cout << endl;

	while (PlayerBoard.ShipCount != 35) {
		PlayerBoard.placeShip(autoPlaceShip);
	}
	while (ComputerBoard.ShipCount != 35) {
		ComputerBoard.placeShip(1);
	}
	while (true) {
		PlayerSuccessShoot = false;
		ComputerSuccessShoot = false;
		PlayerBoard.BoardChangeStatus();
		PlayerBoard.showBoard();
		ComputerBoard.BoardChangeStatus();
		ComputerBoard.showShadowBoard();
		while (!PlayerSuccessShoot) {
			ComputerBoard.shoot(&PlayerSuccessShoot);
		}
		while (!ComputerSuccessShoot) {
			PlayerBoard.CompShoot(&ComputerSuccessShoot,&CompShootX,&CompShootY,&CompShootDirection,&CompMissShot);
		}
	}
	ComputerBoard.showBoard();
	ComputerBoard.ShowPos();
	cout << "Well Done" << endl;
}