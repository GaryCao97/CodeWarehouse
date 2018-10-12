#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;
typedef int ElemType;
typedef class LNode{
public:
	ElemType      data;
	LNode  *next;
}*Link, *Position;
typedef class {
private:
	Link head, tail;
	int  len;
public:
	Status MakeNode(Link &p, ElemType e);//分配由p指向的结点并赋值为e
	void FreeNode(Link &p);//释放p所指向的结点
	Status InitList();//构造一个由L指向的空的线性表
	Status DestroyList();//销毁由L指向的线性表
	Status ClearList();//将线性表L置为空表，并释放原链表的头结点
	Status InsFirst(Link s);//将s指向的结点插入线性链表的第一个结点之前
	Status DelFirst(Link &q);//删除表中第一个结点并以q返回
	Status Append(Link s);//将指针s所的一串结点链接在线性表L的最后一个结点
	Status Remove(Link &q);//删除线性表l中的尾结点
	Status InsBefore(Link &p, Link s);//将s所指向结点插入在p所指结点之前
	Status InsAfter(Link &p, Link s);//将s所指向结点插入在p所指结点之后
	Status SetCurElem(Link &p, ElemType e);//用e更新p所指向的当前结点
	ElemType GetCurElem(Link p);//返回p所指结点中元素的值
	Status LisEmpty();//判断线性表是否为空
	int Listlength();//返回线性表中元素个数
	Position GetHead();//返回线性表l中头结点的位置
	Position GetLast();//返回线性表l中最后一个结点的位置
	Position PriorPos(Link p);//返回p所指结点的直接前驱的位置
	Position NextPos(Link p);//返回p所指结点的直接后继的位置
	Status LocatePos(int i, Link &p);//用p返回线性表l中第i个结点的位置，并返回ok
	Position LocatElem(ElemType e, Status(*compare)(ElemType, ElemType));//返回表中第一个与e满足一定函数关系的结点次序位置
	Status ListTraverse(Status(*visit)(ElemType));//用一个函数遍历表中所有结点
}LinkList;


