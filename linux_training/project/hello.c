#include"student.h"
void hello(void)
    {
        int c;
       system("clear");
        printf("\n\n\t\t\t\t------------------------------------------\n");
        printf("\t\t\t\t|*****************************************|\n");
        printf("\t\t\t\t|*        欢     迎     使     用        *|\n");/**输出界面**/
        printf("\t\t\t\t|*                                       *|\n");
        printf("\t\t\t\t|* 学   生   信   息   管   理   系   统 *|\n");
        printf("\t\t\t\t|*****************************************|\n");
        printf("\t\t\t\t------------------------------------------\n\n");
        printf("\t\t\t\t           按任意键进入系统\n");
        scanf("%d",&c);
        FILE *w= fopen("xueguan.txt","r");/**打开文件**/
        if(w==NULL) menu();/**文件为空进入主菜单**/
        else/**输出文件中的信息**/
        {
            struct node*Head;/**定义头部**/
            Head = (struct node*)malloc(LEN);/**给头部开辟一个空间**/
            Node *p,*q;/**定义一个节点**/
            head=Head;/**保存头部**/
            while(!feof(w))/**如果文件没有结束则循环**/
            {
                p = (Node*)malloc(sizeof(Node));/**开辟新空间**/
                if(p==NULL)
                {
                    printf("申请空间失败！\a\n");
                    sleep(2);/**延时2s**/
                    hello();/**欢迎函数**/
                }
                fscanf(w,"%s\t%s\t%s\t%s\t%s",&(p->data).ID,&(p->data).name,&(p->data).Gender,&(p->data).Department,&(p->data).professional);/**输出学号，名字，性别，院系，专业**/
                fscanf(w,"\t%d\t%d\n",&(p->data).Class,&(p->data).TS);/**输出班级和总分**/
                n++;/**录入人数纪录**/
                if(n==1) Head->next = p;/**如果为第一个信息，令头部指向这个节点**/
                else q->next=p;/**如果不为第一个，则令前一个节点指向节点**/
                q=p;/**保存一个节点**/
                q->next=NULL;/**令此节点指向空**/
            }
            fclose(w);/**关闭文件**/
            menu();/**进入主菜单**/
        }
    }

