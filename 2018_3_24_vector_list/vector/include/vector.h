/*************************************************************************
	> File Name: include/vector.h
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年07月20日 星期五 11时14分32秒
 ************************************************************************/

#ifndef _VECTOR_H
#define _VECTOR_H

#include<stdio.h>            
#define VECTOR_INIT_SIZE 100  //初始容量
#define VECTOR_CRMENT 10      //增量


typedef struct vector{
    int *data;
    int len;
    int size;
}Vector;         // ";" 号不要忘了

Vector *create_vector();
int free_vector(Vector *);
int push_back(Vector *,int d);   // insert data back
void disp_vector(Vector *);      // 打印

#endif




