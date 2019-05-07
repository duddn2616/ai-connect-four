#include "connect_four.h"

ConnectFour::ConnectFour()
	: input(""), is_board_init_(false), is_order_init_(false),
	error_message_("\n\n"), print_buffer_(""), last_put_(-1) {}

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

char ConnectFour::get_first_char(string input) {
	if (input.empty()) return ' ';
	return input[0];
}

void ConnectFour::check_input_validity(int from, int to, bool column) {
	char from_ch = from + '0';
	char to_ch = to + '0';
	char first_char = get_first_char(input);
	if (first_char < '0' || first_char > '9') {
		throw ConnectFourException::NumberFormatException();
	}
	else if (first_char < from_ch || first_char > to_ch) {
		if (column)
			throw ConnectFourException::ColumnOutOfRangeException();
		else 
			throw ConnectFourException::SelectOutOfRangeException();
	}
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
	flush_error_message();
	error_message_ = error_message + "\n\n";
}

void ConnectFour::append_print_buffer(char appended_char) {
	print_buffer_ += appended_char;
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

void ConnectFour::Initialize() {
	if (!is_board_init_) init_board();
	if (!is_order_init_) init_order();
	init_method();
}

void ConnectFour::init_board() {
	for (int r = 0; r < kRow; ++r) {
		for (int c = 0; c < kCol; ++c) {
			block[r][c] = new ConnectFourBlock();
		}
	}

	is_board_init_ = true;
}

void ConnectFour::init_order() {
	char first_char = 0;
	PrintBoard();
	cout << " ** Select the order **\n\n";
	cout << " You First(1), Computer First(2)\n\n";
	cout << " Select: ";
	cin >> input;
	check_input_validity(1, 2, false);

	switch (get_first_char(input)) {
	case '1':
		player_turn_ = true;
		set_player_color(ConnectFourBlockColor::Color::kBlack);
		break;
	case '2':
		player_turn_ = false;
		set_player_color(ConnectFourBlockColor::Color::kWhite);
		break;
	}

	is_order_init_ = true;
}

void ConnectFour::init_method() {
	char first_char = 0;
	PrintBoard();
	cout << " ** Select AI Decision Rule **\n\n";
	cout << " Minimax + Alpha-beta Pruning (1),\n";
	cout << " Monte Carlo Tree Search (2)\n\n";
	cout << " Select: ";
	cin >> input;
	check_input_validity(1, 2, false);

	switch (get_first_char(input)) {
	case '1':
		is_minimax_ = true;
		minimax = new Minimax();
		break;
	case '2':
		is_minimax_ = false;
		// MCTS *mtcs = new MCTS();
		break;
	}
}

void ConnectFour::PrintBoard() {
	system("cls");

	flush_print_buffer();
	append_print_buffer(error_message_);
	set_error_message("");

	append_print_buffer(' ');
	for (int c = 1; c <= kRow+1; ++c) {
		append_print_buffer(c + '0');
		append_print_buffer(' ');
	}
	append_print_buffer(" \n");
	for (int r = 0; r < kRow; ++r) {
		append_print_buffer(' ');
		for (int c = 0; c < kCol; ++c) {
			append_print_buffer(block[r][c]->get_color_char());
			append_print_buffer(' ');
		}
		append_print_buffer(" \n");
	}
	append_print_buffer(" \n");

	cout << print_buffer_;
}

int ConnectFour::GetInput() {
	PrintBoard();
	if (is_player_turn()) {
		cout << " Your turn!\n\n";
		cout << " Select: ";
		cin >> input;
		check_input_validity(1, kCol, true);
		return last_put_ = get_first_char(input) - '0';
	}
	else {
		cout << " Computer's turn!\n\n";
		cout << " Computer is thinking..\n\n";
		if (is_minimax_)
			return minimax->GetInput(last_put_); // Minimax
		else return 2; // MCTS
	}
	return -1;
}

void ConnectFour::PutStone(int col) {
	if (!block[0][col-1]->is_empty()) {
		throw ConnectFourException::FullColumnException();
	}
	for (int row = kRow-1; row >= 0; --row) {
		if (block[row][col-1]->is_empty()) {
			block[row][col-1]->set_color(
				is_player_turn()
				&& get_player_color() == ConnectFourBlockColor::Color::kBlack
				||
				!is_player_turn()
				&& get_opponent_color() == ConnectFourBlockColor::Color::kBlack
				?
				ConnectFourBlockColor::Color::kBlack
				: ConnectFourBlockColor::Color::kWhite);
			player_turn_ = !player_turn_;
			return;
		}
	}
}

bool ConnectFour::CheckFour(int r, int c) {
	return false;
}