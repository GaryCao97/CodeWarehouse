
#include "Main.h"
#include "Var.h"

int ChessBoard[19][19];
short Top = 3, Left = 6;
char BlackChess[3] = "¡ð";
char WhiteChess[3] = "¡ñ";
int Direct[8][2] = {
	{ 1,1 },
	{ 1,0 },
	{ 1,-1 },
	{ 0,-1 },
	{ -1,-1 },
	{ -1,0 },
	{ -1,1 },
	{ 0,1 }
};