#include <iostream>
#include <cstring>
using namespace std;
char Change[10][10] = {
	{ 'z', 'e', 'r', 'o', '\0' },
	{ 'o', 'n', 'e', '\0' },
	{ 't', 'w', 'o', '\0' },
	{ 't', 'h', 'r', 'e', 'e', '\0' },
	{ 'f', 'o', 'u', 'r', '\0' },
	{ 'f', 'i', 'v', 'e', '\0' },
	{ 's', 'i', 'x', '\0' },
	{ 's', 'e', 'v', 'e', 'n', '\0' },
	{ 'e', 'i', 'g', 'h', 't', '\0' },
	{ 'n', 'i', 'n', 'e', '\0' }
};
struct Equation
{
	char equa[50];
	char answer[20];
	int add1, add2, ans;
	struct Equation *next;
};
struct Equation *head;
void GetNum(char a[],int *b)
{
	*b = -1;
	char ch[10];
	int p = 0,q = 0;
	while (a[0] != ' ' && a[0] != '\0')
	{
		ch[p++] = a[0];
		for (int m = 0; a[m] != '\0'; m++)
			a[m] = a[m + 1];
	}
	ch[p] = '\0';
	for (int m = 0; a[m] != '\0'; m++)
		a[m] = a[m + 1];
	if (ch[0] == '+' || ch[0] == '=')
		return;
	else
		for (int i = 0; i < 10; i++)
			if (strcmp(ch, Change[i]) == 0)
				*b = i;
}
void GetEqua(char a[])
{
	char ch;
	ch = getchar();
	int i = 0;
	while (ch != 10)
	{
		a[i++] = ch;
		ch = getchar();
	}
	for (; i < 50;i++)
		a[i] = '\0';
}
void Copy(char a[], char b[])
{
	int z;
	for (z = 0; b[z] != '\0'; z++)
		a[z] = b[z];
	a[z] = '\0';
}
void GetEng(int a, char b[])
{
	int n[3];
	for (int i = 0; i < 3; i++)
	{
		n[i] = a % 10;
		a /= 10;
	}
	if (n[2] == 0 && n[1] == 0)
	{
		int m = 0, i;
		for (i = 0; Change[n[0]][i] != '\0'; m++, i++)
			b[m] = Change[n[0]][i];
		b[m] = '\0';
	}
	else if (n[2] == 0)
	{
		int m = 0, i;
		for (i = 0; Change[n[1]][i] != '\0'; m++, i++)
			b[m] = Change[n[1]][i];
		b[m++] = ' ';
		for (i = 0; Change[n[0]][i] != '\0'; m++, i++)
			b[m] = Change[n[0]][i];
		b[m] = '\0';
	}
	else if (n[2] != 0)
	{
		int m = 0, i;
		for (i = 0; Change[n[2]][i] != '\0'; m++, i++)
			b[m] = Change[n[2]][i];
		b[m++] = ' ';
		for (i = 0; Change[n[1]][i] != '\0'; m++, i++)
			b[m] = Change[n[1]][i];
		b[m++] = ' ';
		for (i = 0; Change[n[0]][i] != '\0'; m++, i++)
			b[m] = Change[n[0]][i];
		b[m] = '\0';
	}
}
void Input()
{
	struct Equation *p,*q;
	int j = 0;
	head = 0;
	char equa[50];
	GetEqua(equa);
	while (strcmp(equa, "zero + zero =") != 0)
	{
		j++;
		p = new Equation;
		Copy(p->equa,equa);
		int num[3], o = 0;
		do
		{
			GetNum(equa, &num[o]);
		} while (num[o++] != -1);
		if (o == 2)
			p->add1 = num[0];
		else if (o == 3)
			p->add1 = num[0] * 10 + num[1];
		o = 0;
		do
		{
			GetNum(equa, &num[o]);
		} while (num[o++] != -1);
		if (o == 2)
			p->add2 = num[0];
		else if (o == 3)
			p->add2 = num[0] * 10 + num[1];
		cout << p->add1 << p->add2;
		p->ans = p->add1 + p->add2;
		GetEng(p->ans, p->answer);
		if (j == 1)head = p;
		else q->next = p;
		q = p;
		GetEqua(equa);
	}
	p->next = 0;
}
void Answer()
{
	struct Equation *p;
	p = head;
	while (p != 0)
	{
		cout << p->answer << endl;
		p = p->next;
	}
	cout << "zero" << endl;
}
void main()
{
	cout << "Please input some equation :" << endl;
	Input();
	Answer();
}