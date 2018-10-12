#include <iostream>
#include <stdlib.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int Status;
typedef int ElemType;//���ж���Ԫ������ 
class SqList{
private:
	ElemType *elem;
	int length;
	int listsize;
public:
	Status InitList_Sq();// ����һ���յ����Ա�L��
	Status DestroyList_Sq();//����һ��˳���
	Status ListEmpty_Sq();//�ж�˳����Ƿ�Ϊ��
	int ListLength_Sq();//��˳���ĳ���
	Status GetElem_Sq(int i, ElemType &e);//����˳����еĵ�i��Ԫ��
	Status ListInsert_Sq(int i, ElemType e);// ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
	Status ListChange_Sq(int i, ElemType e);//����˳�����Ա� �ĵ�i��Ԫ�� 
	Status ListDelete_Sq(int i, ElemType &e);// ��˳�����Ա�L��ɾ����i-1��Ԫ�أ�����e������ֵ��
	Status ListTraverse_Sq(Status(*visit)(ElemType));//����˳�����Ա�
};
Status SqList::InitList_Sq() {
	// ����һ���յ����Ա�L��
	elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!elem)
		return OK;
	length = 0;
	listsize = LIST_INIT_SIZE;
	for(int q = 0; q < 5; q++)
		ListInsert_Sq(q+1,q+1);
	return OK;
}
Status SqList::DestroyList_Sq(){
	//����һ��˳���
	if (elem)
		free(elem);
	elem=NULL;
	return OK;
}
Status SqList::ListEmpty_Sq(){
	//�ж�˳����Ƿ�Ϊ��
	return length == 0;
}
int SqList::ListLength_Sq(){
	//��˳���ĳ���
	return (length);
}
Status SqList::GetElem_Sq(int i, ElemType &e){
	//����˳����еĵ�i��Ԫ��
	if (i<1 || i>length)
		return ERROR;
	e = elem[i - 1];
	return OK; 
}
Status SqList::ListInsert_Sq( int i, ElemType e) {
	// ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
	// i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
	ElemType *p;
	if (i < 1 || i > length+1)
		return ERROR;
	if (length >= listsize) {
		ElemType *newbase = (ElemType *)realloc(elem, (listsize+LISTINCREMENT)*sizeof (ElemType));
		if (!newbase)
			return ERROR;
		elem = newbase;
		listsize += LISTINCREMENT;
	}
	ElemType *q = &(elem[i-1]);
	for (p = &(elem[length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++length;
	return OK;
}
Status SqList::ListChange_Sq(int i, ElemType e){
	//����˳�����Ա� �ĵ�i��Ԫ�� 
	if (i < 1 || i > length+1)
		return ERROR;
	ElemType *p = &(elem[i - 1]);
	*p = e;
	return OK;
} 
Status SqList::ListDelete_Sq(int i, ElemType &e) {
	// ��˳�����Ա�L��ɾ����i-1��Ԫ�أ�����e������ֵ��
	// i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
	ElemType *p, *q;
	if (i<1 || i>length)
		return ERROR;
	p = &(elem[i - 1]);
	e = *p;
	q = elem + length - 1;
	for (p; p <= q; ++p)
		*(p - 1) = *p;
	--length;
	return OK;
}
Status SqList::ListTraverse_Sq(Status(*visit)(ElemType)){
	//����˳�����Ա�
	if (ListEmpty_Sq())return ERROR;
	for (int i = 0; i < length; i++){
		if(!(*visit)(elem[i]))
			return ERROR;
		if((i+1) % 5 == 0)cout << endl;
	}
	cout << endl;
	return OK;
}
Status VisitElem(ElemType e){
	cout << e << ' ';
}
int main(int argc, char** argv) {
	SqList SQL;
loop1:
	system("cls");
	cout << "���������ѡ����Ӧ�Ĺ��ܣ�" << endl;
	cout << "��ʼ��---1" << endl; 
	cout << "����-----2" << endl; 
	cout << "ɾ��-----3" << endl; 
	cout << "����-----4" << endl; 
	cout << "����-----5" << endl; 
	cout << "����-----6" << endl; 
	cout << "����-----7" << endl; 
	cout << "�˳�-----����" << endl; 
	int n, m;
	int x, y;
	cin >> n;
	switch(n){
		case 1:
			system("cls");
			if(SQL.InitList_Sq() == OK)
				cout << "��ʼ���ɹ�" << endl << "��ʼ����Ϊ5�����ݷֱ�Ϊ1,2,3,4,5" << endl;
			cout << "�����밴1" << endl;
			cin >> m;
			if(m == 1)goto loop1;
			break;
		case 2:
			loop2:
			system("cls");
			cout << "���������λ����Ԫ�أ���ʽΪ����� Ԫ�أ���";
			cin >> x >> y;
			if(SQL.ListInsert_Sq(x, y) != OK) cout << "����ʧ�ܣ�" << endl;
			else cout << "����ɹ���" << endl;
			cout << "�����밴1" << endl << "�����밴2" << endl;
			cin >> m;
			if(m == 1)goto loop2;
			if(m == 2)goto loop1;
			break;
		case 3:
			loop3:
			system("cls");
			cout << "������ɾ����λ�ã���ʽΪ����ţ���";
			cin >> x;
			if(SQL.ListDelete_Sq(x, y) != OK) cout << "ɾ��ʧ�ܣ�" << endl;
			else cout << "ɾ���ɹ���" << endl;
			cout << "�����밴1" << endl << "�����밴2" << endl;
			cin >> m;
			if(m == 1)goto loop3;
			if(m == 2)goto loop1;
			break;
		case 4:
			loop4:
			system("cls");
			cout << "��������µ�λ����Ԫ�أ���ʽΪ����� Ԫ�أ���";
			cin >> x >> y;
			if(SQL.ListChange_Sq(x, y) != OK) cout << "����ʧ�ܣ�" << endl;
			else cout << "���³ɹ���" << endl;
			cout << "�����밴1" << endl << "�����밴2" << endl;
			cin >> m;
			if(m == 1)goto loop4;
			if(m == 2)goto loop1;
			break;
		case 5:
			loop5:
			system("cls");
			cout << "��������ҵ�λ�ã���ʽΪ����ţ���";
			cin >> x;
			if(SQL.GetElem_Sq(x, y) != OK) cout << "����ʧ�ܣ�" << endl;
			else cout << y << endl << "���ҳɹ���" << endl;
			cout << "�����밴1" << endl << "�����밴2" << endl;
			cin >> m;
			if(m == 1)goto loop5;
			if(m == 2)goto loop1;
			break;
		case 6:
			system("cls");
			if(SQL.ListTraverse_Sq(VisitElem) != OK)
				cout << "����ʧ��" << endl;
			cout << "�����밴1" << endl;
			cin >> m;
			if(m == 1)goto loop1;
			break;
		case 7:
			system("cls");
			if(SQL.DestroyList_Sq() == OK)
				cout << "���ٳɹ�" << endl;
			cout << "�����밴1" << endl;
			cin >> m;
			if(m == 1)goto loop1;
			break; 
		default:
			return 0;
			break;
	}
	return 0;
}
