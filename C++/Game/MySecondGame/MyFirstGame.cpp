
#include "stdafx.h"
#include "Setting.h"
#include "MyPlayer.h"
#include "Menu.h"

int main(){
	HideCursor();
	
	SetConsoleTitle("нр╣дсно╥");
	PlayerCharacter pc;
	Start();
	pc.Origin = ChoiceOrigin();

	//CloseHandle(hOut);
	return 0;
}
