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
    ps->data = (PeoInfo*)malloc(DEFAULT_SZ*sizeof(PeoInfo));
    if(ps->data == NULL)
    {
        return;

    }
    ps->size = 0;
    ps->capacity = DEFAULT_SZ;
}

void CheckCapacity(Contact* ps)
{
    if(ps->size == ps->capacity)
    {
        PeoInfo* ptr = realloc(ps->data,(ps->capacity+2)*sizeof(PeoInfo));
        if(ptr != NULL)
        {
            ps->data = ptr;
            ps->capacity+=2;
            printf("增容成功");
        }
        else
        {
            printf("增容失败");
        }
    }
    
}

void AddContact(struct Contact* ps)
{
    //检测当前通讯录容量
    //1.如果满了增加两个容量
    //2.如果不满啥也不干
    CheckCapacity(ps);
    //增加数据
    // if(ps->size == ps->capacity)
    // {
    //     printf("通讯录已满\n");
    // }
    // else
    // {
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
    int pos = 0;

    char name[MAX_NAME];
    scanf("%s",&name);
    //查找要删除的人在什么位置
    pos = FindByName(ps,name);

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
    int pos = 0;
    char name[MAX_NAME];
    printf("请输入要查找人的名字\n");
    scanf("%s",&name);

    pos = FindByName(ps,name);
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
    int pos = 0;
    char name[MAX_NAME];
    printf("请输入要查找人的名字\n");
    scanf("%s",&name);

    pos = FindByName(ps,name);

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

DestoryContact(Contact* ps)
{
    free(ps->data);
    ps->data = NULL;
}
