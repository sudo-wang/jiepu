/*************************************************************************
	> File Name: src/timer_test.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年07月27日 星期五 16时19分24秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<signal.h>
#include<sys/time.h>
#include<time.h>
#include<unistd.h>     //包含 sleep() 函数 

typedef struct itimerval TIMER;

TIMER t0 = {{0,800000},{0,800000}};

static int _index = 0;
static char* str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void myhandler(int num)   //这里传的参数代表信号量的标号，没有什么特殊意义
{                         //不写 num 写成其他变量名字也行，并不需要声明
    //printf("%c", str[_index++]);
    fprintf(stderr,"%c ",str[_index++]);
}

int main(int argc, char** argv)
{
    if(signal(SIGALRM, myhandler) == SIG_ERR){   //绑定操作
        printf("signal errror!\n");              //绑定失败
        return -1;
    }

    setitimer(ITIMER_REAL, &t0, NULL);

    printf("info:%d\n", __LINE__);               //调试代码用的
    int i = 0;
    for(i = 0; i < 100; i++){
        //printf("%d", i % 10);
        fprintf(stderr, "%d ", i % 10);          //此处注释看最后    
        sleep(1);
    }
    return 0;
}

//使用 printf 函数的话不会有输出，因为缓冲区没有满
// printf 函数缓存区满的三个条件：1、换行 2、缓冲区写满 3、程序结束了
//这里并不满足上述任何条件，所以没有执行缓冲区自动清空机制
//数据在缓冲区，但是没有输出。
//所以这里用 fprintf ，可以向指定位置输出数据
//这里指定在标准错误中输出，因为这里输出的话无缓冲，有数据就会输出
//而标准输出是有缓冲的，必须清空缓冲才可以输出数据
