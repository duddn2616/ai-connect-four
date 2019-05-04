#ifndef __ConnectFour__ConnectFourException__
#define __ConnectFour__ConnectFourException__

class ConnectFourException {
public:
	class IllegalInputException {};
	class NumberFormatException : IllegalInputException {};
	class FullColumnException : IllegalInputException {};
	class OutOfRangeException : IllegalInputException {};
	class ColumnOutOfRangeException : OutOfRangeException {};
	class SelectOutOfRangeException : OutOfRangeException {};
	class GameOverException {};
};
#endif