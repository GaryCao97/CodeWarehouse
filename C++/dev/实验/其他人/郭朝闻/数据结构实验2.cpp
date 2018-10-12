 //���ݽṹ�������˳�����Ķ���

#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
#include<Windows.h>
#define LIST_INIT_SIZE   100
#define LISTINCREMENT   10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFEASIBLE -1
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬���� 
typedef int Status;
typedef int ElemType; 

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

class LIST{
	public:
		Status (*cmp)(SqList L,ElemType e);
		Status InitList_Sq(SqList &L);
		Status ListInsert_Sq(SqList &L,int i,ElemType e);
		Status ListDelete_Sq(SqList &L,int i,ElemType &e);
		Status LocateElem_Sq(SqList L,ElemType e);
        Status cmpare(ElemType a,ElemType b);
		Status UpdateList_Sq(SqList &L,int i,ElemType e);
		Status ListTraverse_Sq(SqList L);
};

Status LIST::InitList_Sq(SqList &L){
	//����һ���յ����Ա�L
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE *(sizeof(ElemType)));
	if(!L.elem) exit (OVERFLOW) ;
	//�洢����ʧ��
	L.length=0;
	//�ձ���Ϊ0
	L.listsize=LIST_INIT_SIZE ;
	//��ʼ�洢����
	return OK; 
	
}


//��˳���ĵ�i��Ԫ��ǰ����һ��Ԫ��

Status LIST::ListInsert_Sq(SqList &L,int i,ElemType e) {
	if(i<1 || i>L.length+1)
	   return ERROR ;
	if(L.length>=L.listsize){
	   ElemType *newbase=(ElemType *)realloc(L.elem,
	                (L.listsize+LISTINCREMENT)*sizeof(ElemType));
    if(!newbase) exit (OVERFLOW);
    L.elem=newbase;
    L.listsize+=LISTINCREMENT;
	}
    	ElemType *q=&(L.elem[i-1]);
    	ElemType *p;
    	for(p=&(L.elem[L.length-1]);p>=q;p--)
    		*(p+1)=*p;
        *q=e;
        L.length++;
	return OK;
}//ListInsert_sq


//ɾ��˳����i��λ�õ�Ԫ�� 

Status LIST::ListDelete_Sq(SqList &L,int i,ElemType &e){
	if(i<1 || i>L.length)
	   return ERROR;
	   
	ElemType *p;
	p=&(L.elem[i-1]);
	*p=e;
	ElemType *q=L.elem+L.length-1;
	for(++p;p<=q;p++)
	    *(p-1)=*p;
	--L.length;
	return OK;    
} //ListDelete_sq

Status LIST::cmpare(ElemType a,ElemType b){
	if(a == b)
		return OK;
	else
		return ERROR;
}
//��˳����в��ҵ�i��Ԫ��

Status LIST::LocateElem_Sq(SqList L,ElemType e){
	//��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
	//���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0
	int i=1;
	ElemType *p=L.elem;
	while(i<=L.length && !cmpare(*p++,e))
	    ++i;
	if(i<=L.length)
	    printf("���ҵ�Ԫ���ڵ�%d��λ�á�",i);
	else 
	    return ERROR;
} //LocateElem_Sq


//����˳����е�i��Ԫ�ص�ֵ

Status LIST::UpdateList_Sq(SqList &L,int i,ElemType e){
	if(i<1 || i>L.length)
	  return ERROR;
	ElemType *p=&(L.elem[i-1]);
	*p=e;
	  return OK;
}//UpdateList_Sq


//����˳���

Status LIST::ListTraverse_Sq(SqList L){
   
	ElemType *p=L.elem;
	ElemType *q=&L.elem[L.length-1];
	
	printf("˳���Ϊ��");
	while(p<=q){
	    printf("%d",*p);
	    printf(" ");
	    p++;
}
       return OK;
}//ListTraverse_Sq

int main(){
	ElemType e;
	SqList L;
	LIST list;
	list.InitList_Sq(L);
	printf("\n\n==��ӭ����˳���ϵͳ==\n\n"); 
	printf("��������Ԫ�ظ����� ");
	int N;
	scanf("%d",&N) ;
	printf("����������Ԫ��:\n");
	for(int i=1;i<=N;i++){
	    printf("��%d�����ݣ�",i);
	    scanf("%d",&e);
	    //system("pause");
	    list.ListInsert_Sq(L,i,e);
	}
	Sleep(1000);
	system("cls");
	loop:{
		printf("��ѡ����Ҫ���еĹ��ܣ�\n");
		printf("1) ����Ԫ�� \n");
		printf("2) ɾ��Ԫ�� \n");
		printf("3) ����Ԫ�� \n");
		printf("4) ����Ԫ�� \n");
		printf("5) �������Ա� \n");
	   int a;
	    scanf("%d",&a);
	    system("cls");
	    switch(a){
	    	case 1:printf("Ҫ�����ĸ�Ԫ�أ�");
	    	       scanf("%d",&e);
	    	       printf("\n");
	    	       printf("Ҫ�����ĸ�λ�ã�");
	    	       scanf("%d",&N);
	    	       list.ListInsert_Sq(L,N,e);
	    	       Sleep(1000);
	    	    goto loop;break;
	    	case 2:printf("Ҫɾ���ĸ�λ�õ�Ԫ�أ�");
	    	       scanf("%d",&N);
	    	       printf("\n");
	    	       list.ListDelete_Sq(L,N,e);
				   printf("��ɾ��%d��",e);
				   Sleep(1000);
				goto loop;break;
			case 3:printf("����Ҫ���ҵ�Ԫ��ֵ�Ƕ��٣�");
			       scanf("%d",&e);
				   list.LocateElem_Sq(L,e);
				goto loop;break;
		    case 4:printf("����Ҫ���µ�Ԫ��λ�������");
			       scanf("%d",&N);
			       printf("\n");
			       printf("������³�ʲôԪ�أ�");
			       scanf("%d\n",&e);
				   list.UpdateList_Sq(L,N,e);
				   Sleep(1000);
				   goto loop;break;
		    case 5:printf("�������Ա�");
			        list.ListTraverse_Sq(L);
			        system("pause");
			        goto loop;break;
			default:
				printf("**��������1~5������**");
				goto loop;break;
	}
}
return OK; 
}

















