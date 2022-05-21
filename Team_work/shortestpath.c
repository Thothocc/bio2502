#include <stdio.h>
#include <stdlib.h>
#include "shortestpath.h"

void dijkstra(GraphLnk *G, int u, double dis[][])
{
	int vis[MAXN] = {0};
	int i, j;
	for(i = 0; i < MAXN; i++){
		dis[u][i] = 0x7fffffff;
	}
	dis[u][u] = 0; 
	int cur = u;
	while(!vis[cur]){
		vis[cur] = 1;
		double minn = 0x7fffffff;
		Edge *p;
		for(p = G.tab[cur].hed; p != NULL; p = p->link){
			int v = p->to;
			if(!vis[v] && dis[u][v] > dis[u][cur] + p->w){
				dis[u][v] = dis[u][cur] + p->w;
			}
		}
		for(i = 0; i < G->cntN; i++){
			if(dis[u][i] < minn && !vis[i]){
				minn = dis[u][i];
				cur = i;
			}
		}
	}
}
