
//---------------���̰����뵯���¼����ж�------------------------------

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

//---------------��Ϸ����------------------------------

enum GAME_PLACE{
	MAIN_MENU = 0,		// ������ 
	MENPAI = 1,			// ���ɽ��� 
	GUAJI = 2,			// �һ��������� 
	SHUXING = 3,		// ���Խ���
	BEIBAO = 4,			// ��������
};

//---------------����------------------------------ 

extern GAME_PLACE gamePlace;
extern char Masters[50][10];
extern char Origin[4][20];

//---------------����------------------------------

extern char* AgeToWord(long long age);//������(����)ת��Ϊ����(�ַ���)
extern int Random(int min, int max);
extern void PrintWordCenter(short y,char *string);
extern void HideCursor();
extern void ShowCursor();
extern void DeleteLine(short row);
extern void ClearLine(short row);
extern void ClearScreen(); // ����
