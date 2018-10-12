#include<iostream>
#include<windows.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define OVERFLOW    -2 
typedef int Status;
typedef int QElemType;
//ѭ������
#define MAXSIZE 100
typedef struct {
	QElemType *base;
	int front, rear;
}SqQueue;
Status InitQueue_Sq(SqQueue &Q) {
	//��ʼ��
	Q.base = (QElemType*)malloc(MAXSIZE * sizeof(QElemType));
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
int QueueLength_Sq(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
Status EnQueue_Sq(SqQueue &Q, QElemType e) {
	//����
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}
Status DeQueue_Sq(SqQueue &Q, QElemType &e) {
	//ɾ��
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}
Status GetTop_Sq(SqQueue Q, QElemType &e) {
	//��ȡ����Ԫ��
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	return OK;
}
Status QueueTraverse_Sq(SqQueue Q) {
	if (Q.front == Q.rear)
		return ERROR;
	for (int a = Q.front; Q.base[a] && (a != Q.rear); a = (a + 1) % MAXSIZE) {
		cout << Q.base[a] << ' ';
	}
	cout << endl;
	return OK;
}


//������
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front, rear;
}LinkQueue;
Status InitQueue_Link(LinkQueue &Q);//����һ���ն���Q
Status QueueEmpty_Link(LinkQueue Q);//��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
int QueueLength_Link(LinkQueue Q);//����еĳ���
Status GetHead_Link(LinkQueue Q, QElemType &e);//�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
Status EnQueue_Link(LinkQueue &Q, QElemType e);//����Ԫ��eΪQ���µĶ�βԪ��
Status DeQueue_Link(LinkQueue &Q, QElemType &e);//�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
Status InitQueue_Link(LinkQueue &Q) {
	// ����һ���ն���Q   
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
Status QueueEmpty_Link(LinkQueue Q) {
	// ��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE   
	if (Q.front->next == NULL)
		return TRUE;
	else
		return FALSE;
}
int QueueLength_Link(LinkQueue Q) {
	// ����еĳ���   
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (Q.rear != p) {
		i++;
		p = p->next;
	}
	return i;
}
Status GetHead_Link(LinkQueue Q, QElemType &e) {
	// �����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR   
	QueuePtr p;
	if (QueueEmpty_Link(Q))
		return ERROR;
	p = Q.front->next;
	e = p->data;
	return OK;
}
Status EnQueue_Link(LinkQueue &Q, QElemType e) {
	// ����Ԫ��eΪQ���µĶ�βԪ��   
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
Status DeQueue_Link(LinkQueue &Q, QElemType &e) {
	// �����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR   
	QueuePtr p;
	if (QueueEmpty_Link(Q))
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}
Status QueueTraverse_Link(LinkQueue Q) {
	if(QueueEmpty_Link(Q))
		return ERROR;
	QueuePtr p = Q.front->next;
	while (p) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
	return OK;
}
int main() {
	SqQueue Q1;
	LinkQueue Q2;
	if (InitQueue_Link(Q2) && InitQueue_Sq(Q1))
		cout << "ѭ�������������г�ʼ���ɹ�" << endl;
	else return 1;
	Sleep(1000 * 1.5);
	char c1, c2, c3;
	QElemType e;
	do {
		system("cls");
		cout << "��ѡ����Ҫ���в����Ķ��У�" << endl << "����1ѡ��ѭ������" << endl << "����2ѡ��������" << endl << "���������ַ��˳�" << endl;
		cin >> c1;
		if (c1 == '1') {
			do {
				system("cls");
				cout << "������Ϊѭ������" << endl;
				cout << "��ѡ��Ҫ���еĲ���:" << endl;
				cout << "���-------1" << endl;
				cout << "����-------2" << endl;
				cout << "��ö�ͷ---3" << endl;
				cout << "����-------4" << endl;
				cout << "����-------����" << endl;
				cin >> c2;
				switch (c2){
				case '1':
					do {
						system("cls");
						cout << "����Ԫ��e��";
						cin >> e;
						if (EnQueue_Sq(Q1, e)) {
							cout << "����ɹ�" << endl;
							cout << "ѭ������Ԫ��Ϊ��";
							QueueTraverse_Sq(Q1);
						}
						else
							cout << "����ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '2':
					do {
						system("cls");
						if (DeQueue_Sq(Q1, e)) {
							cout << "ɾ���ɹ�" << endl;
							cout << "��ɾ����Ԫ��Ϊ��" << e << endl;
							cout << "ѭ������Ԫ��Ϊ��";
							QueueTraverse_Sq(Q1);
						}
						else
							cout << "ɾ��ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '3':
					do {
						system("cls");
						if (GetTop_Sq(Q1, e)) {
							cout << "��ȡ�ɹ�" << endl;
							cout << "����ȡ��Ԫ��Ϊ��" << e << endl;
							cout << "ѭ������Ԫ��Ϊ��";
							QueueTraverse_Sq(Q1);
						}
						else
							cout << "��ȡʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '4':
					do {
						system("cls");
						cout << "ѭ������Ԫ��Ϊ��";
						if (QueueTraverse_Sq(Q1)) {
							cout << endl << "�����ɹ�" << endl;
						}
						else
							cout << endl << "����ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				default:
					break;
				}
			} while (c2 >= '1' && c2 <= '4');
		}
		else if (c1 == '2') {
			do {
				system("cls");
				cout << "������Ϊ������" << endl;
				cout << "��ѡ��Ҫ���еĲ���:" << endl;
				cout << "���-------1" << endl;
				cout << "����-------2" << endl;
				cout << "��ö�ͷ---3" << endl;
				cout << "����-------4" << endl;
				cout << "����-------����" << endl;
				cin >> c2;
				switch (c2){
				case '1':
					do {
						system("cls");
						cout << "����Ԫ��e��";
						cin >> e;
						if (EnQueue_Link(Q2, e)) {
							cout << "����ɹ�" << endl;
							cout << "������Ԫ��Ϊ��";
							QueueTraverse_Link(Q2);
						}
						else
							cout << "����ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '2':
					do {
						system("cls");
						if (DeQueue_Link(Q2, e)) {
							cout << "ɾ���ɹ�" << endl;
							cout << "��ɾ����Ԫ��Ϊ��" << e << endl;
							cout << "������Ԫ��Ϊ��";
							QueueTraverse_Link(Q2);
						}
						else
							cout << "ɾ��ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '3':
					do {
						system("cls");
						if (GetHead_Link(Q2, e)) {
							cout << "��ȡ�ɹ�" << endl;
							cout << "����ȡ��Ԫ��Ϊ��" << e << endl;
							cout << "������Ԫ��Ϊ��";
							QueueTraverse_Link(Q2);
						}
						else
							cout << "��ȡʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '4':
					do {
						system("cls");
						cout << "������Ԫ��Ϊ��";
						if (QueueTraverse_Link(Q2)) {
							cout << endl << "�����ɹ�" << endl;
						}
						else
							cout << endl << "����ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				default:
					break;
				}
			} while (c2 >= '1' && c2 <= '4');
		}
		else
			break;
	} while (c1 == '1' || c1 == '2');
	return 0;
}
