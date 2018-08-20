/*************************************************************************
	> File Name: src/displayio.c
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年08月11日 星期六 18时45分09秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    FILE *f;
    f = fopen("text", "w");
    if(f == NULL)
    {
        printf("open failed!\n");
        return -1;
    }
    fputc('h', f);               // 向 text 文件中写入字符 'h'
    char buffer[1024] = {0};
    fgets(buffer, 1024, stdin);  // 从标准输入中读入字符串读到 buffer 中（遇到空格不会终止,所以读入会是一句完整的话，不像scanf）
    //scanf("%s", buffer);       // 如果用 scanf 读入的话，遇到空格就终止了
    fputs(buffer, f);       // 将 buffer 中的数据输出到 f 中
    fclose(f);
    return 0;

}
