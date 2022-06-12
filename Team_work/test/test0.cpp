#include <stdio.h>    
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXN 100
typedef struct Edge
{
	int to;
	double w;//记录边权
	struct Edge *link;
}Edge; 

typedef struct Node
{
	char name[20];
	Edge *hed;
}Node;

typedef struct GraphLnk
{
	int maxn;
	int cntN;
	int cntE;
	Node *Nodetable;
}GraphLnk;
/*typedef struct ppi_data {
    char name1[10];
    char name2[10];
    double w;
}ppi_data;*/
//字符串数组
void cmp(char nodelib[],char name[],int i){
    int n=0;
    for(;n<i;n++){
        if(strcmp(&nodelib[n],name)){
            if(n==i){
                
            }
        }
        break;
    }
}

void InitGraph(GraphLnk *G){
    G->maxn = MAXN;
    G->cntN = 0;
    G->cntE = 0;
    G->Nodetable = (Node*)malloc(sizeof(Node) * G->maxn);
    assert(G->Nodetable != NULL);
    int i=0;
    for(;i<G->maxn;i++){
        G->Nodetable[i].hed = NULL;
    }
}

void insertNode(GraphLnk *G, const char *p)
{
	if(G->cntN >= G->maxn){
		printf("Warning!The input is wrong.\nThe number of nodes is too much.");
		exit(0);
	}
	int i, flag = 0;
	for(i = 0; i < G->cntN; i++){
		if(strcmp(G->Nodetable[i].name, p) == 0){
			flag = 1;
		}
	}
	if(!flag){
		strcpy(G->Nodetable[G->cntN].name, p);
		G->cntN++;
	}
}

int getNode(GraphLnk *G, const char *p)
{
	int i;
	for(i = 0; i < G->cntN; i++){
		if(strcmp(G->Nodetable[i].name, p) == 0)
			return i;
	}
	return -1;
}



int GetNodePos(GraphLnk *G,char name[]){
    int i=0;
    for(;i<G->cntN;i++){
        if(!strcmp(G->Nodetable[i].name,name)){
            return i;
        }  
    }
    return -1;
}

void InsertEdge(GraphLnk *G,char name1[],char name2[],double w){
    int n1 = GetNodePos(G,name1);
    int n2 = GetNodePos(G,name2);
    if(n1==-1||n2==-1){
        return;
    }
    Edge *s;
    //n1->n2
    s=(Edge *)malloc(sizeof(Edge));
    assert(s != NULL);
    s->to = n2;
    s->link = G->Nodetable[n1].hed;
    s->w = w;
    G->Nodetable[n1].hed = s;
    //n2->n1
    s=(Edge *)malloc(sizeof(Edge));
    assert(s != NULL);
    s->to = n1;
    s->link = G->Nodetable[n2].hed;
    s->w = w;
    G->Nodetable[n2].hed = s;

    G->cntE++;
}

void extract_data(GraphLnk *G)
{
    void insertNode(GraphLnk *G, const char *p);
    char name1[10]={0};
    char name2[10]={0};
    double w;
    char buffer[500]={0};
    FILE *fp;
    char path[100]="G:/WeChat/WeChat Files/wxid_422slv6jnmwy22/FileStorage/File/2022-05/string_interactions.tsv";
    fp = fopen(path,"r");
    if (NULL == fp)
	{
		printf("read file fail\n");
		return ;
	}
    fgets(buffer, sizeof(buffer), fp);
    int col=1;
    int row=1;
    while ( fgets(buffer, sizeof(buffer), fp) > 0) 
	{
		buffer[499] = 0;
        char *p;
        p=strtok(buffer,"\t");
        strcpy(name1,p);
        insertNode(G,p);
        col++;
        for(;(p=strtok(NULL,"\t"));col++){
            
            if(col==2){
                strcpy(name2,p);
                insertNode(G,p);
            }
            if(col==13){
                w=1/atof(p);
            }
        }
		
        col=1;
        row++;
        InsertEdge(G,name2,name1,w);
		//printf("%s\n",name1);
		//printf("%s\n",name2);
		//printf("%f\n",w);
		memset(buffer, 0, sizeof(buffer));
        memset(name1, 0, sizeof(name1));
        memset(name2, 0, sizeof(name2));
	}
}
void ShowGraph(GraphLnk *G){
    Edge *p;
    int i=0;
    for(;i<G->cntN;i++){
        printf("%d %s:>",i,&G->Nodetable[i].name);
        p = G->Nodetable[i].hed;
        while(p!= NULL){
            printf("%d-->",p->to);
            p = p->link;
        }
        printf("Nul.\n");
    }
    printf("\n");
}

void dijkstra(GraphLnk *G, int u, double dis[100][100])
{
    int vis[MAXN] = {0};//flag to imply whether the node is visited
	int i;
    //initialize the distance matrix with maximal value
	for(i = 0; i < MAXN; i++){ 
		dis[u][i] = 0x7fffffff;
	}
	dis[u][u] = 0;//The distance between oneself and oneself is 0
	int cur = u;//current node position
	while(!vis[cur]){
		vis[cur] = 1;
		double minn = 0x7fffffff;
		Edge *p;
		for(p = G->Nodetable[cur].hed; p != NULL; p = p->link){
			int v = p->to;
			if(!vis[v] && dis[u][v] > dis[u][cur] + p->w){
				dis[u][v] = dis[u][cur] + p->w;
			}
		}
        //printf("%s",name);
		for(i = 0; i < G->cntN; i++){
			if(dis[u][i] < minn && !vis[i]){
				minn = dis[u][i];
				cur = i;
			}           
		}
        //printf("->%s",G->Nodetable[cur].name);
	}
    //printf("   distance: %.3f\n",dis[u][cur]);
    int k=u;
    Edge *e;
    for(e = G->Nodetable[k].hed; e != NULL; e = e->link){
        printf("%s->",G->Nodetable[u].name);
        printf("%s: %.3f\n",G->Nodetable[e->to].name,e->w);
    }
}

int main(){
    GraphLnk G;
    InitGraph(&G);
    extract_data(&G);
    //ShowGraph(&G);
    char pro[10]={0};
    scanf("%s",pro);//the original node
    int u = GetNodePos(&G,pro);
    double dis[100][100];
    dijkstra(&G,u,dis);
    
}