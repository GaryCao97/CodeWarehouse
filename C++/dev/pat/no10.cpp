#include<iostream>
#include<stdlib.h>
using namespace std;
struct elem{
	int exp;
	int n;
};
struct node{
	elem data;
	node *next;
};
int main(){
	node *head,*q,*p;
	q = (node*)malloc(sizeof(node));
	q->next = NULL;
	head = q;
	do{
		cin >> q->data.n >> q->data.exp;
		if(q->data.exp == 0)break;
		p = (node*)malloc(sizeof(node));
		p->next = NULL;
		q->next = p;
		q = q->next;
	}while(1);
	q = head;
	if(head->data.exp == 0){
		cout << "0 0";
	}
	else{
		do{
			if(q->data.exp != 0){
				cout << q->data.exp * q->data.n << ' ' << q->data.exp - 1;
			}
			q = q->next;
			if(q->data.exp != 0) cout << ' ';
		}while(q->data.exp != 0);
	}
	return 0;
} 
