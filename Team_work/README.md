# 蛋白质相互作用网络中所有蛋白对的最短路径 All-pairs shortest path in a protein-protein interaction network

**组名：** 第一小组 (Group 1)

**组员：** 逄崇宸，王宇尘，王超贤，朱翔宇

## 项目成品

项目的各个分支函数（头文件）在本仓库栏中

项目整体的package`PPIN_Group1.tgz`也上传在本项目栏中

test文件夹中为项目编写过程中测试用代码

## 文件介绍

`input.h`为输入部分，在读入指定文件中的内容时会完成图的构建

`graph.h`是数据结构的部分，里面包含了邻接表的构建以及访问等操作

`shortestpath.h`是求解最短路径的部分，里面包含了`dijkstra`算法

`choice.h`是各个功能部分，里面包含了本程序的四个设定好的功能

`PPIN.c`是本程序的主函数部分

## 项目报告

### 一、项目背景和目标 Motivation

随着数据库技术的发展，反应蛋白质、代谢等生命系统组成元件之间相互关系的数据迅速增长，这些数据由于节点众多且节点连接呈现不规则特性被称为复杂生物网络。有关生物的复杂网络存在多种，比如与生物体代谢有关的网络、蛋白质间互相联系的网络等，通过分析此类复杂的网络来挖掘生命体系统的运行机制已经演变为重要课题。

以蛋白质为中心点的存在互相影响关系的物理方面和生物化学反应方面在生物体的运行中扮演极其重要的角色。科学研究证实，基本上一切的生命活动均是依赖蛋白质间的互相影响有条不紊的精准进行的，在生命运行过程中所有的蛋白质都极少独自表现出特定的作用。

为了进一步探究蛋白质在分子层面是怎样相互作用并实现生命体所需功能的，实验中要在当前数据库能够构造且极其庞大的网络中找到科研问题中小部分蛋白质间的“桥接蛋白质”。因此蛋白质网络最短路径计算问题在生物学和医学研究中具有重要意义。

我们小组想要初步解决蛋白质网络最短路径计算问题，计算一个蛋白质节点到另一个蛋白质节点的最短路径，要解决以下几个问题：

1. 数据收集和预处理。这一步，主要牵涉三个问题：如何选择合适的原始数据来源，如何从特定格式的文件中获取我们想要的数据，以及对获取的数据进行怎样的数学处理以便于之后的计算。

2. 算法实现。即如何在已有的计算最短路径的算法中进行选取，Floyd-Warshall Algorithm，Dijkstra algorithm， Bellman-Ford algorithm，并针对蛋白质问题进行实际应用。

3. 算法完善。在实际应用中由于数据的一定特性，会出现以下两个问题：无法判定哪个蛋白质存在自身到自身的相互作用；程序容易会陷入死循环，只有对Dijkstra进行改进后，才能够比较好的实现所需功能。



### 二、解决方案 Solution

#### 算法实现

在以上问题中，我们选择了STRING数据库作为我们的数据提供数据库，在此基础上，我们提出解决方案：使用求解最短路径算法dijkstra得出结果。

接下来我们通过伪代码介绍本项目中的核心算法：dijkstra（迪杰斯特拉）算法。

```c
/*
	G为图，u为源点，dis数组为距离数组,dis[u][v]描述为从u点到v点的最短距离。
**/
void dijkstra(GraphLnk *G, int u, double dis[100][100]) 
{
   	定义一个访问数组。如果该点被访问过，vis=1；未访问，vis=0。

	for(遍历整个dis数组用于初始化){
		初始化dis数组为极大值。
	}
	源点到源点的距离设置为0。
	while(仍存在与当前源节点连通且未被访问的节点时){
		将当前点设置为已访问。
		Edge *p;
		for(遍历与当前点相连的所有边){
			int v = p->to;
            v设置为边指向的点。
			if(对于点v，它没有被访问过且源点通过当前点到达点v的距离小于之前dis数组中的距离){
				更新dis的值。
			}
		}
		for(遍历图中所有的点){
            查找已经被访问过的点集合与未被访问过的点集合之间最短路径，并将与之相连的点设置为下一个当前点。
		}
	}
}
```

#### 图的实现

上文中提到了图的遍历，对于存储图中信息，我们选择使用邻接表实现。

以下伪代码将介绍邻接表的实现。

```c
/*
	一个邻接表由三个结构体组成
**/
typedef struct Edge
{
	存储边的信息。
    指向下一条边。
}Edge; 

typedef struct Node
{
	存储点的信息。
    头指针指向第一条边。
}Node;

typedef struct GraphLnk
{
	存储图的信息。
}GraphLnk;
/*
	这三者之间通过指针相互联系
**/

/*
	构建邻接表需要初始化，插入点节点，插入边节点等过程。
**/
void initGraph(GraphLnk *G)
{
	初始化图中各项信息，申请指针空间。
}
void insertNode(GraphLnk *G, const char *p)
{
	插入未被插入的点节点。
}
int getNode(GraphLnk *G, const char *p)
{
	查找目标点节点的编号（ID）
}
void insertEdge(GraphLnk *G, const char *u, const char *v, double val)
{
	定义一个边节点指针，
	将边节点插入进去。
}
```

具体的算法实现详见https://github.com/Thothocc/bio2502 (github.com)

#### 具体功能

我们为本项目的成品设置了四项功能，全功能均可在manual中查询，在此做简要介绍。

1. 输出给定蛋白质互作网络中全部蛋白对之间的“最短路径”（如无联系则不输出）
2. 输出特定蛋白与网络中其他蛋白间的“最短路径”（如无联系则不输出）
3. 输出特定两个蛋白间的“最短路径”（如无联系则不输出）
4. 输出网络中全部蛋白列表（顺带输出其中的邻接表结构）



### 三、实验 Experiment

```
我们同时使用了 simulated data 和 real-world data 来进行测试。
```

#### 1. Simulated data

**模拟图网络：**

```c
人为设置5个点的简单图网络，并赋以权重：
```

