#include <iostream>
#include "connect_four.h"

void StartConnectFour() {
	cout << " ** Select the order **\n\n";
	cout << " You First(1), Computer First(2)\n\n";
	cout << " Select: ";
	cin >> input;


	ConnectFour cf;
	cf.Initialize();

	while(!cf.game_over_) {
		cf.PutStone(cf.GetInput());
	}
}

int main() {
	StartConnectFour();

	return 0;
}