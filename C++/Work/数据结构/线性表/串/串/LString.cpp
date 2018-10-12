#include<iostream>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
typedef int Status;
#define CHUNK_SIZE 80
#define blank ' '
typedef struct Chunk{
	char ch[CHUNK_SIZE];
	struct Chunk *next;
}Chunk;
typedef struct{
	Chunk *head, *tail;
	int curlen;
}LString;
void InitString(LString &T){ /* ��ʼ��(�����մ�)�ַ���T����� */
	T.curlen = 0;
	T.head = NULL;
	T.tail = NULL;
}
Status StrAssign(LString &T, char *chars); //����һ����ֵ����chars�Ĵ�T(Ҫ��chars�в������������ַ�)���ɹ�����OK�����򷵻�ERROR
Status ToChars(LString T, char* *chars); //����T������ת��Ϊ�ַ�����charsΪ��ͷָ�롣�ɹ�����OK�����򷵻�ERROR�����
Status StrCopy(LString T, LString S); //�ɴ�S���Ƶô�T��ȥ���������ַ����ɹ�����OK�����򷵻�ERROR
Status StrEmpty(LString S); //��ʼ��������S���ڡ������������SΪ�մ����򷵻�TRUE�����򷵻�FALSE
int StrCompare(LString S, LString T); //��S>T���򷵻�ֵ>0����S=T���򷵻�ֵ=0����S<T���򷵻�ֵ<0
int StrLength(LString S); //����S��Ԫ�ظ�������Ϊ���ĳ���
Status ClearString(LString &S); //��ʼ��������S���ڡ������������S��Ϊ�մ�
Status Concat(LString &T, LString S1, LString S2); //��T������S1��S2���Ӷ��ɵ��´�(�м�������������ַ�)
Status SubString(LString &Sub, LString S, int pos, int len); //��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ���
int Index(LString S, LString T, int pos); //TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ����򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0
Status StrInsert(LString &S, int pos, LString T); //1��pos��StrLength(S)+1���ڴ�S�ĵ�pos���ַ�֮ǰ���봮T
Status StrDelete(LString &S, int pos, int len); //�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
Status Replace(LString &S, LString T, LString V); //��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
void StrPrint(LString T); //����ַ���T��

Status StrAssign(LString &T, char *chars){
	int i, j, k, m;
	Chunk *p, *q;
	i = strlen(chars);
	if (!i || strchr(chars, blank))
		return ERROR;
	T.curlen = i;
	j = i / CHUNK_SIZE;
	if (i%CHUNK_SIZE)
		j++;
	for (k = 0; k<j; k++){
		p = (Chunk*)malloc(sizeof(Chunk));
		if (!p)
			return ERROR;
		for (m = 0; m<CHUNK_SIZE&&*chars; m++)
			*(p->ch + m) = *chars++;
		if (k == 0)
			T.head = q = p;
		else{
			q->next = p;
			q = p;
		}
		if (!*chars){
			T.tail = q;
			q->next = NULL;
			for (; m<CHUNK_SIZE; m++)
				*(q->ch + m) = blank;
		}
	}
	return OK;
}
Status ToChars(LString T, char* *chars){
	Chunk *p = T.head;
	int i;
	char *q;
	*chars = (char*)malloc((T.curlen + 1)*sizeof(char));
	if (!chars || !T.curlen)
		return ERROR;
	q = *chars;
	while (p){
		for (i = 0; i<CHUNK_SIZE; i++)
			if (p->ch[i] != blank)
				*q++ = (p->ch[i]);
		p = p->next;
	}
	(*chars)[T.curlen] = 0;
	return OK;
}
Status StrCopy(LString T, LString S){
	char *c;
	Status i;
	if (!ToChars(S, &c))
		return ERROR;
	i = StrAssign(T, c);
	free(c);
	return i;
}
Status StrEmpty(LString S){
	if (S.curlen)
		return FALSE;
	else
		return TRUE;
}
int StrCompare(LString S, LString T){
	char *s, *t;
	Status i;
	if (!ToChars(S, &s))
		return ERROR;
	if (!ToChars(T, &t))
		return ERROR;
	i = strcmp(s, t);
	free(s);
	free(t);
	return i;
}
int StrLength(LString S){
	return S.curlen;
}
Status ClearString(LString &S){
	Chunk *p, *q;
	p = S.head;
	while (p){
		q = p->next;
		free(p);
		p = q;
	}
	S.head = S.tail = NULL;
	S.curlen = 0;
	return OK;
}
Status Concat(LString &T, LString S1, LString S2){
	LString a1, a2;
	InitString(a1);
	InitString(a2);
	if (!StrCopy(a1, S1) || !StrCopy(a2, S2))
		return ERROR;
	T.curlen = S1.curlen + S2.curlen;
	T.head = a1.head;
	a1.tail->next = a2.head; /* a1,a2������β���� */
	T.tail = a2.tail;
	return OK;
}
Status SubString(LString &Sub, LString S, int pos, int len){
	char *b, *c;
	Status i;
	if (pos<1 || pos>S.curlen || len<0 || len>S.curlen - pos + 1)
		return ERROR;
	if (!ToChars(S, &c))
		return ERROR;
	b = c + pos - 1;
	b[len] = 0;
	i = StrAssign(Sub, b);
	free(c);
	return i;
}
int Index(LString S, LString T, int pos){
	int i, n, m;
	LString sub;
	if (pos >= 1 && pos <= StrLength(S))
	{
		n = StrLength(S);
		m = StrLength(T);
		i = pos;
		while (i <= n - m + 1)
		{
			SubString(sub, S, i, m);
			if (StrCompare(sub, T))
				++i;
			else
				return i;
		}
	}
	return 0;
}
Status StrInsert(LString &S, int pos, LString T){
	char *b, *c;
	int i, j;
	Status k;
	if (pos<1 || pos>T.curlen + 1)
		return ERROR;
	if (!ToChars(S, &c))
		return ERROR;
	if (!ToChars(T, &b))
		return ERROR;
	j = (int)strlen(c);
	c = (char*)realloc(c, (j + strlen(b) + 1)*sizeof(char));
	for (i = j; i >= pos - 1; i--)
		c[i + strlen(b)] = c[i];
	for (i = 0; i<(int)strlen(b); i++)
		c[pos + i - 1] = b[i];
	InitString(S);
	k = StrAssign(S, c);
	free(b);
	free(c);
	return k;
}
Status StrDelete(LString &S, int pos, int len){
	char *c;
	int i;
	Status k;
	if (pos<1 || pos>S.curlen - len + 1 || len<0)
		return ERROR;
	if (!ToChars(S, &c))
		return ERROR;
	for (i = pos + len - 1; i <= (int)strlen(c); i++)
		c[i - len] = c[i];
	InitString(S);
	k = StrAssign(S, c);
	free(c);
	return k;
}
Status Replace(LString &S, LString T, LString V){
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
void StrPrint(LString T){
	int i = 0, j;
	Chunk *h;
	h = T.head;
	while (i<T.curlen)
	{
		for (j = 0; j<CHUNK_SIZE; j++)
			if (*(h->ch + j) != blank)
			{
				printf("%c", *(h->ch + j));
				i++;
			}
		h = h->next;
	}
	printf("\n");
}