| node1 | node2 | node1_string_id      | node2_string_id      | neighborhood_on_chromosome | gene_fusion | phylogenetic_cooccurrence | homology | coexpression | experimentally_determined_interaction | database_annotated | automated_textmining | 1/weight |
| ----- | ----- | -------------------- | -------------------- | -------------------------- | ----------- | ------------------------- | -------- | ------------ | ------------------------------------- | ------------------ | -------------------- | -------- |
| A     | B     | 9606.ENSP00000451828 | 9606.ENSP00000269305 | 0                          | 0           | 0                         | 0        | 0.053        | 0.201                                 | 0.9                | 0.877                | 1        |
| A     | D     | 9606.ENSP00000451828 | 9606.ENSP00000278616 | 0                          | 0           | 0                         | 0        | 0            | 0.056                                 | 0                  | 0.741                | 2        |
| B     | C     | 9606.ENSP00000451828 | 9606.ENSP00000311032 | 0                          | 0           | 0                         | 0        | 0            | 0.475                                 | 0                  | 0.882                | 0.5      |
| B     | E     | 9606.ENSP00000451828 | 9606.ENSP00000313420 | 0                          | 0           | 0                         | 0        | 0.062        | 0.701                                 | 0.9                | 0.953                | 3        |
| C     | D     | 9606.ENSP00000451828 | 9606.ENSP00000352257 | 0                          | 0           | 0                         | 0        | 0            | 0                                     | 0                  | 0.484                | 1        |
| D     | E     | 9606.ENSP00000451828 | 9606.ENSP00000355759 | 0                          | 0           | 0                         | 0        | 0.062        | 0                                     | 0                  | 0.659                | 0.5      |



#### 2. Real-world data

- **Source**: the STRING database

  
- **Standard Data format**:

  | #node1 | node2 | node1_string_id      | node2_string_id      | neighborhood_on_chromosome | gene_fusion | phylogenetic_cooccurrence | homology | coexpression | experimentally_determined_interaction | database_annotated | automated_textmining | combined_score | weight      |
  | ------ | ----- | -------------------- | -------------------- | -------------------------- | ----------- | ------------------------- | -------- | ------------ | ------------------------------------- | ------------------ | -------------------- | -------------- | ----------- |
  | AKT1   | TP53  | 9606.ENSP00000451828 | 9606.ENSP00000269305 | 0                          | 0           | 0                         | 0        | 0.053        | 0.201                                 | 0.9                | 0.877                | 0.989          | 1.011122346 |

  

- **Weight**: 

  ```
  用combined_score的倒数作为权重。
  ```

  

### 四、结果 Conclusion

- ```c
  /*simulation*/
  1
  Here are the results:
  A->B: 1.000
  A->D: 0.500
  A->C: 3.000
  A->E: 1.333
  B->D: 3.000
  B->C: 2.000
  B->E: 0.333
  D->E: 2.000
  C->D: 1.000
  C->E: 3.000
  
  2
  Input the interested protein name:
  A
  A->B: 1.000
  A->D: 0.500
  A->C: 3.000
  A->E: 1.333
  
  3
  Please input two proteins:
  A D
  A->D: 0.500
  
  4
  0 A:>2-->1-->Null.
  1 B:>4-->3-->Null.
  2 D:>4-->Null.
  3 C:>2-->Null.
  4 E:>Null.
  
  5
  Exit!
  ```

