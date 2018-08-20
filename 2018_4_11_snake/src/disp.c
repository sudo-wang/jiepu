#include<stdio.h>
#include"disp.h"
#include"data.h"

void update()
{
	printf("\33[2J");
	dispGameArea();
	dispInfoArea();
	fflush(NULL);
}
void dispGameArea()
{
	int i;
	printf("\33[%d;%dH\33[44m[]\33[0m",snake.body[0].y,(snake.body[0].x+1)*2);
	for(i=1;i<snake.len;i++)
	{
	printf("\33[%d;%dH\33[43m[]\33[0m",snake.body[i].y,(snake.body[i].x+1)*2);
	}	
	printf("\33[%d;%dH\33[42m[]\33[0m",fruit_y,(fruit_x+1)*2);
	int x,y;
	for(y=0;y<30;y++)
	{
	for(x=0;x<20;x++)
	{
	if(gameArea[x][y]==1)	
	printf("\33[%d;%dH\33[43m[]\33[0m",y,(x+1)*2);
	}
	}
}
void dispInfoArea()
{
}
void initDisp()
{
	printf("\33[2J");
	printf("\33[?25l");
	fflush(NULL);
}
void closeGame()
{
	printf("\n");
	printf("\33[?25h");
	printf("\n");
}

