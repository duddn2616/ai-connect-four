#include <iostream>
#include "connect_four.h"

ConnectFour *cf;

void InitializeConnectFour() {
	cf = new ConnectFour();

	while (true) {
		try {
			cf->Initialize(); return;
		}
		catch (ConnectFourException::SelectOutOfRangeException e) {
			cf->set_error_message("** Error : Input out of range! (1-2) **");
		}
		catch (ConnectFourException::NumberFormatException e) {
			cf->set_error_message("** Error : Number value required! **");
		}
		catch (ConnectFourException::IllegalInputException e) {
			cf->set_error_message("** Error : Unknown input error! **");
		}
	}
}

int GetInput() {
	while (true) {
		try {
			return cf->GetInput();
		}
		catch (ConnectFourException::ColumnOutOfRangeException e) {
			cf->set_error_message("** Error : Input out of range! (1-7) **");
		}
		catch (ConnectFourException::NumberFormatException e) {
			cf->set_error_message("** Error : Number value required! **");
		}
		catch (ConnectFourException::IllegalInputException e) {
			cf->set_error_message("** Error : Unknown input error! **");
		}
	}
}

void PutStone(int input) {
	while (true) {
		try {
			cf->PutStone(input);
			return;
		}
		catch (ConnectFourException::FullColumnException e) {
			cf->set_error_message("** Error : Full Column! **");
			if (!cf->is_player_turn()) throw ConnectFourException::FatalErrorException();
			return;
		}
		catch (ConnectFourException::IllegalInputException e) {
			cf->set_error_message("** Error : Unknown input error! **");
			return;
		}
	}
}

void StartConnectFour() {
	InitializeConnectFour();
	while (true) {
		try {
			PutStone(GetInput());
		}
		catch (ConnectFourException::GameOverException e) {

		}
		catch (ConnectFourException::FatalErrorException e) {
			cout << " Fatal Error!\n";
			cout << " Computer has accessed full column...\n";
			break;
		}
		catch (...) {

		}
	}
}

int main() {
	StartConnectFour();

	delete cf;
	return 0;
}