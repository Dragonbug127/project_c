#include"student.h"
void Entry(void)/**1.输入学生信息**/
    {
        int choose1=0;/**选择1**/
        if(n>0)Insert();/**如果注册人数大于0进入插入函数**/
       system("clear");/** 清屏 **/
        struct node*Head;/**定义头部**/
        Node *p1,*p2;/**定义两个节点**/
        Head = (struct node*)malloc(LEN);/**给头部开辟空间**/
        head = Head;/**保存头部**/
        while(1)/**无限循环**/
        {
            p2 = (struct node*)malloc(LEN);/**开辟一个空间**/
            if(p2==NULL)
            {
                printf("申请空间失败！\a\n");
                sleep(2);/**延时2000ms**/
                p1->next=NULL;/**p2指向空结束链表**/
                menu();/**返回主菜单函数**/
            }
            printf("\t1.请输入学号:");
            scanf("%s",(p2->data).ID);/**储存学号**/
            printf("\t2.请输入姓名:");
            scanf("%s",(p2->data).name);/**储存名字**/
            printf("\t3.请输入性别:");
            scanf("%s",(p2->data).Gender);/**保存性别**/
            printf("\t4.请输入院系:");
            scanf("%s",(p2->data).Department);/**储存院系**/
            printf("\t5.请输入专业:");
            scanf("%s",(p2->data).professional);/**储存专业**/
            printf("\t6.请输入班级:");
            scanf("%d",&(p2->data).Class);/**储存班级**/
            printf("\t7.请输入总分:");
            scanf("%d",&(p2->data).TS);/**储存总分**/
            n++;/**学生人数增加**/
            if(n==1) Head->next = p2;/**如果头部尾指向空则使头部尾指向p3头**/
            else p1->next=p2;/**否则使p1的尾指向p2的头**/
            p1=p2;/**令p1等于p2**/
            printf("\t结束录入请按0\n\t按任意键继续输入");
            scanf("%d",&choose1);/**输入选择**/
            if(choose1==0)/**输入为0 **/
            {
                p1->next=NULL;
                p2->next=NULL;/**使最后一个表尾指向空**/
                menu();/**返回主菜单界面**/
            }
           system("clear");/** 清屏 **/
        }
    }
