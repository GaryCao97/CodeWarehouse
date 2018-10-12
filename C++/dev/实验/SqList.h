#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int Status;
typedef int ElemType;//自行定义元素类型 
class SqList{
private:
	ElemType *elem;
	int length;
	int listsize;
public:
	Status InitList_Sq();// 构造一个空的线性表L。
	Status DestroyList_Sq();//销毁一个顺序表
	Status ClearList_Sq();//清空一个顺序表
	Status ListEmpty_Sq();//判断顺序表是否为空
	int ListLength_Sq();//求顺序表的长度
	Status GetElem_Sq(int i, ElemType &e);//返回顺序表中的第i个元素
	int LocateElem_Sq(ElemType e, Status(*compare)(ElemType, ElemType));// 在顺序线性表L中查找第1个值与e满足compare()的元素的位序。
	Status PriorElem_Sq(ElemType cur_e, ElemType &pre_e);//返回一个不是首元素的前驱
	Status NextElem_Sq(ElemType cur_e, ElemType &next_e);//返回一个不是末元素的后继
	Status ListInsert_Sq(int i, ElemType e);// 在顺序线性表L的第i个元素之前插入新的元素e，
	Status ListDelete_Sq(int i, ElemType &e);// 在顺序线性表L中删除第i个元素，并用e返回其值。
	Status ListChange_Sq(int i, ElemType e);//更新顺序线性表 的第i个元素 
	Status ListTraverse_Sq(Status(*visit)(ElemType));//遍历顺序线性表
};
