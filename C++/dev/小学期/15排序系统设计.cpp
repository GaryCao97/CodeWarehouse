#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define RANDOM(x,y) rand()%(y-x+1) + x
typedef struct People {
	int order;
	int key;
	People *prev;
	People *next;
}*Person,People;
void InitLink(Person &Per,int n){
	Person p,q,head;
	p = NULL;
	for(int i = 1;i <= n;i++){
		q = (Person)malloc(sizeof(People));
		q->order = i;
		q->key = RANDOM(1,n);
		if(p){
			p->next = q;
			q->prev = p;
		}
		else head = q;
		p = q;
	}
	p->next = head;
	head->prev = p;
	Per = head;
}
void DeleteNode(Person Per){
	Per->next->prev = Per->prev;
	Per->prev->next = Per->next;
}
void Print(Person Per,int n){
	int m = RANDOM(0,n),o = 1;
	Person now = Per;
	cout << "ÿ���˵�����Ϊ��";
	do{
		cout << now->key << " ";
		now = now->next;
	}while(now!=Per);
	printf("\n��ʼ����Ϊ��%d\n",m);
	cout << "���б������Ϊ��";
	while(now!=now->next){
		if(o<m){
			now = now->next;
			o++;
		}
		else{
			printf("%d ",now->order);
			m = now->key;
			o = 1;
			now = now->next;
			DeleteNode(now->prev);
		}
	}
	printf("%d\n",now->order);
}
int main(){
	srand(time(NULL));
	cout << "������������";
	int n = 30;
	cin >> n;
	Person P = new People;
	InitLink(P,n);
	Print(P,n); 
	return 0;
}
