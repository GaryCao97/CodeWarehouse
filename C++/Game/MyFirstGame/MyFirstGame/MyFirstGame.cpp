
#include "stdafx.h"
#include "Setting.h"
#include "MyPlayer.h"
#include "Menu.h"

int main(){
	HideCursor();
	
	SetConsoleTitleW(L"�ҵ���Ϸ"); 
	PlayerCharacter pc;
	Start();
	pc.Origin = ChoiceOrigin();

	//CloseHandle(hOut);
	return 0;
}
