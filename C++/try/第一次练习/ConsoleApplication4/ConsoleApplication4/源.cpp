#include<stdio.h>                                                    
#include<stdlib.h>  
typedef struct
{
	char v1;
	char v2;
	int weight;
}Edge;
typedef struct {
	Edge space[100];
	int Elength;
}Headtype;
typedef struct {
	char v;
	int flag;
}Dgree;
typedef struct {
	Dgree biao[20];
	int Glength;
}Mark;
void InitMark(Mark &M, int x)
{
	int j;
	M.Glength = x;
	printf("请依次输入这些点:\n");
	for (j = 1; j <= x; j++)
	{
		scanf("%s", &M.biao[j].v);
		M.biao[j].flag = -1;
	}
}
void InitHeadType(Headtype &H, int y)
{
	int k;
	H.Elength = y;
	for (k = 1; k <= y; k++)
	{
		printf("请输入边的关系:\n");
		scanf("%s%s%d", &H.space[k].v1, &H.space[k].v2, &H.space[k].weight);
	}
}
void HeadAdjust(Headtype &H, int s, int m)
{
	Edge rc;
	int p;
	rc = H.space[s];
	for (p = 2 * s; p <= m; p *= 2)
	{
		if (p<m && (H.space[p].weight<H.space[p + 1].weight))
			++p;
		if (rc.weight>H.space[p].weight)
			break;
		H.space[s] = H.space[p];
		s = p;
	}
	H.space[s] = rc;
}
void HeadSort(Headtype &H)
{
	int q;
	Edge rb;
	for (q = H.Elength / 2; q>0; --q)
		HeadAdjust(H, q, H.Elength);
	for (q = H.Elength; q>1; --q)
	{
		rb = H.space[1];
		H.space[1] = H.space[q];
		H.space[q] = rb;
		HeadAdjust(H, 1, q - 1);
	}
}
int main()
{
	int Gnumber, Enumber, a, b, c;
	printf("请输入点的个数:\n");
	scanf("%d", &Gnumber);
	printf("请输入边数:\n");
	scanf("%d", &Enumber);
	Headtype H;
	Mark M;
	Dgree e1, e2;
	InitMark(M, Gnumber);
	InitHeadType(H, Enumber);
	HeadSort(H);
	printf("输出最小生成树;\n");
	for (a = 1; a <= Enumber; a++)
	{
		for (b = 1; b <= Gnumber; b++)
		{
			if (M.biao[b].v == H.space[a].v1)
			{
				e1 = M.biao[b];  break;
			}
		}
		for (c = 1; c <= Gnumber; c++)
		{
			if (M.biao[c].v == H.space[a].v2)
			{
				e2 = M.biao[c];
				break;
			}
		}
		while (e1.flag != -1)
		{
			b = e1.flag;
			e1 = M.biao[e1.flag];
		}
		while (e2.flag != -1)
		{
			c = e2.flag;
			e2 = M.biao[e2.flag];
		}
		if (e2.v != e1.v)
		{
			M.biao[b].flag = c;
			printf("(%c,%c):%d\n", H.space[a].v1, H.space[a].v2, H.space[a].weight);
		}
	}
	return 0;
}