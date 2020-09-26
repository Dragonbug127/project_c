#include"student.h"
void Modify(Link s)/**4.修改信息程序**/
    {
        int choose4=0;/**定义选择4**/
       system("clear");/**清屏**/
        int x=0;/**储存性别选择**/
        printf("\t  学   号：%s（不可修改）\n",(s->data).ID);/**输出学号**/
        printf("\t1.姓   名：%s\n",(s->data).name);/**输出姓名**/
        printf("\t2.性   别：%s\n",(s->data).Gender);/**输出性别**/
        printf("\t3.院   系：%s\n",(s->data).Department);/**输出院系**/
        printf("\t4.专   业：%s\n",(s->data).professional);/**输出专业**/
        printf("\t5.班   级：%d\n",(s->data).Class);/**输出班级**/
        printf("\t6.总   分：%d\n",(s->data).TS);/**输出总分**/
        printf("\t0.退   出\n");
        printf("请输入需要修改的项目:");
        scanf("%d",&choose4);/**输入选择4**/
        switch(choose4)/**判断选择5**/
        {
        case 1:
            printf("\n请输入需要更改的姓名:");
            scanf("%s",&(s->data).name);/**输入修改是姓名**/
            printf("\n修 改 成 功！\n\a");
            sleep(1);/**延时800ms**/
            Modify(s);/**返回修改函数**/
            break;
        case 2:
            printf("\t3.请选择性别:1男  2女\n");
            scanf("%d",&x);/**输入选择**/
            if(x==1) strcpy((s->data).Gender,"男");/**输入1则为男**/
            else if(x==2) strcpy((s->data).Gender,"女");/**输入2则为女**/
            else/**否则**/
            {
                printf("\n输入有误请重新输入\n\a");
                sleep(1);/**延时800ms**/
                free(s);/**清空s**/
               system("clear");/**清屏**/
                Modify(s);/**返回修改函数**/
            }
            printf("\n修 改 成 功！\n\a");
            sleep(1);/**延时800ms**/
            Modify(s);/**返回修改函数**/
            break;
        case 3:
            printf("\n请输入需要更改的院系:");
            scanf("%s",&(s->data).Department);/**输入修改的院系**/
            printf("\n修 改 成 功！\n\a");
            sleep(1);/**延时800ms**/
            Modify(s);/**返回修改函数**/
            break;
        case 4:
            printf("\n请输入需要更改的专业:");
            scanf("%s",&(s->data).professional);/**输入修改的专业**/
            printf("\n修 改 成 功！\n\a");
            sleep(1);/**延时800ms**/
            Modify(s);/**返回修改函数**/
            break;
        case 5:
            printf("\n请输入需要更改的班级:");
            scanf("%d",&(s->data).Class);/**输入修改的班级**/
            printf("\n修 改 成 功！\n\a");
            sleep(1);/**延时800ms**/
            Modify(s);/**返回修改函数**/
            break;
        case 6:
            printf("\n请输入需要更改的总分:");
            scanf("%d",&(s->data).TS);/**输入修改的总分**/
            printf("\n修 改 成 功！\n\a");
            sleep(1);/**延时800ms**/
            Modify(s);/**返回修改函数**/
            break;
        case 0:menu();break;/**返回主菜单**/
        default:
            printf("\n您输入有误!\n请重新输入\n");
            sleep(1);/**延时800ms**/
            Modify(s);/**返回修改函数**/
        }
    }
