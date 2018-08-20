/*************************************************************************
	> File Name: point.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年08月20日 星期一 16时42分29秒
 ************************************************************************/


#include<iostream>
using namespace std;

void test(int (*a)[2], int, int);

int main(int argc, char **argv)
{
    int array[] = {10, 20, 30, 40};
    int array2[][2] = {{10, 20}, {30, 40}, {50, 60}};

    int *pa = array;
    printf("*pa = %d, *(pa+1) = %d\n", *pa, *(pa+1));

    int **ppa = (int **)array2;
    printf("ppa:%p, *ppa = %d, *(ppa+1) = %d\n", ppa, *ppa, *(ppa+1));
    printf("ppa:%p, *array2 = %d, *(array2+1) = %d\n", ppa, *array2, *(array2+1));       //  不能这样用,是错误的
    printf("ppa:%p, *(*(array2+0)+0) = %d,  *(*(array2+1)+0) = %d\n", ppa,    \
           *(*(array2+0)+0),  *(*(array2+1)+0) );

    test(array2, 2, 1);
    return 0;
}

void test(int (*a)[2],int m,int n)
{
    cout<<*(*(a+m)+n)<<endl;
}


