#include"student.h"
void Insert(void)/**5.插入函数**/
    {
        int c=0;/**插入次数判断**/
        int choose5=0;/**定义选择5**/
        if(n==0)Entry();/**如果录入人数为0进入录入函数录入信息**/
       system("clear");/** 清屏 **/
        Node *p5,*p6,*p7;/**定义两个节点**/
        while(1)/**无限循环**/
        {
            p6 = (struct node*)malloc(LEN);/**开辟空间**/
            if(p6==NULL)
            {
                printf("申请空间失败！\a\n");
                sleep(2);/**延时2000ms**/
                p7->next=NULL;/**p2指向空结束链表**/
                menu();/**返回主菜单函数**/
            }
            printf("\t1.请输入学号:");
            scanf("%s",&(p6->data).ID);/**储存学号**/
            printf("\t2.请输入姓名:");
            scanf("%s",&(p6->data).name);/**储存姓名**/
            printf("\t3.请选择性别:");
            scanf("%s",&(p6->data).Gender);/**输入性别*/
            printf("\t4.请输入院系:");
            scanf("%s",&(p6->data).Department);/**储存院系**/
            printf("\t5.请输入专业:");
            scanf("%s",&(p6->data).professional);/**储存专业**/
            printf("\t6.请输入班级:");
            scanf("%d",&(p6->data).Class);/**储存班级**/
            printf("\t7.请输入总分:");
            scanf("%d",&(p6->data).TS);/**储存总分**/
            n++;/**人数加一**/
            c++;/**插入人数加一**/
            if(c==1) p5=p6;/**储存p6**/
            else p7->next=p6;/**如果头部尾指向空则使头部尾指向p3头**/
            p7=p6;/**令p7等于p6**/
            printf("\t结束录入请按0\n\t按任意键继续输入\n");
            scanf("%d",&choose5);/**输入一个字符**/
            if(choose5==0)/**如果选择0**/
            {
                p6->next = head->next->next;/**p6节点指向原来的第二位节点**/
                head->next->next = p5;/**第一位节点指向p5**/
                B=0;
                menu();/**返回主菜单**/
            }
            p6=p6->next;/**p6指向下一节点**/
           system("clear");/** 清屏 **/
        }
    }
