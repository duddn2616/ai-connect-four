#include <iostream>
#include <sstream>
#include <cstring>

#include "Main.h"

using namespace std;

stringstream ss;

int last_put, result;
const int row = 6, col = 7, INF = 1000;
char board[row][col+1];
bool my_turn, game_over;

void Initialize() {
	for (int i = 0; i < row; ++i) {
		memset(board[i], '.', col*sizeof(board[i][0]));
	}

	int input = 0;
	while (true) {
		PrintBoard();
		cout << " ** Select the order **\n\n";
		cout << " You First(1), Computer First(2)\n\n";
		cout << " Select: ";
		cin >> input;
		if (input == 1) {
			my_turn = true; break;
		}
		else if (input == 2) {
			my_turn = false; break;
		}
	}
}

void PrintBoard() {
	system("cls");

	ss << "¦£ ";
	for (int c = 1; c <= row+1; ++c) {
		ss << c << ' ';
	}
	ss << "\b¦¤\n";
	for (int r = 0; r < row; ++r) {
		ss << "¦¢ ";
		for (int c = 0; c < col; ++c) {
			ss << board[r][c] << ' ';
		}
		ss << "\b¦¢\n";
	}
	ss << "¦¦";
	for (int c = 1; c <= row + 1; ++c) {
		ss << "¦¡¦¡";
	}
	ss << "¦¥\n";

	cout << ss.str();
	ss.str("");
}

int GetInput() {
	PrintBoard();
	if (my_turn) {
		int c;
		cout << " Your turn!\n\n";
		cout << " Select: ";
		cin >> c;
		return c;
	}
	else {
		int n;
		cout << " Computer's turn!\n\n";
		cout << " ** Choose Method **\n\n";
		cout << " MinMax(1), MCTS(2)\n\n";
		cout << " Select: ";
		cin >> n;
		if (n == 1) {
			return 1; // return Min_Max();
		}
		else if (n == 2) {
			return 2; // return MCTS();
		}
		else return INF;
	}
}

void PutStone(int c) {
	if (board[0][c-1] != '.' || c < 1 || c > 7) {
		return;
	}
	for (int r = row-1; r >= 0; --r) {
		if (board[r][c-1] == '.') {
			board[r][c-1] = my_turn ? 'O' : 'X';
			my_turn = !my_turn;
			return;
		}
	}
}

bool CheckFour(int r, int c) {
	return false;
}

int main() {
	Initialize();

	while (!game_over) {
		PutStone(GetInput());
	}

	return 0;
}