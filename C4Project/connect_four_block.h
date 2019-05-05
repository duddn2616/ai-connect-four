#ifndef __ConnectFour__ConnectFourBlock__
#define __ConnectFour__ConnectFourBlock__

namespace ConnectFourBlockColor {
	enum Color {
		kEmpty, kBlack, kWhite
	};
}

class ConnectFourBlock {
public:
	ConnectFourBlock();
	~ConnectFourBlock();

	ConnectFourBlockColor::Color get_color() const;
	bool set_color(ConnectFourBlockColor::Color color);
	char get_color_char() const;
	bool is_empty() const;

private:
	ConnectFourBlockColor::Color color_;
};

#endif