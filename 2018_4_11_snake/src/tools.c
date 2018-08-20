#include <termios.h>
#include <stdio.h>
#include<sys/time.h>
#include<signal.h>
#include"active.h"

struct termios tm_old;
//获取一个字符而 不回显
int getch()
{
	struct termios tm;
	tcgetattr(0,&tm_old);
	cfmakeraw(&tm);
	tcsetattr(0,0,&tm);
	int ch = getchar();
	tcsetattr(0,0,&tm_old);
	return ch;
}
void alarmUs(int t)
{
	//定义结构体
	struct itimerval v;
	//定时器启动的初始值
	v.it_value.tv_sec = 0;		//it_value延时时长   tv_sec秒   tv_usec微妙
	v.it_value.tv_usec = t;
	//定时器启动后的间隔时间值
	v.it_interval.tv_sec = 0;	//it_interval计时间隔
	v.it_interval.tv_usec = t;
	//将时钟计时信号发送出去
	setitimer(ITIMER_REAL,&v,NULL);	//setitimer(系统时间，要设置的值，原来设置的值)
}

void catchSignal(int s)
{
	go();
}
