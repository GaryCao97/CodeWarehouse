#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;
struct HTNode {        // ���н��Ľṹ  
	unsigned int weight;
	unsigned int parent, lchild, rchild;
};
struct HTCode {
	char data;      // ��������ַ�  
	int weight;     // �ַ���Ȩֵ  
	char *code;   // �ַ��ı���  
};
void Init(HTCode *hc, int n) {
	// ��ʼ��������������ַ��ĸ���n���Ӽ�������n���ַ���n��Ȩֵ  
	int i;
	cout << "������" << n << " ���ַ�" << endl;
	for (i = 1; i <= n; ++i)
		cin >> hc[i].data;
	cout << "�밴˳������" << n << "���ַ���Ȩ��" << endl;
	for (i = 1; i <= n; ++i)
		cin >> hc[i].weight;
}
void Select(HTNode *ht, int k, int &s1, int &s2) {
	// ht[1...k]��ѡ��parentΪ0������weight��С��������㣬�������ָ�����s1��s2ָʾ
	int i;
	for (i = 1; i <= k && ht[i].parent != 0; ++i) {
		; ;
	}
	s1 = i;
	for (i = 1; i <= k; ++i) {
		if (ht[i].parent == 0 && ht[i].weight<ht[s1].weight)
			s1 = i;
	}
	for (i = 1; i <= k; ++i) {
		if (ht[i].parent == 0 && i != s1)
			break;
	}
	s2 = i;
	for (i = 1; i <= k; ++i) {
		if (ht[i].parent == 0 && i != s1 && ht[i].weight<ht[s2].weight)
			s2 = i;
	}
}
void HuffmanCoding(HTNode *ht, HTCode *hc, int n) {
	// ����Huffman��ht�������n���ַ��ı���
	char *cd = (char*)malloc(n * sizeof(char));
	int i, m, c, f, s1, s2, start;
	m = 2 * n - 1;
	for (i = 1; i <= m; ++i) {
		if (i <= n)
			ht[i].weight = hc[i].weight;
		else
			ht[i].weight = 0;
		ht[i].parent = ht[i].lchild = ht[i].rchild = 0;
	}
	for (i = n + 1; i <= m; ++i) {
		Select(ht, i - 1, s1, s2);
		ht[s1].parent = i;
		ht[s2].parent = i;
		ht[i].lchild = s1;
		ht[i].rchild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i) {
		start = n - 1;
		for (c = i, f = ht[i].parent; f; c = f, f = ht[f].parent) {
			if (ht[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		hc[i].code = (char*)malloc((n - start + 1) * sizeof(char));
		strcpy(hc[i].code, &cd[start]);
	}
}
int main(){
	int i, n;
	HTNode *ht;
	HTCode *hc;
	cout << "�������ַ����� n = ";
	cin >> n;
	hc = (HTCode*)malloc((n + 1) * sizeof(HTCode));
	ht = (HTNode *)malloc((2 * n) * sizeof(HTNode));
	Init(hc, n); // ��ʼ��
	HuffmanCoding(ht, hc, n); // ����Huffman�������γ��ַ��ı���
	cout << endl;
	for (i = 1; i <= n; ++i)
		cout << hc[i].data << "-----" << hc[i].code << endl;
	return 0;
}