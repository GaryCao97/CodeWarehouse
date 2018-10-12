#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
//#define INFEASIBLE  -1
//#define OVERFLOW    -2

typedef int Status;
#define MAX_VERTEX_NUM 20		//��󶥵����
typedef char VertexType;		//��������
typedef int InfoType;			//�ߵ���Ϣ Ȩ��
typedef int VRType;				//�����ϵ����Ȩͼ�е��ڽ���񣬴�Ȩͼ�е�Ȩֵ
typedef int VisitIf;		//���ʱ�־ 0 δ���� >0 �ѷ���
typedef int GraphKind;		//{����ͼ=0��������=1������ͼ=2��������=3}
//
//ͼ�������ʾ���ڽӾ���
#define INFINITY INT_MAX		//���ֵ
typedef struct ArcCell {
	VRType adj; //VRType�Ƕ����ϵ���͡�������Ȩͼ����1��0��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ���͡�
	char * info;//�û������Ϣ��ָ�� 
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ��� 
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM]; //��������
	VisitIf visited[MAX_VERTEX_NUM];
	AdjMatrix arcs;                  //�ڽӾ���
	int vexnum, arcnum;               //ͼ�ĵ�ǰ�������ͻ���
	GraphKind kind;                  //ͼ�������־
}MGraph;
Status CreateGraph(MGraph &G);//�ڽӾ���ͼ
int LocateVex(MGraph G, VertexType u);//ȷ��λ��
VertexType FirstAdjVex(MGraph G, VertexType v);//����v�ĵ�һ���ڽӶ��㡣
VertexType NextAdjVex(MGraph G, VertexType v, VertexType w);//����v�ģ������w�ģ���һ���ڽӶ��㡣
Status CreateDG(MGraph &G);//�ڽӾ�������ͼ
Status CreateDN(MGraph &G);//�ڽӾ���������
Status CreateUDG(MGraph &G);//�ڽӾ�������ͼ
Status CreateUDN(MGraph &G);//�ڽӾ���������
Status DFSTraverse(MGraph G, Status(*Visit)(VertexType));//��ͼ����������ȱ�����
Status BFSTraverse(MGraph G, Status(*Visit)(VertexType));//��ͼ���й�����ȱ�����
typedef struct {
	VertexType  adjvex;
	VRType     lowcost;
}ClosEdge;
typedef struct {
	VertexType *adjvex;
	int len;
}VexSet;
typedef struct {
	int i, j;
	VRType adj;
}ArcSet;
Status MiniSpanTree_PRIM(MGraph G, VertexType u);//������ķ�㷨�ӵ�u���������������G����С������T�����T�ĸ�����
Status MiniSpanTree_KRUSKAL(MGraph G);//�ÿ�³˹�����㷨������G����С������T�����T�ĸ�����
//
//ͼ���ڽӱ��ʾ
typedef struct ArcNode {
	int adjvex;					//�û���ָ��Ķ����λ��
	struct ArcNode *nextarc;	//ָ����һ������ָ��
	InfoType *info;				//�û������Ϣ��ָ��(��Ȩֵ)
}ArcNode;
typedef struct VNode {
	VertexType data;			//������Ϣ
	ArcNode *firstarc;			//ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];//ͷ���ṹ
typedef struct {
	AdjList vexs;
	VisitIf visited[MAX_VERTEX_NUM];
	int vexnum, arcnum;			//ͼ�ĵ�ǰ�������ͻ���
	int kind;					//ͼ�������־
}ALGraph;						//ͼ�Ľṹ
Status InsertArcToGraph(ALGraph &G, int i, ArcNode *u);//���߲���
Status CreateGraph(ALGraph &G);//�ڽӾ���ͼ
int LocateVex(ALGraph G, VertexType u);//ȷ��λ��
VertexType FirstAdjVex(ALGraph G, VertexType v);//����v�ĵ�һ���ڽӶ��㡣
VertexType NextAdjVex(ALGraph G, VertexType v, VertexType w);//����v�ģ������w�ģ���һ���ڽӶ��㡣
Status CreateDG(ALGraph &G);//�ڽӱ�����ͼ
Status CreateDN(ALGraph &G);//�ڽӱ�������
Status CreateUDG(ALGraph &G);//�ڽӱ�����ͼ
Status CreateUDN(ALGraph &G);//�ڽӱ�������
Status DFSTraverse(ALGraph G, Status(*Visit)(VertexType));//��ͼ����������ȱ�����
Status BFSTraverse(ALGraph G, Status(*Visit)(VertexType));//��ͼ���й�����ȱ�����
//
//����ͼ��ʮ�������ʾ
typedef struct ArcBox {
	int tailvex, headvex;
	ArcBox *hlink, *tlink;
	InfoType *info;
}ArcBox;
typedef struct VexNode {
	VertexType data;
	ArcBox *firstin, *firstout;
}VexNode;
typedef struct {
	VexNode xlist[MAX_VERTEX_NUM];
	VisitIf visited[MAX_VERTEX_NUM];
	int vexnum, arcnum;
}OLGraph;
Status CreateGraph(OLGraph &G);//ʮ������ͼ
Status CreateDG(OLGraph &G);//ʮ����������ͼ
int LocateVex(OLGraph G, VertexType u);//ȷ��λ��
VertexType FirstAdjVex(OLGraph G, VertexType v);//����v�ĵ�һ���ڽӶ��㡣
VertexType NextAdjVex(OLGraph G, VertexType v, VertexType w);//����v�ģ������w�ģ���һ���ڽӶ��㡣
Status DFSTraverse(OLGraph G, Status(*Visit)(VertexType));//��ͼ����������ȱ�����
Status BFSTraverse(OLGraph G, Status(*Visit)(VertexType));//��ͼ���й�����ȱ�����
//
//����ͼ���ڽӶ��ر��ʾ
typedef struct EBox {
	VisitIf mark;			//���ʱ��
	int ivex, jvex;			//�ñ����������������λ��
	EBox *ilink, *jlink;	//�ֱ�ָ�������������������һ����
	InfoType *info;			//�ñ���Ϣָ��
}EdgeBox;
typedef struct VexBox {
	VertexType data;
	EdgeBox *firstedge;		//ָ���һ�������ö���ı�
}VexBox;
typedef struct {
	VisitIf visited[MAX_VERTEX_NUM];
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum, edgenum;	//����ͼ�ĵ�ǰ�������ͱ���
}AMLGraph;
Status CreateGraph(AMLGraph &G);//�ڽӶ��ر�ͼ
Status CreateUDG(AMLGraph &G);//�ڽӶ��ر�����ͼ
int LocateVex(AMLGraph G, VertexType u);//ȷ��λ��
VertexType FirstAdjVex(AMLGraph G, VertexType v);//����v�ĵ�һ���ڽӶ��㡣
VertexType NextAdjVex(AMLGraph G, VertexType v, VertexType w);//����v�ģ������w�ģ���һ���ڽӶ��㡣
Status DFSTraverse(AMLGraph G, Status(*Visit)(VertexType));//��ͼ����������ȱ�����
Status BFSTraverse(AMLGraph G, Status(*Visit)(VertexType));//��ͼ���й�����ȱ�����

int GetPathNum(MGraph G, int i, int j, int k) {
	int l = G.vexnum, m, n, o, t;
	int **adj = (int **)malloc(l * sizeof(int*));
	int **ans = (int **)malloc(l * sizeof(int*));
	int **tmp = (int **)malloc(l * sizeof(int*));
	for (m = 0; m < l; m++) {
		adj[m] = (int *)malloc(l * sizeof(int));
		ans[m] = (int *)malloc(l * sizeof(int));
		tmp[m] = (int *)malloc(l * sizeof(int));
		for (n = 0; n < l; n++){
			adj[m][n] = G.arcs[m][n].adj;
			ans[m][n] = G.arcs[m][n].adj;
			if (m == n) {
				ans[m][n] = 0;
				adj[m][n] = 0;
			}
			tmp[m][n] = 0;
		}
	}
	for(t = 1;t < k;t++){
		for (m = 0; m < l; m++)
			for (n = 0; n < l; n++) {
				tmp[m][n] = 0;
				for (o = 0; o < l; o++) 
					tmp[m][n] += ans[m][o] * adj[o][n];
				if (m == n)tmp[m][n] = 0;
			}
		for (m = 0; m < l; m++)
			for (n = 0; n < l; n++)
				ans[m][n] = tmp[m][n];
	}
	return ans[i][j];
}

Status visit(VertexType d) {
	cout << d << " ";
	return OK;
}
int main() {
	MGraph G1;
	ALGraph G2;
	OLGraph G3;
	AMLGraph G4;
	CreateGraph(G1);
	DFSTraverse(G1, visit);
	BFSTraverse(G1, visit);
	//CreateGraph(G2);
	//DFSTraverse(G2, visit);
	//BFSTraverse(G2, visit);
	//CreateGraph(G3);
	//DFSTraverse(G3, visit);
	//BFSTraverse(G3, visit);
	//CreateGraph(G4);
	//DFSTraverse(G4, visit);
	//BFSTraverse(G4, visit);
	return 0;
}

Status CreateGraph(MGraph &G) {
	cout << "��ѡ��Ҫ������ͼ�����ͣ�" << endl << "����ͼ\t0\n������\t1\n����ͼ\t2\n������\t3\n";
	cin >> G.kind;
	switch (G.kind) {
	case 0:return CreateDG(G);
	case 1:return CreateDN(G);
	case 2:return CreateUDG(G);
	case 3:return CreateUDN(G);
	default:return ERROR;
	}
}
int LocateVex(MGraph G, VertexType u) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == u)return i;
	return -1;
}
VertexType FirstAdjVex(MGraph G, VertexType v) {
	int i = LocateVex(G, v), j;
	if (G.kind == 0 || G.kind == 2)
		for (j = 0; j < G.vexnum && G.arcs[i][j].adj == 0; j++);
	else if (G.kind == 1 || G.kind == 3)
		for (j = 0; j < G.vexnum && G.arcs[i][j].adj == INFINITY; j++);
	if (j == G.vexnum)return -1;
	return G.vexs[j];
}
VertexType NextAdjVex(MGraph G, VertexType v, VertexType w) {
	int i = LocateVex(G, v), j = LocateVex(G, w) + 1;
	if (G.kind == 0 || G.kind == 2)
		for (; j < G.vexnum && G.arcs[i][j].adj == 0; j++);
	else if (G.kind == 1 || G.kind == 3)
		for (; j < G.vexnum && G.arcs[i][j].adj == INFINITY; j++);
	if (j == G.vexnum)return -1;
	return G.vexs[j];
}
Status CreateDG(MGraph &G) {
	int i, j, k;
	VertexType  v1, v2;
	cout << "�����붥�����Ŀ��";
	cin >> G.vexnum;
	cout << "�����뻡����Ŀ��";
	cin >> G.arcnum;
	for (i = 0; i<G.vexnum; i++) {
		cout << "�������" << i + 1 << "������";
		cin >> G.vexs[i];
	}
	for (i = 0; i<G.vexnum; ++i)
		for (j = 0; j<G.vexnum; ++j) {
			G.arcs[i][j].adj = 0;
			G.arcs[i][j].info = NULL;
		}
	for (k = 0; k<G.arcnum; ++k) {
		cout << "��������ʼ�� (�ַ�)��";
		cin >> v1;
		cout << "��������ֹ�� (�ַ�)��";
		cin >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = 1;
	}
	return OK;
}
Status CreateDN(MGraph &G) {
	int i, j, k, w;
	VertexType  v1, v2;
	cout << "�����붥�����Ŀ��";
	cin >> G.vexnum;
	cout << "�����뻡����Ŀ��";
	cin >> G.arcnum;
	for (i = 0; i<G.vexnum; i++) {
		cout << "�������" << i + 1 << "������";
		cin >> G.vexs[i];
	}
	for (i = 0; i<G.vexnum; ++i)
		for (j = 0; j<G.vexnum; ++j) {
			G.arcs[i][j].adj = INFINITY;
			G.arcs[i][j].info = NULL;
		}
	for (k = 0; k<G.arcnum; ++k) {
		cout << "��������ʼ�� (�ַ�)��";
		cin >> v1;
		cout << "��������ֹ�� (�ַ�)��";
		cin >> v2;
		cout << "������Ȩֵ��";
		cin >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;
	}
	return OK;
}
Status CreateUDG(MGraph &G) {
	int i, j, k;
	VertexType  v1, v2;
	cout << "�����붥�����Ŀ��";
	cin >> G.vexnum;
	cout << "������ߵ���Ŀ��";
	cin >> G.arcnum;
	for (i = 0; i<G.vexnum; i++) {
		cout << "�������" << i + 1 << "������";
		cin >> G.vexs[i];
	}
	for (i = 0; i<G.vexnum; ++i)
		for (j = 0; j<G.vexnum; ++j) {
			G.arcs[i][j].adj = 0;
			G.arcs[i][j].info = NULL;
		}
	for (k = 0; k<G.arcnum; ++k) {
		cout << "��������ʼ�� (�ַ�)��";
		cin >> v1;
		cout << "��������ֹ�� (�ַ�)��";
		cin >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = 1;
		G.arcs[j][i].adj = G.arcs[i][j].adj;
	}
	return OK;
}
Status CreateUDN(MGraph &G) {
	int i, j, k, w;
	VertexType  v1, v2;
	cout << "�����붥�����Ŀ��";
	cin >> G.vexnum;
	cout << "������ߵ���Ŀ��";
	cin >> G.arcnum;
	for (i = 0; i<G.vexnum; i++) {
		cout << "�������" << i + 1 << "������ (�ַ�)";
		cin >> G.vexs[i];
	}
	for (i = 0; i<G.vexnum; ++i)
		for (j = 0; j<G.vexnum; ++j) {
			G.arcs[i][j].adj = INFINITY;
			G.arcs[i][j].info = NULL;
		}
	for (k = 0; k<G.arcnum; ++k) {
		cout << "��������ʼ�� (�ַ�)��";
		cin >> v1;
		cout << "��������ֹ�� (�ַ�)��";
		cin >> v2;
		cout << "������Ȩֵ��";
		cin >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;
		G.arcs[j][i].adj = G.arcs[i][j].adj;
	}
	return OK;
}
void DFS(MGraph &G, VertexType v, Status(*Visit)(VertexType)) {
	G.visited[LocateVex(G, v)] = 1;
	Visit(v);
	for (VertexType w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		if (G.visited[LocateVex(G, w)] == 0)
			DFS(G, w, Visit);
}
Status DFSTraverse(MGraph G, Status(*Visit)(VertexType)) {
	cout << "ͼ��������ȱ�����";
	for (int i = 0; i < G.vexnum; ++i)
		G.visited[i] = 0;
	for (int v = 0; v < G.vexnum; ++v)
		if (G.visited[v] == 0)
			DFS(G, G.vexs[v], Visit);
	cout << endl;
	return OK;
}
Status BFSTraverse(MGraph G, Status(*Visit)(VertexType)) {
	cout << "ͼ�Ĺ�����ȱ�����";
	VertexType v, w;
	queue<VertexType> Q;
	VertexType u;
	for (int i = 0; i<G.vexnum; ++i) G.visited[i] = 0;
	for (int i = 0; i < G.vexnum; ++i)
		if (G.visited[i] == 0) {
			v = G.vexs[i];
			G.visited[i] = 1;
			Visit(v);
			Q.push(v);
			while (!Q.empty()) {
				u = Q.front();
				Q.pop();
				for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
					if (G.visited[LocateVex(G, w)] == 0) {
						G.visited[LocateVex(G, w)] = 1;
						Visit(w);
						Q.push(w);
					}
			}
		}
	cout << endl;
	return OK;
}
int minimum(ClosEdge *clos, int num) {
	int min, tag = 0;
	for(int i = 0;i < num;i++){
		if (clos[i].lowcost > 0) {
			if (tag == 0) tag = 1, min = i;
			else min = clos[i].lowcost < clos[min].lowcost ? i : min;
		}
	}
	return min;
}
Status MiniSpanTree_PRIM(MGraph G, VertexType u) {
	cout << "����ķ�㷨������С��������" << endl;
	ClosEdge closedge[MAX_VERTEX_NUM];
	int i, j, k;
	k = LocateVex(G, u);
	for (j = 0; j<G.vexnum; ++j) {
		if (j != k) {
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j].adj;
		}
	}
	closedge[k].lowcost = 0;
	for (i = 1; i<G.vexnum; ++i) {
		k = minimum(closedge, G.vexnum);
		cout << closedge[k].adjvex << ' ' << G.vexs[k] << endl;
		closedge[k].lowcost = 0;
		for (j = 0; j<G.vexnum; ++j)
			if (G.arcs[k][j].adj < closedge[j].lowcost) {
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j].adj;
			}
	}
	return OK;
}
void UnionSet(VexSet *vex,int i,int j, int num) {
	VexSet *v = new VexSet;
	v->len = vex[i].len + vex[j].len;
	v->adjvex = new VertexType[v->len];
	for (int k = 0; k < v->len; k++) {
		if (k < vex[i].len)v->adjvex[k] = vex[i].adjvex[k];
		else v->adjvex[k] = vex[j].adjvex[k - vex[i].len];
	}
	for (int k = 0; k < num; k++) {
		if (k != i && k != j) {
			if (vex[k].adjvex == vex[i].adjvex || vex[k].adjvex == vex[j].adjvex)
				vex[k].adjvex = v->adjvex;
		}
	}
	vex[i].adjvex = vex[j].adjvex = v->adjvex;
}
int comp(ArcSet a1, ArcSet a2) {
	return a1.adj < a2.adj;
}
Status MiniSpanTree_KRUSKAL(MGraph G) {
	cout << "��³˹�����㷨������С��������" << endl;
	VexSet *vex = new VexSet[G.vexnum];
	ArcSet *arc = new ArcSet[G.arcnum];
	int i, j, k = 0, l;
	for (i = 0; i < G.vexnum; i++)
		for (j = i; j < G.vexnum; j++)
			if (G.arcs[i][j].adj > 0 && G.arcs[i][j].adj != INFINITY) {
				arc[k].i = i;
				arc[k].j = j;
				arc[k].adj = G.arcs[i][j].adj;
				k++;
			}
	sort(arc, arc + G.arcnum, comp);
	for (i = 0; i < G.vexnum; i++) {
		vex[i].len = 1;
		vex[i].adjvex = new VertexType;
		*(vex[i].adjvex) = G.vexs[i];
	}
	for (l = 0,k = 1; k < G.vexnum; k++) {
		i = arc[l].i;
		j = arc[l].j;
		l++;
		if (vex[i].adjvex != vex[j].adjvex) {
			cout << G.vexs[i] << " " << G.vexs[j] << endl;
			UnionSet(vex, i, j, G.vexnum);
		}
		else
			k--;
	}
	return OK;
}

