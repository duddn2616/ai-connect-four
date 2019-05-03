#include <iostream>
#include "connect_four.h"

ConnectFour* InitializeConnectFour() {
	ConnectFour *cf = new ConnectFour();

	while (true) {
		try {
			if (cf->Initialize()) return cf;
		}
		catch (NumberFormatException e) {
			cf->set_error_message("Error : Number value required!\n");
		}
		catch (SelectOutOfRangeException e) {
			cf->set_error_message("Error : Input out of range! (1-2)\n");
		}
		catch (IllegalInputException e) {
			cf->set_error_message("Error : Unknown input error!\n");
		}
	}
}

void StartConnectFour() {
	ConnectFour *cf = InitializeConnectFour();
	printf("Game Over\n");
}

int main() {
	StartConnectFour();

	return 0;
}