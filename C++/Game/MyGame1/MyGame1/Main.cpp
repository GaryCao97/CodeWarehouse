#include "stdafx.h"
#include "Func.h"
#include "Arr.h"
#include "Menu.h"
#include "MyPlayer.h"

int main() {
	//Message("«Î ‰»Î–’√˚123sadsda");
	WindowsProperty();
	InitMenpaiAndMaster();
	srand((unsigned int)time(0));
	PlayerCharacter pc;
	if (pc.isNew)goto start;
	else goto mainMenu;
start:
	Start();
	Create(pc);
mainMenu:
	switch (MainMenu(pc)) {
	case EXIT:
		goto EXit;
		break;
	case SETTING:
		goto setting;
		break;
	case PROPERTY:
		goto propertyMenu;
		break;
	case SCHOOL:
		goto schoolMenu;
		break;
	default:
		goto mainMenu;
		break;
	}
propertyMenu:
	switch (PropertyMenu(pc)) {
	case MAIN_MENU:
		goto mainMenu;
		break;
	case SETTING:
		goto setting;
		break;
	default:
		goto mainMenu;
		break;
	}
schoolMenu:
	switch (MenpaiMenu(pc)) {
	case MAIN_MENU:
		goto mainMenu;
		break;
	case SETTING:
		goto setting;
		break;
	default:
		goto mainMenu;
		break;
	}
setting:
	switch (SettingMenu(pc)) {
	case EXIT:
		goto EXit;
		break;
	case RESTART:
		goto start;
		break;
	default:
		goto mainMenu;
		break;
	}
EXit:
	return 0;
}