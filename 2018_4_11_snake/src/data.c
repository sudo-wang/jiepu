#include"data.h"
#include<stdlib.h>
#include<time.h>

int gameArea[20][30]={0};
int fruit_x,fruit_y;
Snake snake;

static int checkFruitCoordinate();
void initData()
{
	srand(time(NULL));
	int x,y;
	for(x=0;x<20;x++)
	{
	for(y=0;y<30;y++)
	{
	if(x==0||x==19||y==0||y==29)
		gameArea[x][y]=1;
	else
		gameArea[x][y]=0;
	}
	}

	snake.len=5;
	snake.dir=0;
	int i;
	for(i=0;i<5;i++)
	{
	snake.body[i].x=8+i;
	snake.body[i].y=15;
	}
	do
	{
	fruit_x=random()%18+1;
	fruit_y=random()%28+1;
	}while(checkFruitCoordinate());
}
void eat()
{
	do
	{
	fruit_x=random()%18+1;
	fruit_y=random()%28+1;
	}while(checkFruitCoordinate());
	
}
static int checkFruitCoordinate()
{
	int i;
	for(i=0;i<snake.len;i++)
	{
	if(fruit_x==snake.body[i].x&&fruit_y==snake.body[i].y)
		return 1;
	}
	return 0;
}
