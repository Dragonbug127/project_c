#include"student.h"
void Statistics(void)/**7.统计函数**/
    {
        int d;
        Node *p4;/**定义一个节点**/
        int x[2]={0};/**记录男生女生人数**/
        int b[10]={0};/**纪录各班人数**/
        int c=0;/**循环次数**/
        p4=head->next;/**头部指向p4**/
        while(p4!=NULL)/**p4不为空循环**/
        {
            b[(p4->data).Class-1]++;/**班级加一**/
            if(strcmp((p4->data).Gender,"男")==0) x[0]++;/**男生人数加一**/
            if(strcmp((p4->data).Gender,"女")==0) x[1]++;/**女生人数加一**/
            p4=p4->next;/**p4指向下一节点**/
        }
        printf("\t录入人数为:%d\n",n);/**输出总人数**/
        printf("\t男生人数为:%d\n",x[0]);/**输出男生人数**/
        printf("\t女生人数为:%d\n",x[1]);/**输出女生人数**/
        for(c=0;c<10;c++)/**循环10次**/
        {
            if(b[c]!=0) printf("\t%d班的人数为%d\n",c+1,b[c]);/**输出班级以及人数**/
            else  continue;/**没有结束循环**/
        }
        printf("任意键退出！\n");
        scanf("%d",&d);
        menu();/**返回主菜单**/
    }
