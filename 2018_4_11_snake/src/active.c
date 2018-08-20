#include<stdlib.h>
#include"active.h"
#include"data.h"
#include"disp.h"

static void checkFruit();
static void checkSnake(int d);
void up()
{
	if(snake.dir==3)
		return;
	checkSnake(1);
	int i;
	for(i=snake.len;i>0;i--)
	{
	snake.body[i]=snake.body[i-1];
	}
	snake.body[0].y--;
	snake.dir=1;
	checkFruit();
	update();
}
void down()
{
	if(snake.dir==1)
		return;
	checkSnake(3);
	int i;
	for(i=snake.len;i>0;i--)
	{
	snake.body[i]=snake.body[i-1];
	}
	snake.body[0].y++;
	snake.dir=3;
	checkFruit();
	update();
}
void left()
{
	if(snake.dir==2)
		return;
	checkSnake(0);
	int i;
	for(i=snake.len;i>0;i--)
	{
	snake.body[i]=snake.body[i-1];
	}
	snake.body[0].x--;
	snake.dir=0;
	checkFruit();
	update();
}
void right()
{
	if(snake.dir==0)
		return;
	checkSnake(2);
	int i;
	for(i=snake.len;i>0;i--)
	{
	snake.body[i]=snake.body[i-1];
	}
	snake.body[0].x++;
	snake.dir=2;
	checkFruit();
	update();
}
void go()
{
	int i;
	for(i=snake.len;i>0;i--)
		snake.body[i]=snake.body[i-1];
	if(snake.body[1].x>snake.body[2].x)
	{
	checkSnake(2);	
		snake.body[0].x++;
		snake.dir=2;
		checkFruit();
		update();
	}
	else if(snake.body[1].x<snake.body[2].x)
	{
	checkSnake(0);	
		snake.body[0].x--;
		snake.dir=0;
		checkFruit();
		update();
	}
	else if(snake.body[1].y>snake.body[2].y)
	{
	checkSnake(3);	
		snake.body[0].y++;
		snake.dir=3;
		checkFruit();
		update();
	}
	else if(snake.body[1].y<snake.body[2].y)
	{
		snake.body[0].y--;
		snake.dir=1;
		checkFruit();
		update();
	checkSnake(1);	
	}
	update();	

}

static void checkFruit()
{
	if(fruit_x==snake.body[0].x&&fruit_y==snake.body[0].y)
	{
	snake.len++;
	eat();
	}
}
static void checkSnake(int d)
{
	int x,y,i;
	if(d==0)
	{
		x=snake.body[0].x-1;
		y=snake.body[0].y;
	}
	else if(d==1)
	{
		x=snake.body[0].x;
		y=snake.body[0].y-1;
	}
	else if(d==2)
	{
		x=snake.body[0].x+1;
		y=snake.body[0].y;
	}
	else if(d==3)
	{
		x=snake.body[0].x;
		y=snake.body[0].y+1;
	}

	if(x==0||x==19||y==0||y==29)
	{
		closeGame();
		exit(0);
	}
	for(i=0;i<snake.len;i++)
	{
	if(x==snake.body[i].x&&y==snake.body[i].y)
	{
		closeGame();
		exit(0);
	}
	}
}
