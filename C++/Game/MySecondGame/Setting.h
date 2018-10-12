
//---------------键盘按下与弹起事件的判断------------------------------

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

//---------------游戏界面------------------------------

enum GAME_PLACE{
	MAIN_MENU = 0,		// 主界面 
	MENPAI = 1,			// 门派界面 
	GUAJI = 2,			// 挂机修炼界面 
	SHUXING = 3,		// 属性界面
	BEIBAO = 4,			// 背包界面
};

//---------------变量------------------------------ 

extern GAME_PLACE gamePlace;
extern char Masters[50][10];
extern char Origin[4][20];

//---------------函数------------------------------

extern char* AgeToWord(long long age);//将年龄(数字)转化为年龄(字符串)
extern int Random(int min, int max);
extern void PrintWordCenter(short y,char *string);
extern void HideCursor();
extern void ShowCursor();
extern void DeleteLine(short row);
extern void ClearLine(short row);
extern void ClearScreen(); // 清屏
