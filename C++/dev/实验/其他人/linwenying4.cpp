#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

/*˫����������Ķ���*/
typedef struct DuLNode{   
	ElemType data;
	struct DuLNode * prior,* next;
}DuLNode,* DuLinkList;

DuLinkList L;

int amount=0;

#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

/*Ѱ�ҵ�i����㣬ʹpָ��ý��*/
Status LocatePos(DuLinkList L,int i,DuLinkList &p){
	int j=1;
	while(p&&j<i){ //Ѱ�ҵ�i�����
		p=p->next;
		++j;
	}
	return OK;
}


/*����˫������*/
void CreateList_DuL(DuLinkList &L,int n){
	DuLinkList p,q;
	L=(DuLinkList)malloc(sizeof(DuLNode));
	L->next=NULL;//�Ƚ���һ����ͷ����˫������
	q=L;
	for(int i=0;i<n;++i){
		p=(DuLinkList)malloc(sizeof(DuLNode));//�����½��
		scanf("%d",&p->data);//����Ԫ��ֵ
		p->next=q->next;
		q->next=p;
		q=p;
	}
}

/*��˫������ĵ�i�����ǰ����һ�����*/
Status ListInsert_DuL(DuLinkList &L,int i,ElemType e){
	DuLinkList p=L,s;
	int j=0;
	while(p&&j<i-1){ //Ѱ�ҵ�i-1�����
		p=p->next;
		++j;
	}
	if(!(s=(DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;//�����½��
	s->data=e;
	s->next=p->next;//����L��
	p->next=s;
	s->prior=p;
	if(s->next) 
		s->next->prior=s;
	amount++;
	return OK;
}

/*��˫������ĵ�i�����ǰɾ��һ�����*/
Status ListDelete_DuL(DuLinkList &L,int i,ElemType &e){
	DuLinkList p=L;
	int j=0;
	while(p&&j<i-1){ //Ѱ�ҵ�i-1�����
		p=p->next;
		++j;
	}
	e=p->data;
	p->prior->next=p->next;
	if(p->next)
		p->next->prior=p->prior;
	free(p);//ɾ�����ͷŽ��
	amount--;
	return OK;
}


/*��˫�������в��ҵ�i�����*/
Status ListSearch_DuL(DuLinkList L,int i,ElemType &e){
	DuLinkList p=L->next;
	LocatePos(L,i,p);//Ѱ�ҵ�i����㲢ʹpָ��ý��
	e=p->data;	
	printf("��%d",i);
	printf("��Ԫ�ص�ֵΪ��%d",e);
	printf("\n");
	return OK;
}

/*��˫�������и��µ�i�����*/
Status ListUpdata_DuL(DuLinkList L,int i,ElemType e){
	DuLinkList p=L->next;
	LocatePos(L,i,p);//Ѱ�ҵ�i����㲢ʹpָ��ý��
	p->data=e;
	return OK;
}

void visit(ElemType e)  
{  
    printf("%d  ",e);  //��ӡ����Ԫ�� 
}  

/*����˫������*/
Status ListTraverse_DuL(DuLinkList L, void (*visit)( ElemType )){
	DuLinkList p=L->next;
	while(p){
		visit(p->data); //���ζ�L��ÿ������Ԫ�ص���visit()����
		p=p->next;		//һ��visit()ʧ�ܣ������ʧ��
	}	 
	printf("\n");
	return OK;
}


int main(){
	int i=0,num,n;
	ElemType e; 
	printf("\t\t\t\t˫������Ļ�������\n");
	printf("\t\t-----------------------------------------------\n");
	loop1:
		do{	
			printf("������˫������Ԫ�صĸ���:");
			scanf("%d",&n);
			if(n==0){
			printf("˫�������е�Ԫ�ظ�������Ϊ0������������:\n");
			goto loop1;
			}
			else{
			printf("������˫�������е�Ԫ��:");
			CreateList_DuL(L,n); 
			amount=n;// 
			break;
			}
		}while(1);
	while(1){
	printf("��ѡ�����²�����\n");  //��ʾ 
	printf("---------------------------------------------------\n");
	printf("1����˫������ĵ�i�����ǰ����һ�����\n");
	printf("2����˫������ĵ�i�����ǰɾ��һ����� \n");
	printf("3����˫�������в��ҵ�i������ֵ\n");
	printf("4������˫�������е�i������ֵ\n");
	printf("5������˫������\n");
	printf("6�������˳�\n");
	printf("---------------------------------------------------\n");
	loop2:
	scanf("%d",&num);	//����������ֽ����ж�
	if(!(num>=1&&num<=6)){	//������벻Ϊ1-6���������������� 
		printf("�������������ѡ��:\n");
		goto loop2;
	}
	switch(num){
		case 1 : printf("������i��ֵ��");
				 scanf("%d",&i);
				 if(i>amount||i<1){  //�ж�i��ֵ�Ƿ��ڷ�Χ�� 
				 	printf("����iֵ����\n");
				 	break; 
				 }
				 printf("����Ҫ�����Ԫ��ֵ��");
				 scanf("%d",&e);
				 ListInsert_DuL(L,i,e);  //��˫������ĵ�i��Ԫ��ǰ����һ�����
				 printf("�����ɹ���\n\n"); 
				  break;
		case 2 : printf("������i��ֵ��");
				 scanf("%d",&i);
				 if(i>amount||i<=1){
				 	printf("����iֵ����\n");
				 	break; 
				 }
				 ListDelete_DuL(L,i,e);  //��˫������ĵ�i��Ԫ��ǰɾ��һ����� 
				 printf("�����ɹ���\n\n");
		 		 break;
		case 3 : printf("������i��ֵ��");
				 scanf("%d",&i);
				 if(i>amount||i<1){
				 	printf("����iֵ����\n");
				 	break; 
				 }
				 ListSearch_DuL(L,i,e);  // ��˫�������в��ҵ�i�����
				 printf("�����ɹ���\n\n"); 
				   break;
		case 4 : printf("������i��ֵ��");
				 scanf("%d",&i);
				 if(i>amount||i<1){
				 	printf("����iֵ����\n");
				 	break; 
				 }
				 printf("������Ҫ���µ�Ԫ��ֵ��");
				 scanf("%d",&e);
				 ListUpdata_DuL(L,i,e);  //����˫�������е�i��Ԫ�ص�ֵ
				 printf("�����ɹ���\n\n");   break;
		case 5 : printf("����˫������ ");
				 ListTraverse_DuL(L,visit);  //����˫������
			 	 printf("�����ɹ���\n\n");  break; 
		case 6 : system("CLS");
				 printf("\t\n���������\n\t�ټ���\n");
				 exit(0);	//�������� 
		}
	}
}

