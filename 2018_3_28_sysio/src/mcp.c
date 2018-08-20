/*************************************************************************
	> File Name: src/mcp.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年07月24日 星期二 13时34分57秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char **argv)  // argc 存储的是启动例程在命令行上面搜索到的参数个数，argv 则存储的是每个参数是什么
{
    if(argc<2){
        printf("Usage: cp [srcfile] [dstfile]\n");
        return -1;
    }
    int srcfd, dstfd;
    //O_RDONLY O_WRONLY O_RDWR
    srcfd=open(argv[1],O_RDONLY);  // argv[0]存的是命令本身 argv[1]存的是第一个参数
    if(srcfd<0){
        printf("open file(%s) error!\n",argv[1]);
        return -1;
    }
    dstfd=open(argv[2],O_WRONLY|O_CREAT,0644);
    if(dstfd<0){
        printf("open file(%s) error!\n",argv[2]);
        close(srcfd);
        return -1;
    }

    char buffer[1024]={'\0'};  // '\0'对应的 ascii 码为0，也就是 NULL 
    ssize_t len = 0;
    while((len = read(srcfd,buffer,1024)) != 0){
        write(dstfd,buffer,len);
        memset(buffer,'\0',sizeof(buffer)); // 清空缓冲区
    }
    
    close(srcfd);
    close(dstfd);

    return 0;
}
