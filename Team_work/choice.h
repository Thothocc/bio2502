#ifndef __CHOICE_H__
#define __CHOICE_H__
#include "graph.h"

void choice1(GraphLnk *G, double dis[100][100]);
void choice2(GraphLnk *G, int u, double dis[100][100]);
void choice3(GraphLnk *G, int u, int v, double dis[100][100]);
void ShowGraph(GraphLnk *G);

#endif // __CHOICE_H__
