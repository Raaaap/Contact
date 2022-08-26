# define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 20
#define MAX_ADDR 50
#define DEFAULT_SZ 3

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

typedef struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact
{
    struct PeoInfo* data;//存放data指针
    int size;//通讯录中已经存放的好友个数
    int capacity;//当前通讯录最大容量

}Contact;

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

//销毁通讯录
void DestoryContact(Contact* ps);



