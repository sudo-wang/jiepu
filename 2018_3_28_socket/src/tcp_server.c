/*************************************************************************
	> File Name: src/tcp_server.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年07月24日 星期二 18时29分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<error.h>
#include<unistd.h>
#include<fcntl.h>
#include<netdb.h>
#include<time.h>

void do_server(int fd)
{
    time_t t = time(NULL);
    char *ct = ctime(&t);
    write(fd,ct,strlen(ct));
}

int main(int argc, char **argv)
{
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        printf("socket error!\n");
        return -1;
    }

    struct sockaddr_in saddr;
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(10000);
    saddr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr))<0){
        printf("bind error!\n");
        close(sockfd);
        return -1;
    }
    
    if(listen(sockfd,10) < 0){
        printf("listen error!\n");
        close(sockfd);
        return -1;
    }

    int connfd;
    while(1){
        connfd = accept(sockfd,NULL,NULL);
        if(connfd < 0){
            printf("connfd error!\n");
            continue;
        }
        do_server(connfd);
        close(connfd);
    }

    close(sockfd);
    return 0;
}

