# define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void menu()
{
    printf("*****************************");
    printf("**** 1.add      2.delete ****");
    printf("**** 3.search   4.modify ****");
    printf("**** 5.show     6.sort   ****");
    printf("****       0.exit       *****");
    printf("*****************************");


}

int main()
{
    int input = 0;

    //创建通讯录
    struct Contact con;
    //初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("请输入选项\n");
        scanf("%d",&input);
        switch(input)
        {
            case ADD:
                AddContact(&con);
                break;
            case DELETE:
                DeleteContact(&con);
                break;
            case SEARCH:
                SearchContact(&con);
                break;
            case MODIFY:
                break;
            case SHOW:
                ShowContact(&con);
                break;
            case SORT:
                break;
            case EXIT:
                DestoryContact(&con);
                printf("退出通讯录\n");
                break;
            default:
                printf("选择错误\n");
                break;
        }
    }while(input);
    

    return 0;
}

