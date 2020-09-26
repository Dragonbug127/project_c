#include"student.h"
void Delete()/**3.删除信息**/
    {
        Node *d1,*d2;/**定义两个节点**/
        char xuehao[15];/**定义学号**/
        int m = 0 ;/**查找成功标志信息**/
        d1=head;/**头指向d1**/
        printf("请输入要删除的学生学号:");
        scanf("%s",xuehao);/**输入学号**/
        while(d1->next!=NULL)/**直到d1指向空停止循环**/
            {
                if(strcmp(xuehao,(d1->next->data).ID) == 0)/**如果学号相同**/
                {
                    m = 1;/**查找成功标志信息**/
                    printf("\t学   号：%s\n",(d1->next->data).ID);/**输出学号**/
                    printf("\t姓   名：%s\n",(d1->next->data).name);/**输出姓名**/
                    printf("\t性   别：%s\n",(d1->next->data).Gender);/**输出性别**/
                    printf("\t院   系：%s\n",(d1->next->data).Department);/**输出院系**/
                    printf("\t专   业：%s\n",(d1->next->data).professional);/**输出专业**/
                    printf("\t班   级：%d\n",(d1->next->data).Class);/**输出班级**/
                    printf("\t总   分：%d\n",(d1->next->data).TS);/**输出总分**/
                    d2 = d1->next;/**d2保存删除的位置**/
                    d1->next = d2->next;/**d1指向d2的下一位**/
                    free(d2);/**删除d2**/
                    printf("删除中》》》》\n\a");
                    sleep(1);/**延时500ms**/
                   system("clear");
                    printf("删除成功\n\a");
                    n--;
                    sleep(1);/**延时800ms**/

                }
                d1=d1->next;/**d1指向下一位**/
            }
        if(m==1)/**如果m为1**/
        {
            menu();/**返回主菜单**/
        }
        else
        {
            printf("查询无效！！\n");
            sleep(1);/**延时800ms**/
            menu();/**返回主菜单**/
        }
    }
