/*************************************************************************
	> File Name: include/userlist.h
	> Author   : Wang Xu
	> Tips: 1.按F5可以直接编译并执行C、C++、java代码以及执行shell脚本，按“F8”可进行C、C++代码的调试
	> Tips: 2.按“F2”可以直接消除代码中的空行、“F3”可列出当前目录文件，打开树状文件目录。按“Ctrl + P”可自动补全
	> Tips: 3.使用:sp + 文件名可以水平分割窗口,使用:vs + 文件名可以垂直分割窗口,使用Ctrl + w可以快速在窗口间切换 
	> Created Time: 2018年08月04日 星期六 15时33分24秒
 ************************************************************************/

#ifndef _USERLIST_
#define _USERLIST_

struct User {
    int userid;
    char name[20];
    char passwd[10];
} User;
typedef struct User* PUser;

typedef struct list{
    PUser _u;
    struct list *next;
} Node;
typedef struct list* PNode;

extern PNode create_userlist(void);
extern int insert_user(PNode head, PUser user);
extern int delete_user(PNode head, int userid);
extern int modify_user(PNode head, int userid, PUser up);
extern PNode search_user(PNode head, int userid);
extern void destroy_list(PNode head);
extern int counter_list(PNode head);


#endif
