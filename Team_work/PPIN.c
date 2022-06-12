#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "graph.h"
#include "shortestpath.h"
#include "choice.h"

int main(){
    GraphLnk G;
    initGraph(&G);
    extract_data(&G);
    int i;
	double dis[100][100];
	for(i = 0; i < G.cntN; i++)
    {
        dijkstra(&G, i, dis);
    }

//Data input and processing via file
    int flag = 0;
    while(flag != 5){
        printf("choices:\n1:All protein-protein shortest distances\n2:Input one protein and output all shortest distances about it\n3:Choose two proteins and output the shortest distance\n4:Show protein list\n5:Exit\n");
        scanf("%d", &flag);
        if(flag == 1){
            printf("Here are the results:\n");
            choice1(&G,dis);
        }
        if(flag == 2){
            printf("Input the interested protein name:\n");
            char pro[10]={0};
            scanf("%s",pro);  //the original node
            int u = getNode(&G, pro);
            choice2(&G,u,dis);
        }
        if(flag == 3){
            char pro1[10] = {0}, pro2[10] = {0};
            printf("Please input two proteins:\n");
            scanf("%s", pro1);
            scanf("%s", pro2);
            int u = getNode(&G, pro1), v = getNode(&G, pro2);
            choice3(&G,u,v,dis);
        }
        if(flag == 4){
            ShowGraph(&G);
        }
        if(flag > 5 || flag < 1){
            printf("Warning! Undefined operation.");
        }
    }
//Select different functions and work
    printf("Exit!\n");
    return 0;
}
