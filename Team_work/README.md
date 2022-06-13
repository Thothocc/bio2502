# 蛋白质相互作用网络中所有蛋白对的最短路径 All-pairs shortest path in a protein-protein interaction networ
[TOC]

## 项目成品

项目的各个分支函数（头文件）在本仓库栏中

项目整体的package也上传在本项目栏中

test文件夹中为项目编写过程中测试用代码

## 文件介绍

`input.h`为输入部分，在读入指定文件中的内容时会完成图的构建

`graph.h`是数据结构的部分，里面包含了邻接表的构建以及访问等操作

`shortestpath.h`是求解最短路径的部分，里面包含了`dijkstra`算法

`choice.h`是各个功能部分，里面包含了本程序的四个设定好的功能

`PPIN.c`是本程序的主函数部分
