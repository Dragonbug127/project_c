#include"student.h"
void retreat()/**退出函数**/
    {
        Node *p,*q;/**定义一个节点**/
        q=p=head->next;/**q,p节点从头开始**/
        if(B==1)/**已保存**/
        {
            n=0;
            B=0;
            while(q!=NULL)/**q不为空循环**/
            {
                p=q->next;/**p为q的下一位**/
                free(q);/**删除q**/
                q=p;/**q等于p**/
            }
            free(head);/**清空head**/
            hello();/**返回主函数**/
        }
        else/**未保存**/
        {
            printf("\t您录入的信息还未保存请保存后退出！\n\a");
            sleep(1);/**延时**/
            menu();/**返回菜单**/
        }
    }