- ```c
  /*real-world data*/
  
  1
  Here are the results:
  AKT1->TP53: 1.011
  AKT1->ATM: 1.342
  AKT1->CASP3: 1.070
  AKT1->PRKDC: 1.002
  AKT1->XRCC6: 2.066
  AKT1->PARP1: 1.502
  AKT1->CASP7: 1.395
  AKT1->XIAP: 1.047
  AKT1->CHEK1: 1.828
  AKT1->APLF: 2.023
  AKT1->XRCC1: 2.472
  AKT1->POLB: 3.075
  AKT1->WRN: 2.365
  AKT1->EXO1: 2.368
  AKT1->PARG: 3.187
  AKT1->NHEJ1: 2.376
  AKT1->PNKP: 2.813
  AKT1->LIG3: 2.771
  AKT1->DCLRE1C: 2.386
  AKT1->APTX: 2.046
  AKT1->LIG4: 2.349
  AKT1->XRCC4: 2.364
  AKT1->XRCC5: 2.345
  AKT1->MSH6: 2.350
  AKT1->FEN1: 2.536
  AKT1->RAD52: 2.377
  AKT1->TIPIN: 2.461
  AKT1->MCM2: 2.602
  AKT1->TIMELESS: 2.399
  TP53->AKT1: 1.011
  TP53->ATM: 1.001
  TP53->CASP3: 1.081
  TP53->PRKDC: 2.013
  TP53->XRCC6: 2.003
  TP53->PARP1: 2.033
  TP53->CASP7: 1.468
  TP53->XIAP: 2.058
  TP53->CHEK1: 2.003
  TP53->APLF: 2.791
  TP53->XRCC1: 2.131
  TP53->POLB: 2.734
  TP53->WRN: 2.023
  TP53->EXO1: 2.027
  TP53->PARG: 2.846
  TP53->NHEJ1: 2.035
  TP53->PNKP: 2.472
  TP53->LIG3: 2.430
  TP53->DCLRE1C: 2.045
  TP53->APTX: 1.704
  TP53->LIG4: 2.008
  TP53->XRCC4: 2.022
  TP53->XRCC5: 2.004
  TP53->MSH6: 2.009
  TP53->FEN1: 2.194
  TP53->RAD52: 2.036
  TP53->TIPIN: 2.120
  TP53->MCM2: 2.260
  TP53->TIMELESS: 2.058
  ATM->AKT1: 1.342
  ATM->TP53: 1.001
  ATM->CASP3: 1.466
  ATM->PRKDC: 1.018
  ATM->XRCC6: 1.002
  ATM->PARP1: 1.032
  ATM->CASP7: 2.041
  ATM->XIAP: 2.004
  ATM->CHEK1: 1.002
  ATM->APLF: 2.003
  ATM->XRCC1: 1.130
  ATM->POLB: 1.733
  ATM->WRN: 1.022
  ATM->EXO1: 1.026
  ATM->PARG: 1.845
  ATM->NHEJ1: 1.034
  ATM->PNKP: 1.471
  ATM->LIG3: 1.429
  ATM->DCLRE1C: 1.044
  ATM->APTX: 1.546
  ATM->LIG4: 1.007
  ATM->XRCC4: 1.021
  ATM->XRCC5: 1.003
  ATM->MSH6: 1.008
  ATM->FEN1: 1.193
  ATM->RAD52: 1.035
  ATM->TIPIN: 1.119
  ATM->MCM2: 1.259
  ATM->TIMELESS: 1.057
  CASP3->AKT1: 1.070
  CASP3->TP53: 1.081
  CASP3->ATM: 1.466
  CASP3->PRKDC: 1.029
  CASP3->XRCC6: 1.992
  CASP3->PARP1: 1.002
  CASP3->CASP7: 1.076
  CASP3->XIAP: 1.001
  CASP3->CHEK1: 1.497
  CASP3->APLF: 2.050
  CASP3->XRCC1: 2.596
  CASP3->POLB: 3.199
  CASP3->WRN: 2.489
  CASP3->EXO1: 2.492
  CASP3->PARG: 2.174
  CASP3->NHEJ1: 2.500
  CASP3->PNKP: 2.937
  CASP3->LIG3: 2.895
  CASP3->DCLRE1C: 2.510
  CASP3->APTX: 2.073
  CASP3->LIG4: 2.473
  CASP3->XRCC4: 2.488
  CASP3->XRCC5: 2.309
  CASP3->MSH6: 2.474
  CASP3->FEN1: 2.660
  CASP3->RAD52: 2.501
  CASP3->TIPIN: 2.502
  CASP3->MCM2: 2.508
  CASP3->TIMELESS: 2.523
  PRKDC->AKT1: 1.002
  PRKDC->TP53: 2.013
  PRKDC->ATM: 1.018
  PRKDC->CASP3: 1.029
  PRKDC->XRCC6: 2.020
  PRKDC->PARP1: 2.031
  PRKDC->CASP7: 2.105
  PRKDC->XIAP: 2.030
  PRKDC->CHEK1: 2.020
  PRKDC->APLF: 1.021
  PRKDC->XRCC1: 2.040
  PRKDC->POLB: 2.186
  PRKDC->WRN: 2.041
  PRKDC->EXO1: 2.044
  PRKDC->PARG: 2.534
  PRKDC->NHEJ1: 2.052
  PRKDC->PNKP: 2.408
  PRKDC->LIG3: 2.153
  PRKDC->DCLRE1C: 2.062
  PRKDC->APTX: 1.044
  PRKDC->LIG4: 2.025
  PRKDC->XRCC4: 2.022
  PRKDC->XRCC5: 2.021
  PRKDC->MSH6: 2.026
  PRKDC->FEN1: 2.212
  PRKDC->RAD52: 2.054
  PRKDC->TIPIN: 2.137
  PRKDC->MCM2: 2.278
  PRKDC->TIMELESS: 2.075
  XRCC6->AKT1: 2.066
  XRCC6->TP53: 2.003
  XRCC6->ATM: 1.002
  XRCC6->CASP3: 1.992
  XRCC6->PRKDC: 2.020
  XRCC6->PARP1: 2.034
  XRCC6->CASP7: 3.043
  XRCC6->XIAP: 2.993
  XRCC6->CHEK1: 2.004
  XRCC6->APLF: 1.001
  XRCC6->XRCC1: 2.017
  XRCC6->POLB: 2.165
  XRCC6->WRN: 2.024
  XRCC6->EXO1: 2.028
  XRCC6->PARG: 2.514
  XRCC6->NHEJ1: 2.036
  XRCC6->PNKP: 2.388
  XRCC6->LIG3: 2.132
  XRCC6->DCLRE1C: 2.046
  XRCC6->APTX: 1.016
  XRCC6->LIG4: 2.007
  XRCC6->XRCC4: 2.002
  XRCC6->XRCC5: 2.002
  XRCC6->MSH6: 2.010
  XRCC6->FEN1: 2.195
  XRCC6->RAD52: 2.037
  XRCC6->TIPIN: 2.121
  XRCC6->MCM2: 2.261
  XRCC6->TIMELESS: 2.059
  PARP1->AKT1: 1.502
  PARP1->TP53: 2.033
  PARP1->ATM: 1.032
  PARP1->CASP3: 1.002
  PARP1->PRKDC: 2.031
  PARP1->XRCC6: 2.034
  PARP1->CASP7: 1.009
  PARP1->XIAP: 2.003
  PARP1->CHEK1: 2.034
  PARP1->APLF: 1.054
  PARP1->XRCC1: 2.072
  PARP1->POLB: 2.218
  PARP1->WRN: 2.054
  PARP1->EXO1: 2.058
  PARP1->PARG: 2.567
  PARP1->NHEJ1: 2.066
  PARP1->PNKP: 2.441
  PARP1->LIG3: 2.185
  PARP1->DCLRE1C: 2.076
  PARP1->APTX: 1.172
  PARP1->LIG4: 2.039
  PARP1->XRCC4: 2.053
  PARP1->XRCC5: 2.035
  PARP1->MSH6: 2.040
  PARP1->FEN1: 2.225
  PARP1->RAD52: 2.067
  PARP1->TIPIN: 2.151
  PARP1->MCM2: 2.291
  PARP1->TIMELESS: 2.089
  CASP7->AKT1: 1.395
  CASP7->TP53: 1.468
  CASP7->ATM: 2.041
  CASP7->CASP3: 1.076
  CASP7->PRKDC: 2.105
  CASP7->XRCC6: 3.043
  CASP7->PARP1: 1.009
  CASP7->XIAP: 1.001
  CASP7->CHEK1: 2.183
  CASP7->APLF: 2.063
  CASP7->XRCC1: 3.081
  CASP7->POLB: 3.227
  CASP7->WRN: 3.064
  CASP7->EXO1: 3.067
  CASP7->PARG: 3.250
  CASP7->NHEJ1: 3.075
  CASP7->PNKP: 3.450
  CASP7->LIG3: 3.194
  CASP7->DCLRE1C: 3.085
  CASP7->APTX: 2.181
  CASP7->LIG4: 3.048
  CASP7->XRCC4: 3.063
  CASP7->XRCC5: 3.044
  CASP7->MSH6: 3.049
  CASP7->FEN1: 3.234
  CASP7->RAD52: 3.076
  CASP7->TIPIN: 3.160
  CASP7->MCM2: 3.195
  CASP7->TIMELESS: 3.098
  XIAP->AKT1: 1.047
  XIAP->TP53: 2.058
  XIAP->ATM: 2.004
  XIAP->CASP3: 1.001
  XIAP->PRKDC: 2.030
  XIAP->XRCC6: 2.993
  XIAP->PARP1: 2.003
  XIAP->CASP7: 1.001
  XIAP->CHEK1: 2.498
  XIAP->APLF: 3.051
  XIAP->XRCC1: 3.134
  XIAP->POLB: 3.737
  XIAP->WRN: 3.027
  XIAP->EXO1: 3.030
  XIAP->PARG: 3.175
  XIAP->NHEJ1: 3.038
  XIAP->PNKP: 3.475
  XIAP->LIG3: 3.433
  XIAP->DCLRE1C: 3.048
  XIAP->APTX: 3.074
  XIAP->LIG4: 3.011
  XIAP->XRCC4: 3.025
  XIAP->XRCC5: 3.007
  XIAP->MSH6: 3.012
  XIAP->FEN1: 3.197
  XIAP->RAD52: 3.039
  XIAP->TIPIN: 3.123
  XIAP->MCM2: 3.263
  XIAP->TIMELESS: 3.061
  CHEK1->AKT1: 1.828
  CHEK1->TP53: 2.003
  CHEK1->ATM: 1.002
  CHEK1->CASP3: 1.497
  CHEK1->PRKDC: 2.020
  CHEK1->XRCC6: 2.004
  CHEK1->PARP1: 2.034
  CHEK1->CASP7: 2.183
  CHEK1->XIAP: 2.498
  CHEK1->APLF: 2.634
  CHEK1->XRCC1: 1.616
  CHEK1->POLB: 2.237
  CHEK1->WRN: 2.024
  CHEK1->EXO1: 2.028
  CHEK1->PARG: 2.847
  CHEK1->NHEJ1: 2.036
  CHEK1->PNKP: 2.473
  CHEK1->LIG3: 2.431
  CHEK1->DCLRE1C: 2.046
  CHEK1->APTX: 2.548
  CHEK1->LIG4: 2.009
  CHEK1->XRCC4: 2.023
  CHEK1->XRCC5: 2.005
  CHEK1->MSH6: 1.151
  CHEK1->FEN1: 2.195
  CHEK1->RAD52: 2.037
  CHEK1->TIPIN: 1.005
  CHEK1->MCM2: 1.011
  CHEK1->TIMELESS: 2.059
  APLF->AKT1: 2.023
  APLF->TP53: 2.791
  APLF->ATM: 2.003
  APLF->CASP3: 2.050
  APLF->PRKDC: 1.021
  APLF->XRCC6: 1.001
  APLF->PARP1: 1.054
  APLF->CASP7: 2.063
  APLF->XIAP: 3.051
  APLF->CHEK1: 2.634
  APLF->XRCC1: 1.018
  APLF->POLB: 1.164
  APLF->WRN: 1.567
  APLF->EXO1: 2.381
  APLF->PARG: 1.513
  APLF->NHEJ1: 1.399
  APLF->PNKP: 1.387
  APLF->LIG3: 1.131
  APLF->DCLRE1C: 1.088
  APLF->APTX: 1.087
  APLF->LIG4: 1.006
  APLF->XRCC4: 1.001
  APLF->XRCC5: 1.001
  APLF->MSH6: 2.956
  APLF->FEN1: 2.282
  APLF->RAD52: 3.038
  APLF->TIPIN: 3.122
  APLF->MCM2: 3.262
  APLF->TIMELESS: 3.060
  XRCC1->AKT1: 2.472
  XRCC1->TP53: 2.131
  XRCC1->ATM: 1.130
  XRCC1->CASP3: 2.596
  XRCC1->PRKDC: 2.040
  XRCC1->XRCC6: 2.017
  XRCC1->PARP1: 2.072
  XRCC1->CASP7: 3.081
  XRCC1->XIAP: 3.134
  XRCC1->CHEK1: 1.616
  XRCC1->APLF: 1.018
  XRCC1->POLB: 2.182
  XRCC1->WRN: 2.152
  XRCC1->EXO1: 2.156
  XRCC1->PARG: 2.531
  XRCC1->NHEJ1: 2.164
  XRCC1->PNKP: 2.405
  XRCC1->LIG3: 2.130
  XRCC1->DCLRE1C: 2.072
  XRCC1->APTX: 1.001
  XRCC1->LIG4: 2.019
  XRCC1->XRCC4: 2.002
  XRCC1->XRCC5: 2.019
  XRCC1->MSH6: 2.138
  XRCC1->FEN1: 2.196
  XRCC1->RAD52: 2.165
  XRCC1->TIPIN: 2.249
  XRCC1->MCM2: 2.389
  XRCC1->TIMELESS: 2.187
  POLB->AKT1: 3.075
  POLB->TP53: 2.734
  POLB->ATM: 1.733
  POLB->CASP3: 3.199
  POLB->PRKDC: 2.186
  POLB->XRCC6: 2.165
  POLB->PARP1: 2.218
  POLB->CASP7: 3.227
  POLB->XIAP: 3.737
  POLB->CHEK1: 2.237
  POLB->APLF: 1.164
  POLB->XRCC1: 2.182
  POLB->WRN: 2.486
  POLB->EXO1: 2.656
  POLB->PARG: 2.677
  POLB->NHEJ1: 2.563
  POLB->PNKP: 2.551
  POLB->LIG3: 2.295
  POLB->DCLRE1C: 2.252
  POLB->APTX: 1.299
  POLB->LIG4: 2.170
  POLB->XRCC4: 2.165
  POLB->XRCC5: 2.165
  POLB->MSH6: 2.741
  POLB->FEN1: 2.493
  POLB->RAD52: 2.768
  POLB->TIPIN: 2.852
  POLB->MCM2: 2.993
  POLB->TIMELESS: 2.790
  WRN->AKT1: 2.365
  WRN->TP53: 2.023
  WRN->ATM: 1.022
  WRN->CASP3: 2.489
  WRN->PRKDC: 2.041
  WRN->XRCC6: 2.024
  WRN->PARP1: 2.054
  WRN->CASP7: 3.064
  WRN->XIAP: 3.027
  WRN->CHEK1: 2.024
  WRN->APLF: 1.567
  WRN->XRCC1: 2.152
  WRN->POLB: 2.486
  WRN->EXO1: 2.048
  WRN->PARG: 2.868
  WRN->NHEJ1: 2.057
  WRN->PNKP: 2.493
  WRN->LIG3: 2.316
  WRN->DCLRE1C: 2.066
  WRN->APTX: 1.188
  WRN->LIG4: 2.030
  WRN->XRCC4: 2.044
  WRN->XRCC5: 2.026
  WRN->MSH6: 2.031
  WRN->FEN1: 2.216
  WRN->RAD52: 2.058
  WRN->TIPIN: 2.141
  WRN->MCM2: 2.282
  WRN->TIMELESS: 2.080
  EXO1->AKT1: 2.368
  EXO1->TP53: 2.027
  EXO1->ATM: 1.026
  EXO1->CASP3: 2.492
  EXO1->PRKDC: 2.044
  EXO1->XRCC6: 2.028
  EXO1->PARP1: 2.058
  EXO1->CASP7: 3.067
  EXO1->XIAP: 3.030
  EXO1->CHEK1: 2.028
  EXO1->APLF: 2.381
  EXO1->XRCC1: 2.156
  EXO1->POLB: 2.656
  EXO1->WRN: 2.048
  EXO1->PARG: 2.871
  EXO1->NHEJ1: 2.060
  EXO1->PNKP: 2.496
  EXO1->LIG3: 2.454
  EXO1->DCLRE1C: 2.069
  EXO1->APTX: 1.357
  EXO1->LIG4: 2.033
  EXO1->XRCC4: 2.047
  EXO1->XRCC5: 2.029
  EXO1->MSH6: 2.034
  EXO1->FEN1: 2.219
  EXO1->RAD52: 2.061
  EXO1->TIPIN: 2.144
  EXO1->MCM2: 2.285
  EXO1->TIMELESS: 2.083
  PARG->AKT1: 3.187
  PARG->TP53: 2.846
  PARG->ATM: 1.845
  PARG->CASP3: 2.174
  PARG->PRKDC: 2.534
  PARG->XRCC6: 2.514
  PARG->PARP1: 2.567
  PARG->CASP7: 3.250
  PARG->XIAP: 3.175
  PARG->CHEK1: 2.847
  PARG->APLF: 1.513
  PARG->XRCC1: 2.531
  PARG->POLB: 2.677
  PARG->WRN: 2.868
  PARG->EXO1: 2.871
  PARG->NHEJ1: 2.879
  PARG->PNKP: 2.900
  PARG->LIG3: 2.644
  PARG->DCLRE1C: 2.601
  PARG->APTX: 2.326
  PARG->LIG4: 2.519
  PARG->XRCC4: 2.514
  PARG->XRCC5: 2.514
  PARG->MSH6: 2.853
  PARG->FEN1: 3.038
  PARG->RAD52: 2.880
  PARG->TIPIN: 2.964
  PARG->MCM2: 3.104
  PARG->TIMELESS: 2.902
  NHEJ1->AKT1: 2.376
  NHEJ1->TP53: 2.035
  NHEJ1->ATM: 1.034
  NHEJ1->CASP3: 2.500
  NHEJ1->PRKDC: 2.052
  NHEJ1->XRCC6: 2.036
  NHEJ1->PARP1: 2.066
  NHEJ1->CASP7: 3.075
  NHEJ1->XIAP: 3.038
  NHEJ1->CHEK1: 2.036
  NHEJ1->APLF: 1.399
  NHEJ1->XRCC1: 2.164
  NHEJ1->POLB: 2.563
  NHEJ1->WRN: 2.057
  NHEJ1->EXO1: 2.060
  NHEJ1->PARG: 2.879
  NHEJ1->PNKP: 2.505
  NHEJ1->LIG3: 2.463
  NHEJ1->DCLRE1C: 2.078
  NHEJ1->APTX: 1.362
  NHEJ1->LIG4: 2.041
  NHEJ1->XRCC4: 2.056
  NHEJ1->XRCC5: 2.037
  NHEJ1->MSH6: 2.042
  NHEJ1->FEN1: 2.227
  NHEJ1->RAD52: 2.069
  NHEJ1->TIPIN: 2.153
  NHEJ1->MCM2: 2.294
  NHEJ1->TIMELESS: 2.091
  PNKP->AKT1: 2.813
  PNKP->TP53: 2.472
  PNKP->ATM: 1.471
  PNKP->CASP3: 2.937
  PNKP->PRKDC: 2.408
  PNKP->XRCC6: 2.388
  PNKP->PARP1: 2.441
  PNKP->CASP7: 3.450
  PNKP->XIAP: 3.475
  PNKP->CHEK1: 2.473
  PNKP->APLF: 1.387
  PNKP->XRCC1: 2.405
  PNKP->POLB: 2.551
  PNKP->WRN: 2.493
  PNKP->EXO1: 2.496
  PNKP->PARG: 2.900
  PNKP->NHEJ1: 2.505
  PNKP->LIG3: 2.518
  PNKP->DCLRE1C: 2.475
  PNKP->APTX: 2.336
  PNKP->LIG4: 2.393
  PNKP->XRCC4: 2.388
  PNKP->XRCC5: 2.388
  PNKP->MSH6: 2.479
  PNKP->FEN1: 2.664
  PNKP->RAD52: 2.506
  PNKP->TIPIN: 2.589
  PNKP->MCM2: 2.730
  PNKP->TIMELESS: 2.528
  LIG3->AKT1: 2.771
  LIG3->TP53: 2.430
  LIG3->ATM: 1.429
  LIG3->CASP3: 2.895
  LIG3->PRKDC: 2.153
  LIG3->XRCC6: 2.132
  LIG3->PARP1: 2.185
  LIG3->CASP7: 3.194
  LIG3->XIAP: 3.433
  LIG3->CHEK1: 2.431
  LIG3->APLF: 1.131
  LIG3->XRCC1: 2.130
  LIG3->POLB: 2.295
  LIG3->WRN: 2.316
  LIG3->EXO1: 2.454
  LIG3->PARG: 2.644
  LIG3->NHEJ1: 2.463
  LIG3->PNKP: 2.518
  LIG3->DCLRE1C: 2.199
  LIG3->APTX: 1.129
  LIG3->LIG4: 2.137
  LIG3->XRCC4: 2.130
  LIG3->XRCC5: 2.132
  LIG3->MSH6: 2.437
  LIG3->FEN1: 2.323
  LIG3->RAD52: 2.464
  LIG3->TIPIN: 2.547
  LIG3->MCM2: 2.688
  LIG3->TIMELESS: 2.486
  DCLRE1C->AKT1: 2.386
  DCLRE1C->TP53: 2.045
  DCLRE1C->ATM: 1.044
  DCLRE1C->CASP3: 2.510
  DCLRE1C->PRKDC: 2.062
  DCLRE1C->XRCC6: 2.046
  DCLRE1C->PARP1: 2.076
  DCLRE1C->CASP7: 3.085
  DCLRE1C->XIAP: 3.048
  DCLRE1C->CHEK1: 2.046
  DCLRE1C->APLF: 1.088
  DCLRE1C->XRCC1: 2.072
  DCLRE1C->POLB: 2.252
  DCLRE1C->WRN: 2.066
  DCLRE1C->EXO1: 2.069
  DCLRE1C->PARG: 2.601
  DCLRE1C->NHEJ1: 2.078
  DCLRE1C->PNKP: 2.475
  DCLRE1C->LIG3: 2.199
  DCLRE1C->APTX: 1.071
  DCLRE1C->LIG4: 2.051
  DCLRE1C->XRCC4: 2.065
  DCLRE1C->XRCC5: 2.047
  DCLRE1C->MSH6: 2.052
  DCLRE1C->FEN1: 2.237
  DCLRE1C->RAD52: 2.079
  DCLRE1C->TIPIN: 2.162
  DCLRE1C->MCM2: 2.303
  DCLRE1C->TIMELESS: 2.101
  APTX->AKT1: 2.046
  APTX->TP53: 1.704
  APTX->ATM: 1.546
  APTX->CASP3: 2.073
  APTX->PRKDC: 1.044
  APTX->XRCC6: 1.016
  APTX->PARP1: 1.172
  APTX->CASP7: 2.181
  APTX->XIAP: 3.074
  APTX->CHEK1: 2.548
  APTX->APLF: 1.087
  APTX->XRCC1: 1.001
  APTX->POLB: 1.299
  APTX->WRN: 1.188
  APTX->EXO1: 1.357
  APTX->PARG: 2.326
  APTX->NHEJ1: 1.362
  APTX->PNKP: 2.336
  APTX->LIG3: 1.129
  APTX->DCLRE1C: 1.071
  APTX->LIG4: 1.018
  APTX->XRCC4: 1.001
  APTX->XRCC5: 1.027
  APTX->MSH6: 1.869
  APTX->FEN1: 1.195
  APTX->RAD52: 2.222
  APTX->TIPIN: 2.664
  APTX->MCM2: 2.805
  APTX->TIMELESS: 2.603
  LIG4->AKT1: 2.349
  LIG4->TP53: 2.008
  LIG4->ATM: 1.007
  LIG4->CASP3: 2.473
  LIG4->PRKDC: 2.025
  LIG4->XRCC6: 2.007
  LIG4->PARP1: 2.039
  LIG4->CASP7: 3.048
  LIG4->XIAP: 3.011
  LIG4->CHEK1: 2.009
  LIG4->APLF: 1.006
  LIG4->XRCC1: 2.019
  LIG4->POLB: 2.170
  LIG4->WRN: 2.030
  LIG4->EXO1: 2.033
  LIG4->PARG: 2.519
  LIG4->NHEJ1: 2.041
  LIG4->PNKP: 2.393
  LIG4->LIG3: 2.137
  LIG4->DCLRE1C: 2.051
  LIG4->APTX: 1.018
  LIG4->XRCC4: 2.007
  LIG4->XRCC5: 2.007
  LIG4->MSH6: 2.015
  LIG4->FEN1: 2.200
  LIG4->RAD52: 2.042
  LIG4->TIPIN: 2.126
  LIG4->MCM2: 2.266
  LIG4->TIMELESS: 2.064
  XRCC4->AKT1: 2.364
  XRCC4->TP53: 2.022
  XRCC4->ATM: 1.021
  XRCC4->CASP3: 2.488
  XRCC4->PRKDC: 2.022
  XRCC4->XRCC6: 2.002
  XRCC4->PARP1: 2.053
  XRCC4->CASP7: 3.063
  XRCC4->XIAP: 3.025
  XRCC4->CHEK1: 2.023
  XRCC4->APLF: 1.001
  XRCC4->XRCC1: 2.002
  XRCC4->POLB: 2.165
  XRCC4->WRN: 2.044
  XRCC4->EXO1: 2.047
  XRCC4->PARG: 2.514
  XRCC4->NHEJ1: 2.056
  XRCC4->PNKP: 2.388
  XRCC4->LIG3: 2.130
  XRCC4->DCLRE1C: 2.065
  XRCC4->APTX: 1.001
  XRCC4->LIG4: 2.007
  XRCC4->XRCC5: 2.002
  XRCC4->MSH6: 2.030
  XRCC4->FEN1: 2.196
  XRCC4->RAD52: 2.057
  XRCC4->TIPIN: 2.140
  XRCC4->MCM2: 2.281
  XRCC4->TIMELESS: 2.079
  XRCC5->AKT1: 2.345
  XRCC5->TP53: 2.004
  XRCC5->ATM: 1.003
  XRCC5->CASP3: 2.309
  XRCC5->PRKDC: 2.021
  XRCC5->XRCC6: 2.002
  XRCC5->PARP1: 2.035
  XRCC5->CASP7: 3.044
  XRCC5->XIAP: 3.007
  XRCC5->CHEK1: 2.005
  XRCC5->APLF: 1.001
  XRCC5->XRCC1: 2.019
  XRCC5->POLB: 2.165
  XRCC5->WRN: 2.026
  XRCC5->EXO1: 2.029
  XRCC5->PARG: 2.514
  XRCC5->NHEJ1: 2.037
  XRCC5->PNKP: 2.388
  XRCC5->LIG3: 2.132
  XRCC5->DCLRE1C: 2.047
  XRCC5->APTX: 1.027
  XRCC5->LIG4: 2.007
  XRCC5->XRCC4: 2.002
  XRCC5->MSH6: 2.011
  XRCC5->FEN1: 2.196
  XRCC5->RAD52: 2.038
  XRCC5->TIPIN: 2.122
  XRCC5->MCM2: 2.262
  XRCC5->TIMELESS: 2.060
  MSH6->AKT1: 2.350
  MSH6->TP53: 2.009
  MSH6->ATM: 1.008
  MSH6->CASP3: 2.474
  MSH6->PRKDC: 2.026
  MSH6->XRCC6: 2.010
  MSH6->PARP1: 2.040
  MSH6->CASP7: 3.049
  MSH6->XIAP: 3.012
  MSH6->CHEK1: 1.151
  MSH6->APLF: 2.956
  MSH6->XRCC1: 2.138
  MSH6->POLB: 2.741
  MSH6->WRN: 2.031
  MSH6->EXO1: 2.034
  MSH6->PARG: 2.853
  MSH6->NHEJ1: 2.042
  MSH6->PNKP: 2.479
  MSH6->LIG3: 2.437
  MSH6->DCLRE1C: 2.052
  MSH6->APTX: 1.869
  MSH6->LIG4: 2.015
  MSH6->XRCC4: 2.030
  MSH6->XRCC5: 2.011
  MSH6->FEN1: 2.201
  MSH6->RAD52: 2.043
  MSH6->TIPIN: 2.127
  MSH6->MCM2: 2.162
  MSH6->TIMELESS: 2.065
  FEN1->AKT1: 2.536
  FEN1->TP53: 2.194
  FEN1->ATM: 1.193
  FEN1->CASP3: 2.660
  FEN1->PRKDC: 2.212
  FEN1->XRCC6: 2.195
  FEN1->PARP1: 2.225
  FEN1->CASP7: 3.234
  FEN1->XIAP: 3.197
  FEN1->CHEK1: 2.195
  FEN1->APLF: 2.282
  FEN1->XRCC1: 2.196
  FEN1->POLB: 2.493
  FEN1->WRN: 2.216
  FEN1->EXO1: 2.219
  FEN1->PARG: 3.038
  FEN1->NHEJ1: 2.227
  FEN1->PNKP: 2.664
  FEN1->LIG3: 2.323
  FEN1->DCLRE1C: 2.237
  FEN1->APTX: 1.195
  FEN1->LIG4: 2.200
  FEN1->XRCC4: 2.196
  FEN1->XRCC5: 2.196
  FEN1->MSH6: 2.201
  FEN1->RAD52: 2.229
  FEN1->TIPIN: 2.312
  FEN1->MCM2: 2.453
  FEN1->TIMELESS: 2.250
  RAD52->AKT1: 2.377
  RAD52->TP53: 2.036
  RAD52->ATM: 1.035
  RAD52->CASP3: 2.501
  RAD52->PRKDC: 2.054
  RAD52->XRCC6: 2.037
  RAD52->PARP1: 2.067
  RAD52->CASP7: 3.076
  RAD52->XIAP: 3.039
  RAD52->CHEK1: 2.037
  RAD52->APLF: 3.038
  RAD52->XRCC1: 2.165
  RAD52->POLB: 2.768
  RAD52->WRN: 2.058
  RAD52->EXO1: 2.061
  RAD52->PARG: 2.880
  RAD52->NHEJ1: 2.069
  RAD52->PNKP: 2.506
  RAD52->LIG3: 2.464
  RAD52->DCLRE1C: 2.079
  RAD52->APTX: 2.222
  RAD52->LIG4: 2.042
  RAD52->XRCC4: 2.057
  RAD52->XRCC5: 2.038
  RAD52->MSH6: 2.043
  RAD52->FEN1: 2.229
  RAD52->TIPIN: 2.154
  RAD52->MCM2: 2.295
  RAD52->TIMELESS: 2.092
  TIPIN->AKT1: 2.461
  TIPIN->TP53: 2.120
  TIPIN->ATM: 1.119
  TIPIN->CASP3: 2.502
  TIPIN->PRKDC: 2.137
  TIPIN->XRCC6: 2.121
  TIPIN->PARP1: 2.151
  TIPIN->CASP7: 3.160
  TIPIN->XIAP: 3.123
  TIPIN->CHEK1: 1.005
  TIPIN->APLF: 3.122
  TIPIN->XRCC1: 2.249
  TIPIN->POLB: 2.852
  TIPIN->WRN: 2.141
  TIPIN->EXO1: 2.144
  TIPIN->PARG: 2.964
  TIPIN->NHEJ1: 2.153
  TIPIN->PNKP: 2.589
  TIPIN->LIG3: 2.547
  TIPIN->DCLRE1C: 2.162
  TIPIN->APTX: 2.664
  TIPIN->LIG4: 2.126
  TIPIN->XRCC4: 2.140
  TIPIN->XRCC5: 2.122
  TIPIN->MSH6: 2.127
  TIPIN->FEN1: 2.312
  TIPIN->RAD52: 2.154
  TIPIN->MCM2: 2.016
  TIPIN->TIMELESS: 2.176
  MCM2->AKT1: 2.602
  MCM2->TP53: 2.260
  MCM2->ATM: 1.259
  MCM2->CASP3: 2.508
  MCM2->PRKDC: 2.278
  MCM2->XRCC6: 2.261
  MCM2->PARP1: 2.291
  MCM2->CASP7: 3.195
  MCM2->XIAP: 3.263
  MCM2->CHEK1: 1.011
  MCM2->APLF: 3.262
  MCM2->XRCC1: 2.389
  MCM2->POLB: 2.993
  MCM2->WRN: 2.282
  MCM2->EXO1: 2.285
  MCM2->PARG: 3.104
  MCM2->NHEJ1: 2.294
  MCM2->PNKP: 2.730
  MCM2->LIG3: 2.688
  MCM2->DCLRE1C: 2.303
  MCM2->APTX: 2.805
  MCM2->LIG4: 2.266
  MCM2->XRCC4: 2.281
  MCM2->XRCC5: 2.262
  MCM2->MSH6: 2.162
  MCM2->FEN1: 2.453
  MCM2->RAD52: 2.295
  MCM2->TIPIN: 2.016
  MCM2->TIMELESS: 2.317
  TIMELESS->AKT1: 2.399
  TIMELESS->TP53: 2.058
  TIMELESS->ATM: 1.057
  TIMELESS->CASP3: 2.523
  TIMELESS->PRKDC: 2.075
  TIMELESS->XRCC6: 2.059
  TIMELESS->PARP1: 2.089
  TIMELESS->CASP7: 3.098
  TIMELESS->XIAP: 3.061
  TIMELESS->CHEK1: 2.059
  TIMELESS->APLF: 3.060
  TIMELESS->XRCC1: 2.187
  TIMELESS->POLB: 2.790
  TIMELESS->WRN: 2.080
  TIMELESS->EXO1: 2.083
  TIMELESS->PARG: 2.902
  TIMELESS->NHEJ1: 2.091
  TIMELESS->PNKP: 2.528
  TIMELESS->LIG3: 2.486
  TIMELESS->DCLRE1C: 2.101
  TIMELESS->APTX: 2.603
  TIMELESS->LIG4: 2.064
  TIMELESS->XRCC4: 2.079
  TIMELESS->XRCC5: 2.060
  TIMELESS->MSH6: 2.065
  TIMELESS->FEN1: 2.250
  TIMELESS->RAD52: 2.092
  TIMELESS->TIPIN: 2.176
  TIMELESS->MCM2: 2.317
      
  2
  input the interested protein name: 
  ATM
  ATM->AKT1: 1.342
  ATM->TP53: 1.001
  ATM->ATM: 0.000
  ATM->CASP3: 1.466
  ATM->PRKDC: 1.018
  ATM->XRCC6: 1.002
  ATM->PARP1: 1.032
  ATM->CASP7: 2.041
  ATM->XIAP: 2.004
  ATM->CHEK1: 1.002
  ATM->APLF: 2.003
  ATM->XRCC1: 1.130
  ATM->POLB: 1.733
  ATM->WRN: 1.022
  ATM->EXO1: 1.026
  ATM->PARG: 1.845
  ATM->NHEJ1: 1.034
  ATM->PNKP: 1.471
  ATM->LIG3: 1.429
  ATM->DCLRE1C: 1.044
  ATM->APTX: 1.546
  ATM->LIG4: 1.007
  ATM->XRCC4: 1.021
  ATM->XRCC5: 1.003
  ATM->MSH6: 1.008
  ATM->FEN1: 1.193
  ATM->RAD52: 1.035
  ATM->TIPIN: 1.119
  ATM->MCM2: 1.259
  ATM->TIMELESS: 1.057
      
  3
  Please input two proteins:
  ATM AKT1
  ATM->AKT1: 1.342
      
  4
  0 AKT1:>7-->3-->2-->9-->8-->7-->6-->5-->4-->3-->2-->1-->Null.
  1 TP53:>7-->3-->2-->20-->0-->Null.
  2 ATM:>7-->3-->9-->5-->23-->21-->4-->22-->13-->14-->6-->16-->26-->19-->29-->25-->0-->18-->3-->17-->20-->15-->8-->7-->10-->1-->12-->28-->11-->27-->24-->20-->10-->0-->Null.
  3 CASP3:>7-->8-->6-->4-->0-->7-->9-->5-->15-->23-->2-->1-->2-->0-->Null.
  4 PRKDC:>3-->2-->20-->10-->0-->Null.
  5 XRCC6:>3-->2-->20-->10-->0-->Null.
  6 PARP1:>7-->3-->2-->20-->10-->0-->Null.
  7 CASP7:>8-->0-->9-->6-->3-->2-->1-->3-->2-->0-->Null.
  8 XIAP:>7-->3-->2-->0-->Null.
  9 CHEK1:>12-->28-->11-->27-->24-->7-->3-->2-->0-->Null.
  10 APLF:>2-->20-->5-->23-->22-->21-->4-->6-->20-->19-->18-->17-->16-->15-->14-->13-->2-->12-->11-->Null.
  11 XRCC1:>9-->2-->20-->10-->Null.
  12 POLB:>9-->2-->20-->10-->Null.
  13 WRN:>2-->20-->10-->Null.
  14 EXO1:>2-->20-->10-->Null.
  15 PARG:>3-->2-->20-->10-->Null.
  16 NHEJ1:>2-->20-->10-->Null.
  17 PNKP:>2-->20-->10-->Null.
  18 LIG3:>2-->20-->10-->Null.
  19 DCLRE1C:>2-->20-->10-->Null.
  20 APTX:>2-->22-->21-->15-->23-->18-->19-->6-->14-->5-->26-->16-->17-->4-->10-->25-->13-->2-->1-->12-->11-->24-->10-->Null.
  21 LIG4:>2-->20-->10-->Null.
  22 XRCC4:>2-->20-->10-->Null.
  23 XRCC5:>3-->2-->20-->10-->Null.
  24 MSH6:>9-->2-->20-->Null.
  25 FEN1:>2-->20-->Null.
  26 RAD52:>2-->20-->Null.
  27 TIPIN:>9-->2-->Null.
  28 MCM2:>9-->2-->Null.
  29 TIMELESS:>2-->Null.
      
  5
  Exit!
  ```



