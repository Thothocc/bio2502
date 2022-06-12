#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choice.h"

void choice1(GraphLnk *G, double dis[100][100]){
    int i, j;
    for(i = 0;i < G->cntN;i++){
        for(j = 0;j < G->cntN;j++){
            if(i == j)
                continue;
            if(dis[i][j] != 0x7fffffff){
                printf("%s->",G->tab[i].name);
                printf("%s: %.3f\n",G->tab[j].name,dis[i][j]);
            }

        }
    }
}

void choice2(GraphLnk *G, int u, double dis[100][100]){
    int v;
    for(v = 0; v < G->cntN; v++){
        if(u == v)
            continue;
        if(dis[u][v]!= 0x7fffffff){
            printf("%s->",G->tab[u].name);
            printf("%s: %.3f\n",G->tab[v].name,dis[u][v]);
        }

    }
}

void choice3(GraphLnk *G, int u, int v, double dis[100][100]) {
    if(u == v){
        printf("Warning! The two inputs are the same protein.");
        return;
    }
    if (dis[u][v] != 0x7fffffff) {
        printf("%s->", G->tab[u].name);
        printf("%s: %.3f\n", G->tab[v].name, dis[u][v]);
    }

}

void ShowGraph(GraphLnk *G){
    Edge *p;
    int i;
    for(i = 0;i < G->cntN;i++){
        printf("%d %s:>",i, G->tab[i].name);
        p = G->tab[i].hed;
        while(p != NULL){
            printf("%d-->",p->to);
            p = p->link;
        }
        printf("Null.\n");
    }
    printf("\n");
}
