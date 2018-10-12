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
//循环队列
#define MAXSIZE 100
typedef struct {
	QElemType *base;
	int front, rear;
}SqQueue;
Status InitQueue_Sq(SqQueue &Q) {
	//初始化
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
	//插入
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}
Status DeQueue_Sq(SqQueue &Q, QElemType &e) {
	//删除
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}
Status GetTop_Sq(SqQueue Q, QElemType &e) {
	//获取队首元素
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


//链队列
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front, rear;
}LinkQueue;
Status InitQueue_Link(LinkQueue &Q);//构造一个空队列Q
Status QueueEmpty_Link(LinkQueue Q);//若Q为空队列，则返回TRUE，否则返回FALSE
int QueueLength_Link(LinkQueue Q);//求队列的长度
Status GetHead_Link(LinkQueue Q, QElemType &e);//若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
Status EnQueue_Link(LinkQueue &Q, QElemType e);//插入元素e为Q的新的队尾元素
Status DeQueue_Link(LinkQueue &Q, QElemType &e);//若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
Status InitQueue_Link(LinkQueue &Q) {
	// 构造一个空队列Q   
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
Status QueueEmpty_Link(LinkQueue Q) {
	// 若Q为空队列，则返回TRUE，否则返回FALSE   
	if (Q.front->next == NULL)
		return TRUE;
	else
		return FALSE;
}
int QueueLength_Link(LinkQueue Q) {
	// 求队列的长度   
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
	// 若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR   
	QueuePtr p;
	if (QueueEmpty_Link(Q))
		return ERROR;
	p = Q.front->next;
	e = p->data;
	return OK;
}
Status EnQueue_Link(LinkQueue &Q, QElemType e) {
	// 插入元素e为Q的新的队尾元素   
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
	// 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR   
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
		cout << "循环队列与链队列初始化成功" << endl;
	else return 1;
	Sleep(1000 * 1.5);
	char c1, c2, c3;
	QElemType e;
	do {
		system("cls");
		cout << "请选择需要进行操作的队列：" << endl << "输入1选择循环队列" << endl << "输入2选择链队列" << endl << "输入其他字符退出" << endl;
		cin >> c1;
		if (c1 == '1') {
			do {
				system("cls");
				cout << "本队列为循环队列" << endl;
				cout << "请选择要进行的操作:" << endl;
				cout << "入队-------1" << endl;
				cout << "出队-------2" << endl;
				cout << "获得队头---3" << endl;
				cout << "遍历-------4" << endl;
				cout << "返回-------其他" << endl;
				cin >> c2;
				switch (c2){
				case '1':
					do {
						system("cls");
						cout << "输入元素e：";
						cin >> e;
						if (EnQueue_Sq(Q1, e)) {
							cout << "插入成功" << endl;
							cout << "循环队列元素为：";
							QueueTraverse_Sq(Q1);
						}
						else
							cout << "插入失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '2':
					do {
						system("cls");
						if (DeQueue_Sq(Q1, e)) {
							cout << "删除成功" << endl;
							cout << "被删除的元素为：" << e << endl;
							cout << "循环队列元素为：";
							QueueTraverse_Sq(Q1);
						}
						else
							cout << "删除失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '3':
					do {
						system("cls");
						if (GetTop_Sq(Q1, e)) {
							cout << "获取成功" << endl;
							cout << "被获取的元素为：" << e << endl;
							cout << "循环队列元素为：";
							QueueTraverse_Sq(Q1);
						}
						else
							cout << "获取失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '4':
					do {
						system("cls");
						cout << "循环队列元素为：";
						if (QueueTraverse_Sq(Q1)) {
							cout << endl << "遍历成功" << endl;
						}
						else
							cout << endl << "遍历失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
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
				cout << "本队列为链队列" << endl;
				cout << "请选择要进行的操作:" << endl;
				cout << "入队-------1" << endl;
				cout << "出队-------2" << endl;
				cout << "获得队头---3" << endl;
				cout << "遍历-------4" << endl;
				cout << "返回-------其他" << endl;
				cin >> c2;
				switch (c2){
				case '1':
					do {
						system("cls");
						cout << "输入元素e：";
						cin >> e;
						if (EnQueue_Link(Q2, e)) {
							cout << "插入成功" << endl;
							cout << "链队列元素为：";
							QueueTraverse_Link(Q2);
						}
						else
							cout << "插入失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '2':
					do {
						system("cls");
						if (DeQueue_Link(Q2, e)) {
							cout << "删除成功" << endl;
							cout << "被删除的元素为：" << e << endl;
							cout << "链队列元素为：";
							QueueTraverse_Link(Q2);
						}
						else
							cout << "删除失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '3':
					do {
						system("cls");
						if (GetHead_Link(Q2, e)) {
							cout << "获取成功" << endl;
							cout << "被获取的元素为：" << e << endl;
							cout << "链队列元素为：";
							QueueTraverse_Link(Q2);
						}
						else
							cout << "获取失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '4':
					do {
						system("cls");
						cout << "链队列元素为：";
						if (QueueTraverse_Link(Q2)) {
							cout << endl << "遍历成功" << endl;
						}
						else
							cout << endl << "遍历失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
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
