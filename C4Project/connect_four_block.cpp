#include "connect_four_block.h"

ConnectFourBlock::ConnectFourBlock() : color_(ConnectFourBlockColor::kEmpty) {}

ConnectFourBlock::~ConnectFourBlock() {}

ConnectFourBlockColor::Color ConnectFourBlock::get_color() const {
	return color_;
}

bool ConnectFourBlock::set_color(ConnectFourBlockColor::Color color) {
	this->color_ = color;
	return true;
}

char ConnectFourBlock::get_color_char() const {
	switch (color_) {
	case ConnectFourBlockColor::Color::kEmpty : return '.';
	case ConnectFourBlockColor::Color::kBlack : return 'X';
	case ConnectFourBlockColor::Color::kWhite : return 'O';
	}
	return '.';
}

bool ConnectFourBlock::is_empty() const {
	if (color_ == ConnectFourBlockColor::Color::kEmpty) return true;
	return false;
}