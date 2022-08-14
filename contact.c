#include"contact.h"

# define _CRT_SECURE_NO_WARNINGS 1

//查找函数，找到了返回元素下标
//找不到返回-1
static int FindByName(const struct Contact* ps,char name[MAX_NAME])
{
    int i = 0;
    for(i=0;i<ps->size;i++)
    {
        if(0==strcmp(name,ps->data[i].name))
        {
            return i; 
        }
        else
        {
        return -1;
        }
    }

}


void InitContact(struct Contact* ps)
{
    memset(ps->data,0,sizeof(ps->data));
    ps->size = 0;//设置通讯录最初只有零个元素
}

void AddContact(struct Contact* ps)
{
    if(ps->size == MAX)
    {
        printf("通讯录已满\n");
    }
    else
    {
        printf("请输入名字\n");
        scanf("%s",&ps->data[ps->size].name);
        printf("请输入年龄\n");
        scanf("%s",&ps->data[ps->size].age);
        printf("请输入性别\n");
        scanf("%s",&ps->data[ps->size].sex);
        printf("请输入电话\n");
        scanf("%s",&ps->data[ps->size].tele);
        printf("请输入住址\n");
        scanf("%s",&ps->data[ps->size].addr);

        ps->size++;
        printf("添加成功\n");
    }
}

void ShowContact(const struct Contact* ps)
{
    printf("%20s\t%4s\t%5s\t%12s\t%20s","姓名","年龄","性别","电话","地址");
    int i = 0;
    for(i=0;i<ps->size;i++)
    {
        printf("%20s\t%4s\t%5s\t%12s\t%20s",
        ps->data[i].name,
        ps->data[i].age,
        ps->data[i].sex,
        ps->data[i].tele,
        ps->data[i].addr
        );
    }
}

void  DeleteContact(struct Contact* ps)
{

    char name[MAX_NAME];
    scanf("%s",&name);
    //查找要删除的人在什么位置
    int pos = FindByName(ps,name);

    //删除
    if(pos == -1)
    {
        printf("通讯录中无该联系人");
    }
    else
    {
        int j = 0;
        for( j = pos;j<ps->size-1;j++)
        {
            ps->data[j]=ps->data[j+1];
        }
        ps->size--;
        printf("删除成功\n");

    }
    
}

void SearchContact(const struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的名字\n");
    scanf("%s",&name);

    int pos = FindByName(ps,name);
    if(-1 == pos)
    {
        printf("通讯录中不存在此联系人");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s","姓名","年龄","性别","电话","地址");
    
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s",
        ps->data[pos].name,
        ps->data[pos].age,
        ps->data[pos].sex,
        ps->data[pos].tele, 
        ps->data[pos].addr
        );
        
    }
}

void ModifyContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的名字\n");
    scanf("%s",&name);

    int pos = FindByName(ps,name);

    if(-1 == pos)
    {
        printf("通讯录中不存在此联系人");
    }
    else
    {
        printf("请输入名字\n");
        scanf("%s",&ps->data[pos].name);
        printf("请输入年龄\n");
        scanf("%s",&ps->data[pos].age);
        printf("请输入性别\n");
        scanf("%s",&ps->data[pos].sex);
        printf("请输入电话\n");
        scanf("%s",&ps->data[pos].tele);
        printf("请输入住址\n");
        scanf("%s",&ps->data[pos].addr);

        
        printf("修改成功\n");

    }
    
}
