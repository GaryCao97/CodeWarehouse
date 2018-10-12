#include<iostream>
#include<vector>
#include<deque>
using namespace std;
#define MAX_SIZE 10000
typedef int Status;
typedef int VertexType;		//��������
typedef struct{
	int Long;
	int Comp;
}InfoType;			//�ߵ���Ϣ Ȩ��
typedef int VisitIf;		//���ʱ�־ 0 δ���� >0 �ѷ���
typedef struct ArcNode {
	int adjvex;					//�û���ָ��Ķ����λ��
	struct ArcNode *nextarc;	//ָ����һ������ָ��
	InfoType info;				//�û������Ϣ��ָ��(��Ȩֵ)
}ArcNode;
typedef struct VNode {
	VertexType data;			//������Ϣ
	ArcNode *firstarc;			//ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MAX_SIZE];//ͷ���ṹ
typedef struct {
	AdjList vexs;
	VisitIf visited[MAX_SIZE];
	int vexnum, arcnum;			//ͼ�ĵ�ǰ�������ͻ���
}ALGraph;						//ͼ�Ľṹ
void InsertArcToGraph(ALGraph &G, int i, ArcNode *u) {
	ArcNode *p = G.vexs[i].firstarc;
	if (!p) {
		u->nextarc = p;
		G.vexs[i].firstarc = u;
	}
	else {
		while (p->nextarc && p->nextarc->adjvex < u->adjvex)p = p->nextarc;
		u->nextarc = p->nextarc;
		p->nextarc = u;
	}
}
int main(){
	ALGraph g;
	int m,n,i,j,k,*sit;
	for(i = 0;i < MAX_SIZE;i++){
		g.vexs[i].data = i;
		g.vexs[i].firstarc = NULL;
	}
	cin >> n;
	for(i = 0;i < n;i++){
		cin >> m;
		sit = new int(m);
		for(j = 0;j < m;j++){
			cin >> sit[j];
		}
		for(j = 0;j < m;j++){
			ArcNode *p;
			for(k = 0;k < m;k++){
				if(k != j){
					p = new ArcNode;
					p->adjvex = sit[k];
					p->info->Long = abs(j-k);
					p->info->Comp = i + 1;
					InsertArcToGraph(G, sit[j], p);
				}
			}
		}
	}
	vector<ArcNode> l,s;
	
	return 0;
}
