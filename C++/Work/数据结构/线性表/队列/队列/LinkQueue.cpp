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

Status InitQueue(LinkQueue &Q);//����һ���ն���Q
Status DestroyQueue(LinkQueue &Q);//���ٶ���Q(���ۿշ����)
Status ClearQueue(LinkQueue &Q);//��Q��Ϊ�ն���
Status QueueEmpty(LinkQueue Q);//��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
int QueueLength(LinkQueue Q);//����еĳ���
Status GetHead(LinkQueue Q, QElemType &e);//�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
Status EnQueue(LinkQueue &Q, QElemType e);//����Ԫ��eΪQ���µĶ�βԪ��
Status DeQueue(LinkQueue &Q, QElemType &e);//�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType));//�Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���visit()  

Status InitQueue(LinkQueue &Q){
	// ����һ���ն���Q   
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q){
	// ���ٶ���Q(���ۿշ����)   
	while (Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue &Q){
	// ��Q��Ϊ�ն���   
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
	// ��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE   
	if (Q.front->next == NULL)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q){
	// ����еĳ���   
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
	// �����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR   
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e){
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

Status DeQueue(LinkQueue &Q, QElemType &e){
	// �����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR   
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
	// �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()   
	QueuePtr p;
	p = Q.front->next;
	while (p){
		(*visit)(p->data);
		p = p->next;
	}
}