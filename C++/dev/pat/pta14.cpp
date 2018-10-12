#include<iostream>
#include<vector>
#include<deque>
using namespace std;
#define MAX_SIZE 10000
typedef int Status;
typedef int VertexType;		//顶点类型
typedef struct{
	int Long;
	int Comp;
}InfoType;			//边的信息 权重
typedef int VisitIf;		//访问标志 0 未访问 >0 已访问
typedef struct ArcNode {
	int adjvex;					//该弧所指向的顶点的位置
	struct ArcNode *nextarc;	//指向下一条弧的指针
	InfoType info;				//该弧相关信息的指针(如权值)
}ArcNode;
typedef struct VNode {
	VertexType data;			//顶点信息
	ArcNode *firstarc;			//指向第一条依附该顶点的弧的指针
}VNode, AdjList[MAX_SIZE];//头结点结构
typedef struct {
	AdjList vexs;
	VisitIf visited[MAX_SIZE];
	int vexnum, arcnum;			//图的当前顶点数和弧数
}ALGraph;						//图的结构
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
