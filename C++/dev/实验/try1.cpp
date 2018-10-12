#include <stdio.h>
#include <vector>
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
void LongestPath(BiTree bt)//��������еĵ�һ���·������,������·���ϵĽڵ�
{
	BiTree p = bt; //l, s��ջ��Ԫ���Ƕ��������ָ�룬l�б�����ǰ�·���еĽ��
	vector<BiTree> l,s;
	int i,top = 0, longest = 0;
	vector<int> tag;
	while (p || top >0)
	{
		while (p)
		{
			s[++top] = p;
			tag[top] = 0;
			p = p->lchild;
		} //�����֦����
		if (tag[top] == 1)    //��ǰ�����ҷ�֦�ѱ���
		{
			if (!s[top]->lchild && !s[top]->rchild)  //ֻ�е�Ҷ�ӽ��ʱ���Ų鿴·������
				if (top>longest)
				{
					for (i = 1; i <= top; i++)
						l[i] = s[i];
					longest = top;
					top--;
				}//������ǰ�·����lջ����ס���ջ��ָ�룬��ջ
		}
		else if (top>0)
		{
			tag[top] = 1;
			p = s[top]->rchild;
		}   //�����ӷ�֦����
	}//while(p!=null||top>0)
	int k = 0;
	for (k = 0; k < longest; k++)
	{
		printf("%d ", l[k]->data);
	}
}//����LongestPath
