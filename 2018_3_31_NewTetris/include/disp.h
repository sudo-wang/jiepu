/*************************************************************************
	> File Name: disp.h
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年08月03日 星期五 11时27分51秒
 ************************************************************************/

#ifndef _DISP_H
#define _DISP_H

void updata();           //刷新界面
void dispGameArea();     //打印游戏区域
void dispInfoArea();     //打印游戏信息 分数、等级、下一个方块形状
void initDisp();
void closeGame();

#endif
