#include "connect_four_block.h"

ConnectFourBlock::ConnectFourBlock() : color_(ConnectFourBlockColor::kEmpty) {}

ConnectFourBlock::~ConnectFourBlock() {}

ConnectFourBlockColor::Color ConnectFourBlock::get_color() const {
	return color_;
}

bool ConnectFourBlock::set_color(ConnectFourBlockColor::Color &color) {
	this->color_ = color;
	return true;
}