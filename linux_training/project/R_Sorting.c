#include"student.h"
void R_Sorting(int y)/**排序执行函数**/
    {
        Node *x1,*x2,*x;/**定义三个节点**/
        x1=head->next;/**头部指向x1**/
        if(y==1||y==3)
        {
            for(;x1!=NULL;x1=x1->next)/**x1不为空循环**/
            {
                x2=head->next;/**头部指向x2**/
                for(;x2!=NULL;x2=x2->next)/**x不为空循环**/
                {
                    if(y==1)
                    {
                        if(x1->data.TS < x2->data.TS)/**如果x1的总分大于x2的总分**/
                        {
                            x=(struct node*)malloc(LEN);/**给x开辟一个空间**/
                            x->data = x1->data;
                            x1->data = x2->data;/**通过中间量x实现x1，x2换位**/
                            x2->data = x->data;
                            free(x);/**释放x**/
                        }
                    }
                    else
                    {
                        if(strcmp((x1->data).ID,(x2->data).ID) < 0)/**如果x1的总分大于x2的总分**/
                        {
                            x=(struct node*)malloc(LEN);/**给x开辟一个空间**/
                            x->data = x1->data;
                            x1->data = x2->data;/**通过中间量x实现x1，x2换位**/
                            x2->data = x->data;
                            free(x);/**释放x**/
                        }
                    }
                }
            }
        }
        else
        {
            for(;x1!=NULL;x1=x1->next)/**x1不为空循环**/
            {
                x2=head->next;/**头部指向x2**/
                for(;x2!=NULL;x2=x2->next)/**x不为空循环**/
                {
                    if(y==1)
                    {
                        if(x1->data.TS > x2->data.TS)/**如果x1的总分大于x2的总分**/
                        {
                            x=(struct node*)malloc(LEN);/**给x开辟一个空间**/
                            x->data = x1->data;
                            x1->data = x2->data;/**通过中间量x实现x1，x2换位**/
                            x2->data = x->data;
                            free(x);/**释放x**/
                        }
                    }
                    else
                    {
                        if(strcmp((x1->data).ID,(x2->data).ID) > 0)/**如果x1的总分大于x2的总分**/
                        {
                            x=(struct node*)malloc(LEN);/**给x开辟一个空间**/
                            x->data = x1->data;
                            x1->data = x2->data;/**通过中间量x实现x1，x2换位**/
                            x2->data = x->data;
                            free(x);/**释放x**/
                        }
                    }
                }
            }
        }
        display();/**进入显示函数**/
    }
