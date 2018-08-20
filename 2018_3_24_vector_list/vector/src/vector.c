/*************************************************************************
	> File Name: src/vector.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年07月20日 星期五 11时21分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"vector.h"

int wang=10;

Vector *create_vector()
{
    // 为 Vector 分配空间
    Vector *v=(Vector*)malloc(sizeof(Vector));
    if(v==NULL)
        return NULL;

    // 为 data分配空间
    v->data=(int *)malloc(VECTOR_INIT_SIZE*sizeof(int));
    if(v->data==NULL)
        return NULL;
    v->len=0;
    v->size=VECTOR_INIT_SIZE;
    return v;
}

int free_vector(Vector *v)
{
    //先销毁v中的data,再销毁v，注意顺序
    free(v->data);
    v->data=NULL;
    v->len=0;
    v->size=0;
    free(v);
    return 0;
}
int push_back(Vector *v,int d)
{
    if(v == NULL)
        return -1;
    if(v->len == v->size)  //容量是否用完
    { 
        //申请的空间全部被用完
        v->data=(int *)realloc(v->data,(v->size+VECTOR_CRMENT)*sizeof(int));
        if(v->data==NULL)
            return -1;
        v->size+=VECTOR_CRMENT;
    }
    v->data[v->len]=d;
    v->len++;
}

void disp_vector(Vector *v)
{
    if(v==NULL)
        printf("vector is failed!\n");
    printf("vector len=%d,size=%d\n",v->len,v->size);
    for(int i =0;i<v->len;i++)
        printf("v->data[%d]=%d \n",i,v->data[i]);
}









