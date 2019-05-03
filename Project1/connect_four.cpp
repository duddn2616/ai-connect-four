#include "connect_four.h"

class ConnectFour::ConnectFourBuilder {
public:
	ConnectFourBuilder set_player_turn() {
		
	}
private:
	bool player_turn_ = true;
	ConnectFourBlockColor::Color player_color_ = ConnectFourBlockColor::kBlack;
	ConnectFourBlockColor::Color opponent_color_ = ConnectFourBlockColor::kWhite;
};

ConnectFour::ConnectFour()
	: last_put_(-1), error_message_("") {}

ConnectFour::~ConnectFour() {
	for (int r = 0; r < kRow; ++r) {
		for (int c = 0; c < kCol; ++c) {
			block[r][c] = new ConnectFourBlock();
		}
	}
}

bool ConnectFour::is_player_turn() const {
	return player_turn_;
}

void ConnectFour::switch_turn() {
	player_turn_ = !player_turn_;
}

ConnectFourBlockColor::Color ConnectFour::get_player_color() const {
	return player_color_;
}

void ConnectFour::set_player_color() {

}

void ConnectFour::Initialize() {
	for (int r = 0; r < kRow; ++r) {
		for (int c = 0; c < kCol; ++c) {
			block[r][c] = new ConnectFourBlock();
		}
	}

	int input = 0;
	while (true) {
		PrintBoard();
		cout << " ** Select the order **\n\n";
		cout << " You First(1), Computer First(2)\n\n";
		cout << " Select: ";
		cin >> input;
		if (input == 1) {
			player_turn_ = true; break;
		}
		else if (input == 2) {
			player_turn_ = false; break;
		}
	}
}

void ConnectFour::PrintBoard() {
	system("cls");

	string buffer = "";

	buffer += "¦£ ";
	for (int c = 1; c <= kRow+1; ++c) {
		buffer += '0' + c;
		buffer += ' ';
	}
	buffer += "\b¦¤\n";
	for (int r = 0; r < kRow; ++r) {
		buffer += "¦¢ ";
		for (int c = 0; c < kCol; ++c) {
			buffer += block[r][c];
			buffer += ' ';
		}
		buffer += "\b¦¢\n";
	}
	buffer += "¦¦";
	for (int c = 1; c <= kRow + 1; ++c) {
		buffer += "¦¡¦¡";
	}
	buffer += "¦¥\n";

	cout << buffer;
	buffer.clear();
}

int ConnectFour::GetInput() {
	PrintBoard();
	if (player_turn_) {
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
		else return kInf;
	}
}

void ConnectFour::PutStone(int c) {
	if (block[0][c-1] != '.' || c < 1 || c > 7) {
		return;
	}
	for (int r = kRow-1; r >= 0; --r) {
		if (block[r][c-1] == '.') {
			block[r][c-1] = player_turn_ ? 'O' : 'X';
			player_turn_ = !player_turn_;
			return;
		}
	}
}

bool ConnectFour::CheckFour(int r, int c) {
	return false;
}