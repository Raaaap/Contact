# define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 20
#define MAX_ADDR 50

enum Option
{
    EXIT,
    ADD,
    DELETE,
    SEARCH,
    MODIFY,
    SHOW,
    SORT
};

struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

struct Contact
{
    struct PeoInfo data[MAX];//存放一千个好友信息
    int size;//通讯录中已经存放的好友个数
};

//初始化通讯录
void InitContact(struct Contact* ps);

//添加联系人
void AddContact(struct Contact* ps);

//查看所有联系人信息
void ShowContact(const struct Contact* ps);

//删除一位联系人
void DeleteContact(struct Contact* ps);

//查找联系人
void SearchContact(const struct Contact* ps);

//修改指定联系人的信息
void ModifyContact(struct Contact* ps);



