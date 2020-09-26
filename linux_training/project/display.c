#include"student.h"
void display(void)/**8.显示函数**/
    {
        int c;
        int d;
        if(n==0)
        {
            printf("还未录入信息！\n\a");
            printf("任意键退出！\n");
            scanf("%d",&d);
            menu();/**返回主菜单**/
        }
        Node *p5;/**定义一个节点**/
        p5=head->next;/**头部指向p5**/
       system("clear");
        printf("\t\t学生信息\n");
        while(p5!=NULL)/**p5不为空循环**/
        {
            Output(p5);/**输出函数**/
            printf("\t|-----------------------\n");/**输出分割线**/
            p5=p5->next;
        }
        printf("任意键退出！\n");
        scanf("%d",&c);
        menu();/**返回主菜单**/
    }
