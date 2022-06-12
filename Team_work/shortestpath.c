#include <stdio.h>
#include <stdlib.h>
#include "shortestpath.h"
#define MAXN 100

/*
	the part of algorithm
**/
void dijkstra(GraphLnk *G, int u, double dis[100][100])
{
	int vis[MAXN] = {0};
	int i;
	// initialize the distance array
	for(i = 0; i < MAXN; i++){
		dis[u][i] = 0x7fffffff;
	}
	// this is the program of dijkstra
	dis[u][u] = 0;
	int cur = u;
	while(!vis[cur]){
		vis[cur] = 1;
		double minn = 0x7fffffff;
		Edge *p;
		// update the distance between the source point and other points
		for(p = G->tab[cur].hed; p != NULL; p = p->link){
			int v = p->to;
			if(!vis[v] && dis[u][v] > dis[u][cur] + p->w){
				dis[u][v] = dis[u][cur] + p->w;
			}
		}
		// search the minimum value between visited points and unvisited points
		for(i = 0; i < G->cntN; i++){
			if(dis[u][i] < minn && !vis[i]){
				minn = dis[u][i];
				cur = i;
			}
		}
	}
}
