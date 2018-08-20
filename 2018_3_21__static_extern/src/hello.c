/*************************************************************************
	> File Name: src/hello.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年07月18日 星期三 18时22分37秒
 ************************************************************************/

#include<stdio.h>
#include"test.h"

// this is a test programming
#define _int int
typedef int __int;

extern int counter; //只是声明，不是定义,在test.c中定义了，这里 extern 必须加上
extern int mc;      //只是声明，不是定义

int main(int argc, char ** argv )
{
    //_int a=10;
    //__int b=100;
    //printf("Hello Kitty!.a=%d,b=%d\n",a,b);
    display(counter);
    display(mc);      // 执行失败，因为 mc 在 test.c 中被声明为 static ，错误提示为：mc 未定义
    return 0;
}
