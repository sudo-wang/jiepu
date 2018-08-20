#include<stdlib.h>
#include<signal.h>
#include"data.h"
#include"disp.h"
#include"active.h"
#include"tools.h"

int main()
{
	initData();
	initDisp();
	update();
	
	signal(SIGALRM,catchSignal);
	alarmUs(800000);
	char ch;
	while(1)
	{
	ch=getch();
	switch(ch)
	{
	case 'a':
		left();
		snake.dir=2;
	break;
	case 'w':
		up();
		snake.dir=1;
	break;
	case 'd':
		right();
		snake.dir=0;
	break;
	case 's':
		down();
		snake.dir=3;
	break;
	case 'q':
		closeGame();
		exit(0);
	break;
	}
	}
	closeGame();
	return 0;
}
