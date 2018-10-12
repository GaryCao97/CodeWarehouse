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
void InitString(HString &T);//��ʼ��(�����մ�)�ַ���T
Status StrAssign(HString &T, char *chars);//����һ����ֵ���ڴ�����chars�Ĵ�T
Status StrCopy(HString &T, HString S);//���ƴ�S
Status StrEmpty(HString S);//�жϴ�S�Ƿ�Ϊ��
int StrLength(HString S);//����S��Ԫ�ظ�������Ϊ���ĳ���
int StrCompare(HString S, HString T);//��S>T���򷵻�>0����S<T���򷵻�<0����S=T���򷵻�=0
Status ClearString(HString &S);//��S���
Status Concat(HString &T, HString S1, HString S2);//����������
Status SubString(HString &Sub, HString S, int pos, int len);//���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
int Index(HString S, HString T, int pos);//��������S���ڵ�posλ��֮���һ�γ��ֵ��Ӵ�T��λ��
Status Replace(HString &S, HString T, HString V);//��V�滻S������T
Status StrInsert(HString &S, int pos, HString T);//S��pos�����T
Status StrDelete(HString &S, int pos, int len);//S��pos��ɾ��len���ַ�

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
Status StrCopy(HString &T, HString S){ /* ��ʼ����:��S���ڡ��������: �ɴ�S���Ƶô�T */
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
Status StrEmpty(HString S){ /* ��ʼ����: ��S���ڡ��������: ��SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE */
	if (S.length == 0 && S.ch == NULL)
		return TRUE;
	else
		return FALSE;
}
int StrCompare(HString S, HString T){ /* ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 */
	int i;
	for (i = 0; i < S.length && i < T.length; ++i)
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	return S.length - T.length;
}
int StrLength(HString S){ /* ����S��Ԫ�ظ���,��Ϊ���ĳ��� */
	return S.length;
}
Status ClearString(HString &S){ /* ��S��Ϊ�մ� */
	if (S.ch){
		free(S.ch);
		S.ch = NULL;
	}
	S.length = 0;
	return OK;
}
Status Concat(HString &T, HString S1, HString S2){ /* ��T������S1��S2���Ӷ��ɵ��´� */
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
	// ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�
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
		cout << "��ѡ��Ҫ���еĲ���:" << endl;
		cout << "���ĳ���-------1" << endl;
		cout << "���ıȽ�-------2" << endl;
		cout << "�����Ӵ�-------3" << endl;
		cout << "��������-------4" << endl;
		cout << "�Ӵ���ɾ��-----5" << endl;
		cout << "���Ķ�λ-------6" << endl;
		cin >> c2;
		switch (c2) {
		case '1':
			do {
				system("cls");
				cout << "�����ַ�����";
				cin >> chars;
				StrAssign(Ans,chars);
				cout << "�ַ����ĳ���Ϊ��" << endl;
				cout << StrLength(Ans) << endl;
				cout << "�����밴1" << endl << "�����밴����" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		case '2':
			do {
				system("cls");
				cout <<  "������Ҫ���бȽϵ������ַ�����" << endl;
				cout << "�����ַ���1��";
				cin >> chars;
				StrAssign(Str1,chars);
				cout << "�����ַ���2��";
				cin >> chars;
				StrAssign(Str2,chars);
				op = StrCompare(Str1,Str2);
				op = op>0?'>':(op<0?'<':'=');
				cout << "�ȽϽ��Ϊ��String1" << op << "String2" << endl; 
				cout << "�����밴1" << endl << "�����밴����" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		case '3':
			do {
				system("cls");
				cout << "�����ַ�����";
				cin >> chars;
				StrAssign(Str1,chars);
				cout << "������λ���볤�ȣ�";
				cin >> pos >> len;
				SubString(Ans,Str1,pos,len);
				cout << "�Ӵ�Ϊ��";
				StrPrint(Ans);
				cout << "�����밴1" << endl << "�����밴����" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		case '4':
			do {
				system("cls");
				cout << "�����ַ���1��";
				cin >> chars;
				StrAssign(Str1,chars);
				cout << "�����ַ���2��";
				cin >> chars;
				StrAssign(Str2,chars);
				Concat(Ans,Str1,Str2);
				cout << "���ӽ��Ϊ��";
				StrPrint(Ans);
				cout << "�����밴1" << endl << "�����밴����" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		case '5':
			do {
				system("cls");
				cout << "�����ַ�����";
				cin >> chars;
				StrAssign(Ans,chars);
				cout << "�������Ӵ�λ���볤�ȣ�";
				cin >> pos >> len;
				StrDelete(Ans,pos,len); 
				cout << "ɾ�����Ϊ��";
				StrPrint(Ans);
				cout << "�����밴1" << endl << "�����밴����" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		case '6':
			do {
				system("cls");
				cout << "���븸�ַ�����";
				cin >> chars;
				StrAssign(Str1,chars);
				cout << "�������ַ�����";
				cin >> chars;
				StrAssign(Sub,chars);
				pos = Index_KMP(Str1,Sub,1);
				cout << "�Ӵ�λ��Ϊ��" << pos << endl;
				cout << "�����밴1" << endl << "�����밴����" << endl;
				cin >> c1;
			} while (c1 == '1');
			break;
		default:
			break;
		}
	} while (c2 >= '1' && c2 <= '6');
	return 0;
}
