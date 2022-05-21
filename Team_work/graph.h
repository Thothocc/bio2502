#ifndef GRAPH_H
#define GRAPH_H

typedef struct Edge
{
	int to;
	double w;
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
	Node *tab;
}GraphLnk;

void initGraph(GraphLnk *G);
void insertNode(GraphLnk *G, const char *p);
int getNode(GraphLnk *G, const char *p);
void insertEdge(GraphLnk *G, const char *u, const char *v, double val);

#endif

