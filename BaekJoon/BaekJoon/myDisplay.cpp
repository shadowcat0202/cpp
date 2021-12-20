#include "myDisplay.h"

void Wait() {
	char c;
	while (true) {
		if (_kbhit()) {
			c = _getch();
			system("cls");
			break;
		}
	}
}