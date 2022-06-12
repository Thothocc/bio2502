#include <stdio.h>
#include <stdlib.h>
#include "input.h"

void GetInput(int n, char *node1, char *node2, double *distance)
{
    char path[100] = {0};
    char temp[300] = {0};
    char s[10] = {0};
    int k,j,i = 1,tab = 0,flag = 0;
    FILE *fp;
    printf("Please input the path of the string file:\n");
    scanf("%s", path);
    fp = fopen(path, "r");
    if(fp == NULL){
        printf("The file %s can not be opened\n", path);
    }

    fgets(temp, 300, fp);
    while(i < n){
        fgets(temp, 300, fp);
        i++;
    }

    j = 0;
    while(temp[j] != '\t'){
        node1[j] = temp[j];
        j++;
    }
    i = 0;
    while(1){
        if(temp[i] == '\t'){
            for(k = i+1, j = 0; temp[k] != '\t'; k++){
                node2[j] = temp[k];
                j++;
            }
            break;
        }
        i++;
    }
    i = 0;
    while(1){
        if(temp[i] == '\t'){
            tab++;
            if(tab == 12){
                for(k = i+1, j = 0; temp[k] != '\n'; k++){
                    s[j] = temp[k];
                    j++;
                }
                break;
            }
        }
        i++;
    }
    *distance = 1/(atof(s));
}