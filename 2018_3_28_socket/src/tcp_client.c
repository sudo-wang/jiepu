/*************************************************************************
	> File Name: src/tcp_client.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年07月26日 星期四 14时37分44秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<netdb.h>

int main(int argc,char ** argv)
{
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in saddr;
    memset(&saddr, 0,sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(10000);
    inet_ntop(AF_INET,"127.0.0.1",(char*)&saddr.sin_addr,sizeof(saddr.sin_addr));
    connect(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));

    char buffer[100]={'\0'};

    read(sockfd,buffer,100);
    printf("get server time: %s\n",buffer);
    close(sockfd);
    return 0;
}
