
#include "Main.h"
#include "Func.h"

int main() {
	system("MODE con: COLS=120 LINES=50");
	srand((unsigned int)time(0));
	HideCursor();
	PlayerCharacter pc;
	GamePlaying(pc);
	return 0;
}