/*************************************************************************
	> File Name: inc/list.h
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年07月21日 星期六 16时53分47秒
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H

//单链表结点结构体
typedef struct node{
    int data;
    struct node *next;
}Node,*List;

List creat_list();
int free_list();

#endif