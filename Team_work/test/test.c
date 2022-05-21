#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "shortestpath.h"

int main()
{
	GraphLnk G;
	initGraph(&G);
	int n, m;
	char s[2];
	scanf("%d%d%s", &n, &m, s);
	double dis[100][100];
	int i;
	for(i = 0; i < m; i++){
        int z;
        char x[2], y[2];
        scanf("%s%s%d", x, y, &z);
        insertNode(&G, x);
        insertNode(&G, y);
        insertEdge(&G, x, y, z);
	}
    int u = getNode(&G, s);
    if(u != -1)
        dijkstra(&G, u, dis);
    for(i = 0; i < G.cntN; i++)
    {
        printf("%.3lf ", dis[u][i]);
    }
	return 0;
}
