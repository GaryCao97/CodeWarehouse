#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define OVERFLOW    -2
typedef int Status;
typedef char ElemType;
typedef struct{
	char *ch;
	int length;
}HString;
void InitString(HString &T);//初始化(产生空串)字符串T
Status StrAssign(HString &T, char *chars);//生成一个其值等于串常量chars的串T
Status StrCopy(HString &T, HString S);//复制串S
Status StrEmpty(HString S);//判断串S是否为空
int StrLength(HString S);//返回S的元素个数，称为串的长度
int StrCompare(HString S, HString T);//若S>T，则返回>0；若S<T，则返回<0；若S=T，则返回=0
Status ClearString(HString &S);//将S清空
Status Concat(HString &T, HString S1, HString S2);//链接两个串
Status SubString(HString &Sub, HString S, int pos, int len);//返回串S的第pos个字符起长度为len的子串
int Index(HString S, HString T, int pos);//返回主串S存在的pos位置之后第一次出现的子串T的位置
Status Replace(HString &S, HString T, HString V);//用V替换S中所有T
Status StrInsert(HString &S, int pos, HString T);//S中pos后插入T
Status StrDelete(HString &S, int pos, int len);//S中pos后删除len个字符

void InitString(HString &T){
	T.length = 0;
	T.ch = NULL;
}
Status StrAssign(HString &T, char *chars){ 
	int i, j;
	if (T.ch)
		free(T.ch);
	i = strlen(chars);
	if (!i)	{
		T.ch = NULL;
		T.length = 0;
	}
	else{
		T.ch = (char*)malloc(i*sizeof(char));
		if (!T.ch)
			exit(OVERFLOW);
		for (j = 0; j<i; j++)
			T.ch[j] = chars[j];
		T.length = i;
	}
	return OK;
}
Status StrCopy(HString &T, HString S){ /* 初始条件:串S存在。操作结果: 由串S复制得串T */
	int i;
	if (T.ch)
		free(T.ch);
	T.ch = (char*)malloc(S.length*sizeof(char));
	if (!T.ch)
		exit(OVERFLOW);
	for (i = 0; i<S.length; i++)
		T.ch[i] = S.ch[i];
	T.length = S.length;
	return OK;
}
Status StrEmpty(HString S){ /* 初始条件: 串S存在。操作结果: 若S为空串,则返回TRUE,否则返回FALSE */
	if (S.length == 0 && S.ch == NULL)
		return TRUE;
	else
		return FALSE;
}
int StrCompare(HString S, HString T){ /* 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
	int i;
	for (i = 0; i < S.length && i < T.length; ++i)
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	return S.length - T.length;
}
int StrLength(HString S){ /* 返回S的元素个数,称为串的长度 */
	return S.length;
}
Status ClearString(HString &S){ /* 将S清为空串 */
	if (S.ch){
		free(S.ch);
		S.ch = NULL;
	}
	S.length = 0;
	return OK;
}
Status Concat(HString &T, HString S1, HString S2){ /* 用T返回由S1和S2联接而成的新串 */
	int i;
	if (T.ch)
		free(T.ch);
	T.length = S1.length + S2.length;
	T.ch = (char *)malloc(T.length*sizeof(char));
	if (!T.ch)
		exit(OVERFLOW);
	for (i = 0; i<S1.length; i++)
		T.ch[i] = S1.ch[i];
	for (i = 0; i<S2.length; i++)
		T.ch[S1.length + i] = S2.ch[i];
	return OK;
}
Status SubString(HString &Sub, HString S, int pos, int len){
	int i;
	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
		return ERROR;
	if (Sub.ch)
		free(Sub.ch);
	if (!len){
		Sub.ch = NULL;
		Sub.length = 0;
	}
	else{
		Sub.ch = (char*)malloc(len*sizeof(char));
		if (!Sub.ch)
			exit(OVERFLOW);
		for (i = 0; i <= len - 1; i++)
			Sub.ch[i] = S.ch[pos - 1 + i];
		Sub.length = len;
	}
	return OK;
}
int Index(HString S, HString T, int pos){
	int n, m, i;
	HString sub;
	InitString(sub);
	if (pos>0){
		n = StrLength(S);
		m = StrLength(T);
		i = pos;
		while (i <= n - m + 1){
			SubString(sub, S, i, m);
			if (StrCompare(sub, T) != 0)
				++i;
			else
				return i;
		}
	}
	return 0;
}
int Index_KMP(HString S, HString T, int pos) {
	// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的
	int *next = (int *)malloc((T.length + 1) * sizeof(int));
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i<T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else j = next[j];
	}
	i = pos;
	j = 1;
	while (i < S.length && j < T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			++i;
			++j;
		}
		else j = next[j];
	}
	if (j >= T.length) return  i - (T.length - 1);
	else return 0;
} 
Status StrInsert(HString &S, int pos, HString T){
	int i;
	if (pos<1 || pos>S.length + 1)
		return ERROR;
	if (T.length){
		S.ch = (char*)realloc(S.ch, (S.length + T.length)*sizeof(char));
		if (!S.ch)
			exit(OVERFLOW);
		for (i = S.length - 1; i >= pos - 1; --i)
			S.ch[i + T.length] = S.ch[i];
		for (i = 0; i<T.length; i++)
			S.ch[pos - 1 + i] = T.ch[i];
		S.length += T.length;
	}
	return OK;
}
Status StrDelete(HString &S, int pos, int len){
	int i;
	if (S.length<pos + len - 1)
		exit(ERROR);
	for (i = pos - 1; i <= S.length - len; i++)
		S.ch[i] = S.ch[i + len];
	S.length -= len;
	S.ch = (char*)realloc(S.ch, S.length*sizeof(char));
	return OK;
}
Status Replace(HString &S, HString T, HString V){
	int i = 1;
	if (StrEmpty(T))
		return ERROR;
	do
	{
		i = Index(S, T, i);
		if (i)
		{
			StrDelete(S, i, StrLength(T));
			StrInsert(S, i, V);
			i += StrLength(V);
		}
	} while (i);
	return OK;
}
void StrPrint(HString T){
	int i;
	for (i = 0; i<T.length; i++)
		printf("%c", T.ch[i]);
	printf("\n");
}

