#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

void extract_data(GraphLnk *G)
{
    char name1[10]={0};
    char name2[10]={0};
    double w;
    char buffer[500]={0};
    FILE *fp;
    char path[100];
    printf("Please input the direction of your STRING file:");
    scanf("%s", path);
    fp = fopen(path,"r");
    if (NULL == fp)
	{
		printf("Warning! Read file fail!\n");
		return;
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

        insertNode(G, p);
        col++;
        for(;(p=strtok(NULL,"\t"));col++){

            if(col==2){
                strcpy(name2, p);
                insertNode(G, p);
            }
            if(col==13){
                w=1/atof(p);
            }
        }
        col=1;
        row++;
        insertEdge(G, name2, name1, w);
		memset(buffer, 0, sizeof(buffer));
        memset(name1, 0, sizeof(name1));
        memset(name2, 0, sizeof(name2));
	}
}
