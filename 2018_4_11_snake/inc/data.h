#ifndef _DATA_H
#define _DATA_H

typedef struct
{
	int x,y,c;
}Body;
typedef struct
{
	int len;
	int dir;
	Body body[600];
}Snake;

extern int gameArea[20][30];
extern int fruit_x,fruit_y;
extern Snake snake;
void initData();
void eat();

#endif
