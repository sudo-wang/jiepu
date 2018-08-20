/*************************************************************************
	> File Name: src/pthread.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年07月28日 星期六 11时19分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<error.h>
#include<pthread.h>    
#include<unistd.h>      // 要用 sleep() 需要包含的头文件

// 由于 pthread.h 不是 Linux 系统提供的库，而是个拓展库
// 所以在使用 gcc 编译的时候要指定这个库才行 即：gcc -lpthread

void* first_out(void* arg)
{
    char c = 'A';
    int i = 0;
    for(i = 0; i < 100; i++){
        fprintf(stderr, "%c ", (c+(i%26)));
        sleep(1);
    }
    return (void*)0;            
//相当于 NULL，在c的标准头文件中，就是这样定义NULL的：#define NULL ((void *) 0)
}

void* second_out(void* arg)
{
    int i = 0;
    for(i = 0; i < 100; i++){
        fprintf(stderr, "%d ", i%10);
        sleep(1);
    }
    pthread_exit((void*)0);         //线程退出，执行到这里线程会立即结束
}

int main(int argc,char **argv)
{
    pthread_t tid1, tid2;           //声明变量
    pthread_create(&tid1, NULL, first_out, NULL);
    pthread_create(&tid2, NULL, second_out, NULL);

    //以下是由进程清理线程的资源：
    //void* val;
    //pthread_join(tid1, &val);     // pthread_join(pthead_t, void**);

    //进程将线程分离出去，交由操作系统清理线程资源
    pthread_detach(tid1);
    pthread_detach(tid2);

    while(1)
        sleep(1);

    return 0;
}