Status CreateGraph(ALGraph & G) {
	cout << "��ѡ��Ҫ������ͼ�����ͣ�" << endl << "����ͼ\t0\n������\t1\n����ͼ\t2\n������\t3\n";
	cin >> G.kind;
	switch (G.kind) {
	case 0: return CreateDG(G);
	case 1: return CreateDN(G);
	case 2: return CreateUDG(G);
	case 3: return CreateUDN(G);
	default:return ERROR;
	}
	return OK;
}
Status InsertArcToGraph(ALGraph &G, int i, ArcNode *u) {
	ArcNode *p = G.vexs[i].firstarc;
	if (!p) {
		u->nextarc = p;
		G.vexs[i].firstarc = u;
	}
	else{
		while (p->nextarc && p->nextarc->adjvex < u->adjvex)p = p->nextarc;
		u->nextarc = p->nextarc;
		p->nextarc = u;
	}
	return OK;
}
int LocateVex(ALGraph G, VertexType u) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexs[i].data == u)return i;
	return -1;
}
VertexType FirstAdjVex(ALGraph G, VertexType v) {
	int i = LocateVex(G, v);
	if (G.vexs[i].firstarc == NULL)return -1;
	return G.vexs[G.vexs[i].firstarc->adjvex].data;
}
VertexType NextAdjVex(ALGraph G, VertexType v, VertexType w) {
	int i = LocateVex(G, v);
	ArcNode *p = G.vexs[i].firstarc;
	while (p) {
		if (G.vexs[p->adjvex].data == w)break;
		p = p->nextarc;
	}
	if (p->nextarc == NULL)return -1;
	return G.vexs[p->nextarc->adjvex].data;
}
Status CreateDG(ALGraph & G) {
	int i, j, k;
	VertexType  v1, v2;
	ArcNode *p;
	cout << "�����붥�����Ŀ��";
	cin >> G.vexnum;
	cout << "������ߵ���Ŀ��";
	cin >> G.arcnum;
	for (i = 0; i < G.vexnum; i++) {
		cout << "�������" << i + 1 << "������ (�ַ�)";
		cin >> G.vexs[i].data;
		G.vexs[i].firstarc = NULL;
	}
	for (k = 0; k<G.arcnum; k++) {
		cout << "��������ʼ�� (�ַ�)��";
		cin >> v1;
		cout << "��������ֹ�� (�ַ�)��";
		cin >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = NULL;
		InsertArcToGraph(G, i, p);
	}
	return OK;
}
Status CreateDN(ALGraph & G) {
	int i, j, k, w;
	VertexType  v1, v2;
	ArcNode *p;
	cout << "�����붥�����Ŀ��";
	cin >> G.vexnum;
	cout << "������ߵ���Ŀ��";
	cin >> G.arcnum;
	for (i = 0; i < G.vexnum; i++) {
		cout << "�������" << i + 1 << "������ (�ַ�)";
		cin >> G.vexs[i].data;
		G.vexs[i].firstarc = NULL;
	}
	for (k = 0; k<G.arcnum; k++) {
		cout << "��������ʼ�� (�ַ�)��";
		cin >> v1;
		cout << "��������ֹ�� (�ַ�)��";
		cin >> v2;
		cout << "������Ȩֵ��";
		cin >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = new int();
		*(p->info) = w;
		InsertArcToGraph(G, i, p);
	}
	return OK;
}
Status CreateUDG(ALGraph & G) {
	int i, j, k;
	VertexType  v1, v2;
	ArcNode *p;
	cout << "�����붥�����Ŀ��";
	cin >> G.vexnum;
	cout << "������ߵ���Ŀ��";
	cin >> G.arcnum;
	for (i = 0; i < G.vexnum; i++) {
		cout << "�������" << i + 1 << "������ (�ַ�)";
		cin >> G.vexs[i].data;
		G.vexs[i].firstarc = NULL;
	}
	for (k = 0; k<G.arcnum; k++) {
		cout << "��������ʼ�� (�ַ�)��";
		cin >> v1;
		cout << "��������ֹ�� (�ַ�)��";
		cin >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = NULL;
		InsertArcToGraph(G, i, p);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->info = NULL;
		InsertArcToGraph(G, j, p);
	}
	return OK;
}
Status CreateUDN(ALGraph & G) {
	int i, j, k, w;
	VertexType  v1, v2;
	ArcNode *p;
	cout << "�����붥�����Ŀ��";
	cin >> G.vexnum;
	cout << "������ߵ���Ŀ��";
	cin >> G.arcnum;
	for (i = 0; i < G.vexnum; i++) {
		cout << "�������" << i + 1 << "������ (�ַ�)";
		cin >> G.vexs[i].data;
		G.vexs[i].firstarc = NULL;
	}
	for (k = 0; k<G.arcnum; k++) {
		cout << "��������ʼ�� (�ַ�)��";
		cin >> v1;
		cout << "��������ֹ�� (�ַ�)��";
		cin >> v2;
		cout << "������Ȩֵ��";
		cin >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = new int();
		*(p->info) = w;
		InsertArcToGraph(G, i, p);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->info = new int();
		*(p->info) = w;
		InsertArcToGraph(G, j, p);
	}
	return OK;
}
void DFS(ALGraph &G, VertexType v, Status(*Visit)(VertexType)) {
	G.visited[LocateVex(G, v)] = 1;
	Visit(v);
	for (VertexType w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		if (G.visited[LocateVex(G, w)] == 0)
			DFS(G, w, Visit);
}
Status DFSTraverse(ALGraph G, Status(*Visit)(VertexType)) {
	cout << "ͼ��������ȱ�����";
	for (int i = 0; i < G.vexnum; ++i)
		G.visited[i] = 0;
	for (int v = 0; v < G.vexnum; ++v)
		if (G.visited[v] == 0)
			DFS(G, G.vexs[v].data, Visit);
	cout << endl;
	return OK;
}
Status BFSTraverse(ALGraph G, Status(*Visit)(VertexType)) {
	cout << "ͼ�Ĺ�����ȱ�����";
	VertexType v, w;
	queue<VertexType> Q;
	VertexType u;
	for (int i = 0; i<G.vexnum; ++i) G.visited[i] = 0;
	for (int i = 0; i < G.vexnum; ++i)
		if (G.visited[i] == 0) {
			v = G.vexs[i].data;
			G.visited[i] = 1;
			Visit(v);
			Q.push(v);
			while (!Q.empty()) {
				u = Q.front();
				Q.pop();
				for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
					if (G.visited[LocateVex(G, w)] == 0) {
						G.visited[LocateVex(G, w)] = 1;
						Visit(w);
						Q.push(w);
					}
			}
		}
	cout << endl;
	return OK;
}

Status CreateGraph(OLGraph &G) {
	return CreateDG(G);
}
Status CreateDG(OLGraph & G) {
	int i, j, k;
	VertexType  v1, v2;
	ArcBox *p;
	cout << "�����붥�����Ŀ��";
	cin >> G.vexnum;
	cout << "������ߵ���Ŀ��";
	cin >> G.arcnum;
	for (i = 0; i < G.vexnum; ++i) {
		cout << "�������" << i + 1 << "������ (�ַ�)";
		cin >> G.xlist[i].data;
		G.xlist[i].firstin = G.xlist[i].firstout = NULL;
	}
	for (k = 0; k < G.arcnum; ++k) {
		cout << "��������ʼ�� (�ַ�)��";
		cin >> v1;
		cout << "��������ֹ�� (�ַ�)��";
		cin >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcBox *)malloc(sizeof(ArcBox));
		p->headvex = i;
		p->tailvex = j;
		p->hlink = G.xlist[i].firstout;
		p->tlink = G.xlist[j].firstin;
		p->info = NULL;
		G.xlist[j].firstin = G.xlist[i].firstout = p;
	}
	return OK;
}
int LocateVex(OLGraph G, VertexType u) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.xlist[i].data == u)return i;
	return -1;
}
VertexType FirstAdjVex(OLGraph G, VertexType v) {
	int i = LocateVex(G, v);
	if (G.xlist[i].firstout == NULL)return -1;
	return G.xlist[G.xlist[i].firstout->tailvex].data;
}
VertexType NextAdjVex(OLGraph G, VertexType v, VertexType w) {
	int i = LocateVex(G, v);
	ArcBox *p = G.xlist[i].firstout;
	while (p) {
		if (G.xlist[p->tailvex].data == w)break;
		p = p->hlink;
	}
	if (p->hlink == NULL)return -1;
	return G.xlist[p->hlink->tailvex].data;
}
void DFS(OLGraph &G, VertexType v, Status(*Visit)(VertexType)) {
	G.visited[LocateVex(G, v)] = 1;
	Visit(v);
	for (VertexType w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		if (G.visited[LocateVex(G, w)] == 0)
			DFS(G, w, Visit);
}
Status DFSTraverse(OLGraph G, Status(*Visit)(VertexType)) {
	cout << "ͼ��������ȱ�����";
	for (int i = 0; i < G.vexnum; ++i)
		G.visited[i] = 0;
	for (int v = 0; v < G.vexnum; ++v)
		if (G.visited[v] == 0)
			DFS(G, G.xlist[v].data, Visit);
	cout << endl;
	return OK;
}
Status BFSTraverse(OLGraph G, Status(*Visit)(VertexType)) {
	cout << "ͼ�Ĺ�����ȱ�����";
	VertexType v, w;
	queue<VertexType> Q;
	VertexType u;
	for (int i = 0; i<G.vexnum; ++i) G.visited[i] = 0;
	for (int i = 0; i < G.vexnum; ++i)
		if (G.visited[i] == 0) {
			v = G.xlist[i].data;
			G.visited[i] = 1;
			Visit(v);
			Q.push(v);
			while (!Q.empty()) {
				u = Q.front();
				Q.pop();
				for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
					if (G.visited[LocateVex(G, w)] == 0) {
						G.visited[LocateVex(G, w)] = 1;
						Visit(w);
						Q.push(w);
					}
			}
		}
	cout << endl;
	return OK;
}

Status CreateGraph(AMLGraph &G) {
	return CreateUDG(G);
}
Status CreateUDG(AMLGraph & G) {
	int i, j, k;
	VertexType  v1, v2;
	EdgeBox *p;
	cout << "�����붥�����Ŀ��";
	cin >> G.vexnum;
	cout << "������ߵ���Ŀ��";
	cin >> G.edgenum;
	for (i = 0; i < G.vexnum; i++) {
		cout << "�������" << i + 1 << "������ (�ַ�)";
		cin >> G.adjmulist[i].data;
		G.adjmulist[i].firstedge = NULL;
	}
	for (k = 0; k<G.edgenum; k++) {
		cout << "��������ʼ�� (�ַ�)��";
		cin >> v1;
		cout << "��������ֹ�� (�ַ�)��";
		cin >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (EdgeBox*)malloc(sizeof(EdgeBox));
		p->ivex = i;
		p->jvex = j;
		p->ilink = G.adjmulist[i].firstedge;
		p->jlink = G.adjmulist[j].firstedge;
		G.adjmulist[i].firstedge = p;
		G.adjmulist[j].firstedge = p;
		p->info = NULL;
	}
	return OK;
}
int LocateVex(AMLGraph G, VertexType u) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.adjmulist[i].data == u)return i;
	return -1;
}
VertexType FirstAdjVex(AMLGraph G, VertexType v) {
	int i = LocateVex(G, v);
	if (G.adjmulist[i].firstedge == NULL)return -1;
	if (G.adjmulist[i].firstedge->ivex == i)
		return G.adjmulist[G.adjmulist[i].firstedge->jvex].data;
	else return G.adjmulist[G.adjmulist[i].firstedge->ivex].data;
}
VertexType NextAdjVex(AMLGraph G, VertexType v, VertexType w) {
	int i = LocateVex(G, v), j;
	EdgeBox *p = G.adjmulist[i].firstedge;
	while (p) {
		if (p->ivex == i) {
			j = p->jvex;
			p = p->ilink;
		}
		else {
			j = p->ivex;
			p = p->jlink;
		}
		if (G.adjmulist[j].data == w)
			break;
	}
	if (p == NULL)return -1;
	if (p->ivex == i)
		return G.adjmulist[p->jvex].data;
	else return G.adjmulist[p->ivex].data;
}
void DFS(AMLGraph &G, VertexType v, Status(*Visit)(VertexType)) {
	G.visited[LocateVex(G, v)] = 1;
	Visit(v);
	for (VertexType w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		if (G.visited[LocateVex(G, w)] == 0)
			DFS(G, w, Visit);
}
Status DFSTraverse(AMLGraph G, Status(*Visit)(VertexType)) {
	cout << "ͼ��������ȱ�����";
	for (int i = 0; i < G.vexnum; ++i)
		G.visited[i] = 0;
	for (int v = 0; v < G.vexnum; ++v)
		if (G.visited[v] == 0)
			DFS(G, G.adjmulist[v].data, Visit);
	cout << endl;
	return OK;
}
Status BFSTraverse(AMLGraph G, Status(*Visit)(VertexType)) {
	cout << "ͼ�Ĺ�����ȱ�����";
	VertexType v, w;
	queue<VertexType> Q;
	VertexType u;
	for (int i = 0; i<G.vexnum; ++i) G.visited[i] = 0;
	for (int i = 0; i < G.vexnum; ++i)
		if (G.visited[i] == 0) {
			v = G.adjmulist[i].data;
			G.visited[i] = 1;
			Visit(v);
			Q.push(v);
			while (!Q.empty()) {
				u = Q.front();
				Q.pop();
				for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
					if (G.visited[LocateVex(G, w)] == 0) {
						G.visited[LocateVex(G, w)] = 1;
						Visit(w);
						Q.push(w);
					}
			}
		}
	cout << endl;
	return OK;
}