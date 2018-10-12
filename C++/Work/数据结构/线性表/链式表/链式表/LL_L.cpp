#include<iostream>
using namespace std;
/*========��ͷ�ڵ��������������=========*/
typedef char ElemType;

//�������
typedef struct LNode
{
	char data;
	struct LNode *next;
}*Link, *Position;

//��������
typedef struct
{
	Link head, tail;
	int len;
}LinkList;


/*======================================================*/
/*=======һЩ���������������л���õĺ���===============*/
/*======================================================*/

/*---compare---�Ƚ�����Ԫ�صĴ�С��ϵ*/
int Compare(char a, char b)
{
	return a - b;
}

/*---visit---*/
int Visit(Link p)
{
	if (...)
		return 1;
	else
		return 0;

}

/*---length---�����ĳ���*/
int Length(Link s)
{
	int i = 0;
	Link p = NULL;
	p = s;
	while (p->next != NULL)
	{
		p = p->next;
		i++;
	}
	return i;
}

/*---print---����Ļ��������������Ԫ��*/
void Print(LinkList L)
{
	Link p = NULL;
	p = L.head;
	if (!p->next)
	{
		printf("\nThe LinkList is empty.\n\n");
		return;
	}
	printf("The List:");
	while (p)
	{
		printf("%c-", p->data);
		p = p->next;
	}
}

/*======================================================*/
/*==========�Դ�ͷ���ĵ������Ա���в����ĺ����Ķ���==*/
/*======================================================*/

/*---������pָ��Ľ�㲢��ֵΪe---*/
Position MakeNode(ElemType e)
{
	Link p = NULL;
	p = (Link)malloc(sizeof(struct LNode));
	if (p)
	{
		p->data = e;
		p->next = NULL;
	}
	else return;
	return p;
}

/*---�ͷ�p��ָ��Ľ��-*/
void FreeNode(Link p)
{
	free(p);
}


/*---����һ����Lָ��Ŀյ����Ա�-*/
void InitList(LinkList *L)
{
	L->head = MakeNode('L');//����ͷ���
	L->head->next = NULL;/*����l->head=NULL*/
	L->tail = L->head;
	L->len = 0;
}

/*----------������Lָ������Ա�---------*/
void DestroyList(LinkList *L)
{
	Link p;
	p = (*L).tail;
	while (p != (*L).head)
	{
		p = PriorPos(*L, p);
		FreeNode(p->next);
	}
	FreeNode((*L).head);
}

/*�����Ա�L��Ϊ�ձ����ͷ�ԭ�����ͷ���*/
void ClearList(LinkList *L)
{
	Link p;
	p = (*L).tail;
	while (p != (*L).head)
	{
		p = PriorPos(*L, p);
		FreeNode(p->next);
	}
	FreeNode((*L).head);
}

/*---��sָ��Ľ�������������ĵ�һ�����֮ǰ-*/
void InsFirst(LinkList *L, Link s)
{
	s->next = L->head->next;
	if (!L->head->next)
		L->tail = s;       /*����һ���յ����Ա�ִ�иò���ʱ*/
	L->head->next = s;
	L->len++;
}

/*---ɾ�����е�һ����㲢��q����-*/
void DelFirst(LinkList *L, Link q)
{
	if (!L->head->next)
	{
		printf("\nThe LinkList is empty,can not delete..\n");
		return 0;
	}
	q = L->head->next;
	L->head->next = L->head->next->next;
}

/*---��ָ��s����һ��������������Ա�L�����һ�����-*/
void Append(LinkList *L, Link s)
{
	Link q;
	q = L->head;
	if (!L->tail)
	{/*���ǵ�����Ϊ�յ����*/
		L->head->next = s;
		while (q->next)
			q = q->next;/*β���Ĵ���*/
		L->tail = q;
	}
	L->tail->next = q = s;
	while (q->next)
		q = q->next;/*�������˶�β���Ĵ���*/
	L->tail = q;
	L->len += Length(s);
}

/*---ɾ�����Ա�l�е�β���-*/
void Remove(LinkList *L, Link q)
{
	if (!L->tail)
	{
		printf("\nthe LinkList is empty,can not remonde..\n");
		return 0;
	}
	q = L->tail;
	L->tail = PriorPos(*L, q);
	L->tail->next = NULL;
}

/*---��s��ָ���������p��ָ���֮ǰ-*/
void InsBefore(LinkList *L, Link p, Link s)
{
	Link q;
	q = PriorPos(*L, p);
	s->next = p;
	q->next = s;
}

/*---��s��ָ���������p��ָ���֮��-*/
void InsAfter(LinkList *L, Link p, Link s)
{
	s->next = p->next;
	p->next = s;
}

/*---��e����p��ָ��ĵ�ǰ���-*/
void SetCurElem(Link p, ElemType e)
{
	p->data = e;
}

/*---����p��ָ�����Ԫ�ص�ֵ-*/
ElemType GetCurElem(Link p)
{
	return p->data;
}


int Listempty(LinkList L)
{         /*---�����Ա�Ϊ�ձ��򷵻�1�����򷵻�0-*/
	if (L.head == L.tail)
		return 1;
	return 0;
}


int Listlength(LinkList L)
{      /*---�������Ա���Ԫ�ظ���-*/
	return L.len;
}


Position GetHead(LinkList L)
{     /*---�������Ա�l��ͷ����λ��-*/
	return L.head;
}


Position GetLast(LinkList L)
{      /*-----�������Ա�l�����һ������λ��-------*/
	return L.tail;
}


/*---����p��ָ����ֱ��ǰ����λ��-*/
Position PriorPos(LinkList L, Link p)
{
	Link q;
	q = L.head;
	if (q->next == p)
		return 0;
	while (q->next != p)
		q = q->next;
	return q;
}

/*-----����p��ָ����ֱ�Ӻ�̵�λ��-------*/
Position NextPos(Link p)
{
	Link q;
	q = p->next;
	return q;
}

/*-----��p�������Ա�l�е�i������λ�ã�������ok-------*/
void LocatePos(LinkList L, int i, Link p)
{
	p = L.head;
	if (i <= 0 || i>Listlength(L))
		return 0;
	while (i)
	{
		p = p->next;
		i--;
	}
}

/*----���ر��е�һ����e����һ��������ϵ�Ľ�����λ��----*/
int LocatElem(LinkList L, ElemType e)
{
	int i = 0;
	Link p;
	p = L.head->next;
	while (compare(p->data, e) && p)
	{
		p = p->next;
		++i;
	}
	if (!p)
	{/*���ǵ����Ҳ���ָ��Ԫ�ص����*/
		printf("\nthere's no '%c' in this LinkList.", e);
		return 0;
	}
	return i;
}

/*----��һ�����������������н��-------*/
void ListTraverse(LinkList L)
{
	Link p;
	p = L.head;
	while (!visit(p))
		p = p->next;
}