/*************************************************************************
	> File Name: src/open.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年08月11日 星期六 20时51分20秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>   // strlen strcpy strcat strcmp

int strLength(char *s)    // 自定义函数实现字符串多长的统计，相当于 strlen
{
    int l = 0;
    while(*s++)
        l++;
    return l;
}

int main()
{
    const char path[100] = "log";   // 文件名
    int f = open(path, O_WRONLY | O_APPEND | O_CREAT, 0664);
    if(f == 0)
    {
        printf("open Error!\n");
        return -1;
    }
    printf("file open success! file id is: %d\n", f);
    char writebuf[100] = "Hello World!\n";
    int l = write(f,writebuf,strlen(writebuf));  // 返回实际写入的字节数
    printf("l = %d\n",l);     
    close(f);
    f = open(path, O_RDONLY);
    char readbuf[100];
    int rl = read(f, readbuf, 100);   // 从 f 中读取数据输出到 readbuf 中
    printf("rl = %d\n", rl);          // 返回值为实际读取的字节数
    write(1, readbuf, rl);     // 1 代表输出到屏幕，表示从 readbuf 中读取 rl 个长度的字节 ，输出到屏幕上
    write(1, "ok!\n", 4);      // 在屏幕上输出 ok！，一共 4 个字节
    close(f);
    return 0;

}
