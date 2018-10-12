#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node {
	long long data;
	struct node *next;
}link;
typedef struct {
	link *list;
	long long len;
}linklist;
void InitLink(linklist &L, long long n) {
	L.list = (link*)malloc(sizeof(link));
	L.list->next = L.list;
	L.len = 0;
	link *p;
	for (long long i = n; i >= 1; i--) {
		p = (link*)malloc(sizeof(link));
		p->data = i;
		p->next = L.list->next;
		if (L.len == 0) {
			L.list = p;
		}
		L.list->next = p;
		L.len++;
	}
}
long long J(linklist L, long long k) {
	link *p = L.list,*q;
	long long i = 0;
	do {
		i = 0;
		while (++i<k)p = p->next;
		q = p->next;
		p->next = p->next->next;
		free(q);
		L.len--;
	} while (L.len>1);
	return p->data;
}
int main() {
	linklist L;
	long long n, k;
	while (cin >> n >> k) {
		InitLink(L, n);
		cout << J(L, k) << endl;
	}
	return 0;
}
