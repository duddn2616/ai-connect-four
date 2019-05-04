#include "connect_four.h"

ConnectFour::ConnectFour()
	: initialized_(false), error_message_(""), last_put_(-1) {}

ConnectFour::~ConnectFour() {
	for (int r = 0; r < kRow; ++r) {
		for (int c = 0; c < kCol; ++c) {
			delete block[r][c];
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

void ConnectFour::set_player_color(ConnectFourBlockColor::Color color) {
	player_color_ = color;
}

ConnectFourBlockColor::Color ConnectFour::get_opponent_color() const {
	return player_color_ == ConnectFourBlockColor::kBlack
		? ConnectFourBlockColor::kWhite : ConnectFourBlockColor::kBlack;
}

void ConnectFour::set_error_message(string error_message) {
	if (error_message.empty()) return;
	flush_error_message();
	error_message_ = error_message;
}

void ConnectFour::append_print_buffer(string appended_string) {
	if (appended_string.empty()) return;
	print_buffer_ += appended_string;
}

void ConnectFour::flush_error_message() {
	if (!error_message_.empty()) error_message_.clear();
}

void ConnectFour::flush_print_buffer() {
	if (!print_buffer_.empty()) print_buffer_.clear();
}

int ConnectFour::get_last_put() const {
	return last_put_;
}
void ConnectFour::set_last_put(int col) {
	last_put_ = col;
}

bool ConnectFour::Initialize() {
	if (!initialized_) initialize_board();

	string input = "";
	char first_char = 0;
	PrintBoard();
	cout << " ** Select the order **\n\n";
	cout << " You First(1), Computer First(2)\n\n";
	cout << " Select: ";
	cin >> input;
	first_char = input[0];
	
	switch (first_char) {
	case '1':
		player_turn_ = true;
		set_player_color(ConnectFourBlockColor::Color::kBlack); return true;
	case '2':
		player_turn_ = false;
		set_player_color(ConnectFourBlockColor::Color::kWhite); return true;
	default: throw ConnectFourException::NumberFormatException();
	}
}

void ConnectFour::initialize_board() {
	for (int r = 0; r < kRow; ++r) {
		for (int c = 0; c < kCol; ++c) {
			block[r][c] = new ConnectFourBlock();
		}
	}
	initialized_ = true;
}

void ConnectFour::PrintBoard() {/*
	system("cls");

	flush_print_buffer();
	append_print_buffer(error_message_);

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
	buffer.clear();*/
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

void ConnectFour::PutStone(int c) {/*
	if (block[0][c-1] != '.' || c < 1 || c > 7) {
		return;
	}
	for (int r = kRow-1; r >= 0; --r) {
		if (block[r][c-1] == '.') {
			block[r][c-1] = player_turn_ ? 'O' : 'X';
			player_turn_ = !player_turn_;
			return;
		}
	}*/
}

bool ConnectFour::CheckFour(int r, int c) {
	return false;
}