#include<iostream>
#include<stdlib.h> 
#include<string.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;
typedef int Boolean;
#define EQ(a,b) (!strcmp((a),(b)))
#define LT(a,b) (strcmp((a),(b)) < 0)
#define LQ(a,b) (strcmp((a),(b)) <= 0)
typedef struct {
	char* key;
}ElemType;
typedef struct BSTNode{
	ElemType data;
	int bf;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
#define LH +1
#define EH 0
#define RH -1
void R_Rotate(BSTree &p) {
	BSTree lc;
	lc = p->lchild;            // lcָ��*p�������������
	p->lchild = lc->rchild;    // lc���������ҽ�Ϊ*p��������
	lc->rchild = p;  p = lc;   // pָ���µĸ����
} 
void L_Rotate(BSTree &p) {
	BSTree rc;
	rc = p->rchild;            // rcָ��*p�������������
	p->rchild = rc->lchild;    // rc���������ҽ�Ϊ*p��������
	rc->lchild = p;  p = rc;   // pָ���µĸ����
} 
void LeftBalance(BSTree &T) {  // �㷨 9.12
  // ����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת����
  // ���㷨����ʱ��ָ��Tָ���µĸ����
  BSTree lc,rd;
  lc = T->lchild;
  switch (lc->bf) {
    case LH:
        T->bf = lc->bf = EH; 
        R_Rotate(T);   
        break;  
    case RH:
        rd = lc->rchild;
        switch (rd->bf) { 
          case LH: T->bf = RH;  lc->bf = EH;  break;
          case EH: T->bf = lc->bf = EH;       break;
          case RH: T->bf = EH;  lc->bf = LH;  break;
        }
        rd->bf = EH;              
        L_Rotate(T->lchild);
        R_Rotate(T);
  }
}
void RightBalance(BSTree &T) {
  BSTree rc,ld;
  rc = T->rchild;
  switch (rc->bf) {
    case RH:
        T->bf = rc->bf = EH; 
        L_Rotate(T);   
        break;  
    case LH:
        ld = rc->lchild;
        switch (ld->bf) { 
          case LH: T->bf = RH;  rc->bf = EH;  break;
          case EH: T->bf = rc->bf = EH;       break;
          case RH: T->bf = EH;  rc->bf = LH;  break;
        }
        ld->bf = EH;              
        R_Rotate(T->rchild);
        L_Rotate(T);
  }
}
Status InsertAVL(BSTree &T, ElemType e, Boolean &taller) {
	if (!T) {
		T = (BSTree) malloc (sizeof(BSTNode));  T->data = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;
		taller = TRUE;
	}
	else {
		if (EQ(e.key, T->data.key)){
			taller = FALSE;
			return 0;
		}
		if (LT(e.key, T->data.key)) { 
			if (InsertAVL(T->lchild, e, taller)==0)
				return 0;
			if (taller)
				switch (T->bf) {
		    	case LH:
		        	LeftBalance(T);   taller = FALSE;  break;
		    	case EH:
		        	T->bf = LH;  taller = TRUE;  break;
		    	case RH:
		        	T->bf = EH;  taller = FALSE;  break;   
		    	}
		}
		else {
			if (InsertAVL(T->rchild, e, taller)==0)
				return 0;
			if (taller)
				switch (T->bf) {
				case LH:
				    T->bf = EH;  taller = FALSE;  break;   
				case EH:
				    T->bf = RH;  taller = TRUE;  break;
				case RH:
				    RightBalance(T);  taller = FALSE;  break;
			}
		} 
	}
	return 1;
}
void PRE(BSTree T){
	if(!T){
		cout << T->data.key << " ";
		PRE(T->lchild);
		PRE(T->rchild);
	}
} 
void IN(BSTree T){
	if(!T){
		IN(T->lchild);
		cout << T->data.key << " ";
		IN(T->rchild);
	}
} 

int main(){
	BSTree T;
	Boolean tall;
	//(Jan, Feb, Mar, Apr, May, June, July, Aug, Sep, Oct, Nov, Dec)
	ElemType e;
	e.key = "Jan";
	InsertAVL(T,e,tall);
	e.key = "Feb";
	InsertAVL(T,e,tall);
	e.key = "Mar";
	InsertAVL(T,e,tall);
	e.key = "Apr";
	InsertAVL(T,e,tall);
	e.key = "May";
	InsertAVL(T,e,tall);
	e.key = "June";
	InsertAVL(T,e,tall);
	e.key = "July";
	InsertAVL(T,e,tall);
	e.key = "Aug";
	InsertAVL(T,e,tall);
	e.key = "Sep";
	InsertAVL(T,e,tall);
	e.key = "Oct";
	InsertAVL(T,e,tall);
	e.key = "Nov";
	InsertAVL(T,e,tall);
	e.key = "Dec";
	InsertAVL(T,e,tall);
	cout << "����" << endl;
	PRE(T);
	cout << endl;
	cout << "����" << endl;
	IN(T);
	cout << endl;
	return 0;
} 
