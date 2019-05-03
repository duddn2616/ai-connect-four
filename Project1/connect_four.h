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
class OutOfRangeException : IllegalInputException {};
class FullColumnException : IllegalInputException {};
class GameOverException {};

class ConnectFour {
public:
	class ConnectFourBuilder;
	ConnectFour();
	~ConnectFour();
	
	bool is_player_turn() const;
	void switch_turn();
	ConnectFourBlockColor::Color get_player_color() const;
	void set_player_color();
	ConnectFourBlockColor::Color get_opponent_color() const;
	void append_error_message(string appended_string);
	void flush_error_message();
	int get_last_put() const;
	void set_last_put();

	void Initialize();
	void PrintBoard();
	int GetInput();
	void PutStone(int col);
	bool CheckFour(int row, int col);

private:
	bool player_turn_;
	ConnectFourBlockColor::Color player_color_;
	string error_message_;
	ConnectFourBlock *block[kRow][kCol];
	int last_put_;
};

#endif