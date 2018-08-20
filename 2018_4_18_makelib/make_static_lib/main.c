/*************************************************************************
	> File Name: static_lib.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年08月16日 星期四 10时33分36秒
 ************************************************************************/

#include<stdio.h>
#include"myMath.h"

int main()
{
    int a = 3;
    int b = 5;
    int c = add(a, b);
    printf("add(a,b) = %d\n",c);
    return 0;
}
