#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "graph.h"
#define MAXN 100

/*
	Initialize the graph.
**/
void initGraph(GraphLnk *G)          
{
	G->maxn = MAXN;
	G->cntE = 0;
	G->cntN = 0;
	G->tab = (Node*)malloc(sizeof(Node) * MAXN);
	assert(G->tab != NULL);
	int i;
	for(i = 0; i < G->maxn; i++){
		G->tab[i].hed = NULL;
	}
}

/*
	Insert a node into the graph.
**/
void insertNode(GraphLnk *G, const char *p)
{
	if(G->cntN >= G->maxn){
		printf("Warning!The input is wrong.\nThe number of nodes is too much.");
		exit(0);
	}
	int i, flag = 0;
	for(i = 0; i < G->cntN; i++){
		if(strcmp(G->tab[i].name, p) == 0){
			flag = 1;
		}
	}
	if(!flag){
		strcpy(G->tab[G->cntN].name, p);
		G->cntN++;
	}
}

/*
	Get the node ID from the graph. 
**/
int getNode(GraphLnk *G, const char *p)
{
	int i;
	for(i = 0; i < G->cntN; i++){
		if(strcmp(G->tab[i].name, p) == 0)
			return i;
	}
	return -1;
}

/*
	Insert an edge into the graph
**/
void insertEdge(GraphLnk *G, const char *u, const char *v, double val)
{
	int from = getNode(G, u);
	int to1 = getNode(G, v);
	if(from == -1 || to1 == -1){          // something wrong because the node is not existent.
		printf("Warning!The input is wrong.\nThe node is non-existent.");
		exit(1);
	}
	Edge *E;
	E = (Edge*)malloc(sizeof(Edge));
	assert(E != NULL);
	E->to = to1;
	E->w = val;
	E->link = G->tab[from].hed;
	G->tab[from].hed = E;
	G->cntE++;
}

