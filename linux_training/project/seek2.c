#include"student.h"
void seek2(int x)/**2.2姓名查询程序**/
    {
        Node *p3;
        p3=head->next;
        int m=0;/**查找成功标志信息**/
        char xm[15];/**输入的姓名**/
        char zhuanye[20];/**输入的专业*/
        int banj;/**输入的班级**/
        char yuanx[20];/**输入的院系**/
       system("clear");/**清屏**/
        switch(x)
        {
        case 2:
            printf("\t请输入需要查询的姓名：");
            scanf("%s",&xm);
            break;
        case 3:
            printf("\t请输入需要查询的专业：");
            scanf("%s",&zhuanye);
            break;
        case 4:
            printf("\t请输入需要查询的班级：");
            scanf("%d",&banj);
            break;
        case 5:
            printf("\t请输入需要查询的院系：");
            scanf("%s",&yuanx);
            break;
        }
        while(p3!=NULL)/**p3不为空循环**/
        {
            if(x==2)
            {
                if(strcmp(xm,(p3->data).name)==0)/**如果姓名相同**/
                {
                    m=1;/**查找成功**/
                    Output(p3);/**输出p3**/
                }
            }
            else if(x==3)
            {
                if(strcmp(zhuanye,(p3->data).professional)==0)
                {
                    m=1;/**查找成功**/
                    Output(p3);/**输出p3**/
                }
            }
            else if(x==4)
            {
                if(banj==(p3->data).Class)
                {
                    m=1;/**查找成功**/
                    Output(p3);/**输出p3**/
                }
            }
            else
            {
                if(strcmp(yuanx,(p3->data).Department)==0)
                {
                    m=1;/**查找成功**/
                    Output(p3);/**输出p3**/
                }
            }
            p3=p3->next;/**p3指向下一节点**/
        }
        if(m==1) ret(p3,0);/**如果查询到进入返回界面，并传节点p3**/
        else/**否则**/
        {
            printf("\n\n\t\t\t\t未查找到学生信息\n");
            ret(p3,0);/**进入返回界面，并传节点p4**/
        }
    }
