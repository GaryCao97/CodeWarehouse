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
	Status MakeNode(Link &p, ElemType e);//������pָ��Ľ�㲢��ֵΪe
	void FreeNode(Link &p);//�ͷ�p��ָ��Ľ��
	Status InitList();//����һ����Lָ��Ŀյ����Ա�
	Status DestroyList();//������Lָ������Ա�
	Status ClearList();//�����Ա�L��Ϊ�ձ����ͷ�ԭ�����ͷ���
	Status InsFirst(Link s);//��sָ��Ľ�������������ĵ�һ�����֮ǰ
	Status DelFirst(Link &q);//ɾ�����е�һ����㲢��q����
	Status Append(Link s);//��ָ��s����һ��������������Ա�L�����һ�����
	Status Remove(Link &q);//ɾ�����Ա�l�е�β���
	Status InsBefore(Link &p, Link s);//��s��ָ���������p��ָ���֮ǰ
	Status InsAfter(Link &p, Link s);//��s��ָ���������p��ָ���֮��
	Status SetCurElem(Link &p, ElemType e);//��e����p��ָ��ĵ�ǰ���
	ElemType GetCurElem(Link p);//����p��ָ�����Ԫ�ص�ֵ
	Status LisEmpty();//�ж����Ա��Ƿ�Ϊ��
	int Listlength();//�������Ա���Ԫ�ظ���
	Position GetHead();//�������Ա�l��ͷ����λ��
	Position GetLast();//�������Ա�l�����һ������λ��
	Position PriorPos(Link p);//����p��ָ����ֱ��ǰ����λ��
	Position NextPos(Link p);//����p��ָ����ֱ�Ӻ�̵�λ��
	Status LocatePos(int i, Link &p);//��p�������Ա�l�е�i������λ�ã�������ok
	Position LocatElem(ElemType e, Status(*compare)(ElemType, ElemType));//���ر��е�һ����e����һ��������ϵ�Ľ�����λ��
	Status ListTraverse(Status(*visit)(ElemType));//��һ�����������������н��
}LinkList;


