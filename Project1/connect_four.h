#ifndef __ConnectFour__ConnectFour__
#define __ConnectFour__ConnectFour__

#include <iostream>
#include <string>
#include <cstring>

#include "connect_four_block.h"

using std::cout;
using std::cin;
using std::string;

static int input;
static const int kRow = 6, kCol = 7, kInf = 1000;

class IllegalInputException {};
class NumberFormatException : IllegalInputException {};
class FullColumnException : IllegalInputException {};
class OutOfRangeException : IllegalInputException {};
class ColumnOutOfRangeException : OutOfRangeException {};
class SelectOutOfRangeException : OutOfRangeException {};
class GameOverException {};

class ConnectFour {
public:
	ConnectFour();
	~ConnectFour();
	
	bool is_player_turn() const;
	void switch_turn();
	ConnectFourBlockColor::Color get_player_color() const;
	void set_player_color(ConnectFourBlockColor::Color color);
	ConnectFourBlockColor::Color get_opponent_color() const;
	void set_error_message(string error_message);
	void append_print_buffer(string appended_string);
	int get_last_put() const;
	void set_last_put(int col);

	bool Initialize();
	void PrintBoard();
	int GetInput();
	void PutStone(int col);
	bool CheckFour(int row, int col);

private:
	void initialize_board();
	void flush_error_message();
	void flush_print_buffer();

	bool initialized_;
	bool player_turn_;
	ConnectFourBlockColor::Color player_color_;
	string error_message_;
	string print_buffer_;
	ConnectFourBlock *block[kRow][kCol];
	int last_put_;
};

#endif