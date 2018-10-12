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
	Status ClearList_Sq();//���һ��˳���
	Status ListEmpty_Sq();//�ж�˳����Ƿ�Ϊ��
	int ListLength_Sq();//��˳���ĳ���
	Status GetElem_Sq(int i, ElemType &e);//����˳����еĵ�i��Ԫ��
	int LocateElem_Sq(ElemType e, Status(*compare)(ElemType, ElemType));// ��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
	Status PriorElem_Sq(ElemType cur_e, ElemType &pre_e);//����һ��������Ԫ�ص�ǰ��
	Status NextElem_Sq(ElemType cur_e, ElemType &next_e);//����һ������ĩԪ�صĺ��
	Status ListInsert_Sq(int i, ElemType e);// ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
	Status ListDelete_Sq(int i, ElemType &e);// ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
	Status ListChange_Sq(int i, ElemType e);//����˳�����Ա� �ĵ�i��Ԫ�� 
	Status ListTraverse_Sq(Status(*visit)(ElemType));//����˳�����Ա�
};
