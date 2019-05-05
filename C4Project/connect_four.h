#ifndef __ConnectFour__ConnectFour__
#define __ConnectFour__ConnectFour__

#include <iostream>
#include <string>
#include <cstring>

#include "connect_four_block.h"
#include "connect_four_exception.h"

using std::cout;
using std::cin;
using std::string;


static const int kRow = 6, kCol = 7, kInf = 1000;

class ConnectFour {
public:
	ConnectFour();
	~ConnectFour();
	
	bool is_player_turn() const;
	ConnectFourBlockColor::Color get_player_color() const;
	void set_player_color(ConnectFourBlockColor::Color color);
	ConnectFourBlockColor::Color get_opponent_color() const;
	void set_error_message(string error_message);
	void append_print_buffer(char appended_char);
	void append_print_buffer(string appended_string);
	int get_last_put() const;
	void set_last_put(int col);

	void Initialize();
	void PrintBoard();
	int GetInput();
	void PutStone(int col);
	bool CheckFour(int row, int col);

private:
	char get_first_char(string input);
	void check_input_validity(int from, int to, bool column);
	void switch_turn();
	void init_board();
	void init_order();
	void init_method();
	void flush_error_message();
	void flush_print_buffer();

	string input;
	bool is_board_init_;
	bool is_order_init_;
	bool player_turn_;
	bool minimax_;
	ConnectFourBlockColor::Color player_color_;
	string error_message_;
	string print_buffer_;
	ConnectFourBlock *block[kRow][kCol];
	int last_put_;
};

#endif