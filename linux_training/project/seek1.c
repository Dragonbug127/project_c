#include"student.h"

void seek1(int A)/**2.1学号查询程序**/
    {
        Node *p3,*p4;/**定义两个节点**/
        p3=head->next;/**使p3为第一个单元**/
        int m=0;/**查找成功标志信息**/
        char xuehao[15];/**输入的学号**/
       system("clear");/**清屏**/
        printf("\t请输入需要查询的学号：");
        scanf("%s",xuehao);/**输入学号**/
        while(p3!=NULL)/**p3不为空循环**/
        {
            if(strcmp(xuehao,(p3->data).ID)==0)/**如果学号相同**/
            {
                m=1;/**查找成功**/
                p4=p3;/**保存此时的p3**/
                Output(p3);/**输出p3**/
            }
            p3=p3->next;/**p3指向下一位节点*/
        }
        if(m==1) ret(p4,A);/**如果查询到进入返回界面，并传节点p4**/
        else/**否则**/
        {
            printf("\n\n\t\t\t\t未查找到学生信息\n");
            ret(p4,A);/**到达返回界面**/
        }
    }