### 五、改进意见 Perspective

#### 算法本身的改进

在项目编写时，我们将dis数组大小设置为100*100，这样限制了能够读入的数据点的个数。在理论计算与实际测试当中，我们发现当数据数量过大时，该程序的运行效率不理想，这是由于在查找已经被访问过的点集合与未被访问过的点集合之间最短路径的过程中需要遍历图中的所有点，这样来看，该算法求解单源最短路径的时间复杂度为O(n<sup>2</sup>)，本项目需要求解图中各点间的最短路径，因此还需要在最外层遍历全部点，因此本算法的是时间复杂度为O(n<sup>3</sup>)。

在随后的资料查询以及思考中，我们发现，可以通过一种数据结构，例如：优先队列、堆，将上文中特别提到的查找过程的时间复杂度降低为O(log<sub>2</sub>n)，即整体的时间复杂度降低为O(n<sup>2</sup>log<sub>2</sub>n)，可以有效改善程序的运行效率。

#### 返回值等细节的改进

在本程序中，部分错误输入输出的返回提示不够明晰，部分可能的错误仍未被考虑到。

同时，仍存在潜在的未发现的错误使用方式导致的错误情况，还需要进一步思考及测试，以期进一步完善本项目。

在输出方面，功能1的输出可能过长，不易分析，需要考虑更加简洁明了的输出方式。
