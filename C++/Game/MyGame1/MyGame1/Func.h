#pragma once
//------------------����̨����------------------------
void gotoxy(short x, short y);//����ƶ�
void gotoxy(COORD pos);//����ƶ�
COORD getxy();//����������ʱ��λ��
void HideCursor();
void ShowCursor();
void DeleteLine(short row);// ɾ��ĳ�� (��0��ʼ)
void ClearLine(short row);// ���ĳ�� (��0��ʼ)
void ClearScreen(); // ����

//---------------------����------------------------
char* AgeToWord(long long age);//������(����)ת��Ϊ����(�ַ���)
void DrawBorder();
void PrintWordCenter(short y, string str);
void TablePrint(short y, int n, int m, string *strArr);