/*************************************************************************
	> File Name: src/list.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年07月21日 星期六 17时03分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"list.h"

List create_list()               //创建链表
{
    List l=(List)malloc(sizeof(List));
    if (l==NULL)
        return l;
    l->next=NULL;
    return l;
}

static void free_node(Node *n)   //递归销毁各个结点
{
    if(n==NULL)
        return;
    if(n->next==NULL)
    {
        free(n);
        n=NULL;
        return;
    }
    free_node(n->next);
    free(n);
    n=NULL;
    return;
}

int free_list(List l)           //销毁链表
{
    if(l==NULL)
        return -1;
    free_node(l->next);
    free(l);
    return 0;
}

