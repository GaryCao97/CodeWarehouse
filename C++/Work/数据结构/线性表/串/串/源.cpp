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
	// KMP算法。其中，T非空，1≤pos≤StrLength(S)。
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
} // Index_KMP

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
int main(){
	HString str, sub;
	InitString(str);
	InitString(sub);
	StrAssign(str, "abcdefghijklmnopqrstuvwxyz");
	StrAssign(sub, "opq");
	cout << Index(str, sub, 1) << endl;
	cout << Index_KMP(str, sub, 1) << endl;
	StrPrint(str);
	StrPrint(sub);
	return 0;
}
