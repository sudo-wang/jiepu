/*************************************************************************
	> File Name: data.h
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年08月03日 星期五 11时17分59秒
 ************************************************************************/

#ifndef _DATA_H
#define _DATA_H

extern int gameArea[20][30];
extern int block[4][4];
extern int b_x, b_y;
void initData();      //初始化相关变量
void initBlock(int n, int r);     // n 形状为 7，r 方向为 4
void initNextBlock(); 
int rotate();

#endif
