#include<iostream>

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;

typedef QElemType;
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front, rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);//构造一个空队列Q
Status DestroyQueue(LinkQueue &Q);//销毁队列Q(无论空否均可)
Status ClearQueue(LinkQueue &Q);//将Q清为空队列
Status QueueEmpty(LinkQueue Q);//若Q为空队列，则返回TRUE，否则返回FALSE
int QueueLength(LinkQueue Q);//求队列的长度
Status GetHead(LinkQueue Q, QElemType &e);//若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
Status EnQueue(LinkQueue &Q, QElemType e);//插入元素e为Q的新的队尾元素
Status DeQueue(LinkQueue &Q, QElemType &e);//若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType));//从队头到队尾依次对队列Q中每个元素调用函数visit()  

Status InitQueue(LinkQueue &Q){
	// 构造一个空队列Q   
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q){
	// 销毁队列Q(无论空否均可)   
	while (Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue &Q){
	// 将Q清为空队列   
	QueuePtr p, q;
	Q.rear = Q.front;
	p = Q.front->next;
	Q.front->next = NULL;
	while (p){
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

Status QueueEmpty(LinkQueue Q){
	// 若Q为空队列，则返回TRUE，否则返回FALSE   
	if (Q.front->next == NULL)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q){
	// 求队列的长度   
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (Q.rear != p){
		i++;
		p = p->next;
	}
	return i;
}

Status GetHead(LinkQueue Q, QElemType &e){
	// 若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR   
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e){
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

Status DeQueue(LinkQueue &Q, QElemType &e){
	// 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR   
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}

Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType)){
	// 从队头到队尾依次对队列Q中每个元素调用函数vi()   
	QueuePtr p;
	p = Q.front->next;
	while (p){
		(*visit)(p->data);
		p = p->next;
	}
}