int main() {
	HString Str1, Str2, Sub, Ans;
	InitString(Str1);
	InitString(Str2);
	InitString(Sub);
	InitString(Ans);
	char c1, c2, chars[10000], op;
	int pos, len;
	do {
		system("cls");
		cout << "请选择要进行的操作:" << endl;
		cout << "串的长度-------1" << endl;
		cout << "串的比较-------2" << endl;
		cout << "串的子串-------3" << endl;
		cout << "串的连接-------4" << endl;
		cout << "子串的删除-----5" << endl;
		cout << "串的定位-------6" << endl;
		cin >> c2;
		switch (c2) {
		case '1':
			do {
				system("cls");
				cout << "输入字符串：";
				cin >> chars;
				StrAssign(Ans,chars);
				cout << "字符串的长度为：" << endl;
				cout << StrLength(Ans) << endl;
				cout << "继续请按1" << endl << "返回请按其他" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		case '2':
			do {
				system("cls");
				cout <<  "请输入要进行比较的两个字符串：" << endl;
				cout << "输入字符串1：";
				cin >> chars;
				StrAssign(Str1,chars);
				cout << "输入字符串2：";
				cin >> chars;
				StrAssign(Str2,chars);
				op = StrCompare(Str1,Str2);
				op = op>0?'>':(op<0?'<':'=');
				cout << "比较结果为：String1" << op << "String2" << endl; 
				cout << "继续请按1" << endl << "返回请按其他" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		case '3':
			do {
				system("cls");
				cout << "输入字符串：";
				cin >> chars;
				StrAssign(Str1,chars);
				cout << "请输入位置与长度：";
				cin >> pos >> len;
				SubString(Ans,Str1,pos,len);
				cout << "子串为：";
				StrPrint(Ans);
				cout << "继续请按1" << endl << "返回请按其他" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		case '4':
			do {
				system("cls");
				cout << "输入字符串1：";
				cin >> chars;
				StrAssign(Str1,chars);
				cout << "输入字符串2：";
				cin >> chars;
				StrAssign(Str2,chars);
				Concat(Ans,Str1,Str2);
				cout << "连接结果为：";
				StrPrint(Ans);
				cout << "继续请按1" << endl << "返回请按其他" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		case '5':
			do {
				system("cls");
				cout << "输入字符串：";
				cin >> chars;
				StrAssign(Ans,chars);
				cout << "请输入子串位置与长度：";
				cin >> pos >> len;
				StrDelete(Ans,pos,len); 
				cout << "删除结果为：";
				StrPrint(Ans);
				cout << "继续请按1" << endl << "返回请按其他" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		case '6':
			do {
				system("cls");
				cout << "输入父字符串：";
				cin >> chars;
				StrAssign(Str1,chars);
				cout << "输入子字符串：";
				cin >> chars;
				StrAssign(Sub,chars);
				pos = Index_KMP(Str1,Sub,1);
				cout << "子串位置为：" << pos << endl;
				cout << "继续请按1" << endl << "返回请按其他" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		default:
			break;
		}
	} while (c2 >= '1' && c2 <= '6');
	return 0;
}
