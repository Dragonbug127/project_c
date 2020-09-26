    #include<stdio.h>
    #include<stdlib.h>
    #include<conio.h>/**getch头文件**/
    #include<string.h>
    #include<windows.h>
    #define LEN sizeof(struct node)
    ///链表
    typedef struct student/**定义学生相关信息的结构体，标记为student**/
    {
        char ID[15];/**学号**/
        char name[15];/**姓名**/
        char Gender[5];/**性别**/
        char Department[20];/**院系**/
        char professional[50];/**专业**/
        int Class;/**班级**/
        int TS;/**总分**/
    }STU;
    typedef struct node/**定义每条记录的结构体，标记为node**/
    {
        STU data;/**数据域**/
        struct node *next;/**指针域**/
    }Node,*Link;
    ///全局变量
    int n=0;/**录入的人数**/
    Node *head;/**储存头部**/
    int B;/**保存标志信息**/
    ///自定义函数
    void hello(void);/**欢迎界面**/
    void menu(void);/**主菜单界面**/
    void Entry(void);/**1.输入信息函数**/
    void Insert(void);/**2.插入函数**/
    void Delete(void);/**3.删除信息**/
    void Modify(Link s);/**4.修改界面**/
    void Statistics(void);/**5.统计函数**/
    void Sorting(void);/**6.排序函数**/
    void R_Sorting(int y);/**6.1排序函数排序**/
    void seek(void);/**7查询信息界面**/
    void seek1(int A);/**7.1学号查询程序**/
    void seek2(int x);/**7.2查询程序**/
    void ret(Link z,int A);/**7.3查询后退出函数**/
    void display(void);/**8.显示函数**/
    void Save(void);/**9.保存函数**/
    void retreat(void);/**退出函数**/
    void Output(Link l);/**输出信息函数**/

    void menu()/**主菜单**/
    {
        int choose=0;/**选择**/
        system("cls");/** 清屏 **/
        printf("\t\t\t            <<<<学生成绩管理系统>>>>           \n");
        printf("\t\t\t                    主菜单                     \n\n");
        printf("\t\t\t-----------------------------------------------\n");
        printf("\t\t\t|*********************************************|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*     1 录入信息            2 插入信息      *|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*     3 删除信息            4 修改信息      *|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*     5 统计信息            6 排序信息      *|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*     7 查找信息            8 显示信息      *|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*     9 保存信息            0 退出系统      *|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*********************************************|\n");
        printf("\t\t\t-----------------------------------------------\n");
        scanf("%d",&choose);/**输入选择**/
        switch(choose)/**选择判断**/
        {
        case 1:Entry();break;/**进入录入函数**/
        case 2:Insert();break;/**进入插入函数**/
        case 3:Delete();break;/**进入删除函数**/
        case 4:seek1(1);break;/**进入查询1学号查找函数**/
        case 5:Statistics();break;/**进入统计函数**/
        case 6:Sorting();break;/**进入排序函数**/
        case 7:seek();break;/**进入查找函数**/
        case 8:display();break;/**进入显示函数**/
        case 9:Save();break;/**进入保存函数**/
        case 0:retreat();break;/**进入退出函数**/
        default:
            printf("\t输入有误请重新输入！\n\a");
            Sleep(800);/**眼熟800毫秒**/
            menu();/**进入主函数**/
            break;
        }
    }

    void Entry(void)/**1.输入学生信息**/
    {
        int choose1=0;/**选择1**/
        if(n>0)Insert();/**如果注册人数大于0进入插入函数**/
        system("cls");/** 清屏 **/
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
                Sleep(2000);/**延时2000ms**/
                p1->next=NULL;/**p2指向空结束链表**/
                menu();/**返回主菜单函数**/
            }
            printf("\t1.请输入学号:");
            scanf("%s",&(p2->data).ID);/**储存学号**/
            printf("\t2.请输入姓名:");
            scanf("%s",&(p2->data).name);/**储存名字**/
            printf("\t3.请输入性别:");
            scanf("%s",&(p2->data).Gender);/**保存性别**/
            printf("\t4.请输入院系:");
            scanf("%s",&(p2->data).Department);/**储存院系**/
            printf("\t5.请输入专业:");
            scanf("%s",&(p2->data).professional);/**储存专业**/
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
            system("cls");/** 清屏 **/
        }
    }

    void seek(void)/**2.查找学生信息界面**/
    {
        int choose2=0;
        system("cls");/** 清屏 **/
        printf("\t\t\t查 询 方 式 选 择\n");
        printf("\t\t\t  <1> 学  号     \n");
        printf("\t\t\t  <2> 姓  名     \n");/**输出查询方式**/
        printf("\t\t\t  <3> 专  业     \n");
        printf("\t\t\t  <4> 班  级     \n");
        printf("\t\t\t  <5> 院  系     \n");
        printf("\t\t\t  <0> 退  出     \n");
        scanf("%d",&choose2);/**输入选择2**/
        if(n==0)
        {
            printf("还未录入过信息无法查询！\n\a");
            Sleep(800);
            menu();
        }
        switch(choose2)/**判断选择2**/
        {
        case 0:menu();break;/**进入主菜单函数**/
        case 1:seek1(0);break;/**进入查询1函数**/
        case 2:seek2(2);break;/**进入查询2函数**/
        case 3:seek2(3);break;/**进入查询4函数**/
        case 4:seek2(4);break;/**进入查询5函数**/
        case 5:seek2(5);break;/**进入查询6函数**/
        default:
            printf("\t输入有误请重新输入！\n\a");
            Sleep(800);/**延时800毫秒**/
            seek();/**进入查找函数**/
            break;
        }
    }

    void seek1(int A)/**2.1学号查询程序**/
    {
        Node *p3,*p4;/**定义两个节点**/
        p3=head->next;/**使p3为第一个单元**/
        int m=0;/**查找成功标志信息**/
        char xuehao[15];/**输入的学号**/
        system("cls");/**清屏**/
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

    void seek2(int x)/**2.2姓名查询程序**/
    {
        Node *p3;
        p3=head->next;
        int m=0;/**查找成功标志信息**/
        char xm[15];/**输入的姓名**/
        char zhuanye[20];/**输入的专业*/
        int banj;/**输入的班级**/
        char yuanx[20];/**输入的院系**/
        system("cls");/**清屏**/
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

    void Output(Link l)/**2.6输出信息函数**/
    {
        printf("\t学 号：%s\n",(l->data).ID);/**输出学号**/
        printf("\t姓 名：%s\n",(l->data).name);/**输出姓名**/
        printf("\t性 别：%s\n",(l->data).Gender);/**输出性别**/
        printf("\t院 系：%s\n",(l->data).Department);/**输出院系**/
        printf("\t专 业：%s\n",(l->data).professional);/**输出专业**/
        printf("\t班 级：%d\n",(l->data).Class);/**输出班级**/
        printf("\t总 分：%d\n\n",(l->data).TS);/**输出总分**/
    }

    void ret(Link z,int A)/**返回函数**/
    {
        int choose4=0;
        if(A==1)/**A等于1时为修改**/
        {
            printf("1.修改学生信息\n2.退出");
            scanf("%d",&choose4);/**输入选择4**/
            switch(choose4)/**判断选择4**/
            {
            case 1:Modify(z);break;/**进入修改界面**/
            case 2:
                menu();/**返回主菜单**/
                break;/**返回菜单函数**/
            default:
                printf("您输入有误请重新输入！\n\a");
                Sleep(800);/**延时800毫秒**/
                ret(z,A);/**返回退出函数**/
                break;
            }
        }
        else/**否则为普通退出**/
        {
            printf("按任意键返回！\n\a");
            getch();/**读取一个字符**/
            Sleep(800);/**延时800毫秒**/
            seek();/**返回查找函数**/
        }
    }

    void Delete()/**3.删除信息**/
    {
        Node *d1,*d2;/**定义两个节点**/
        char xuehao[15];/**定义学号**/
        int m = 0 ;/**查找成功标志信息**/
        d1=head;/**头指向d1**/
        printf("请输入要删除的学生学号:");
        scanf("%s",&xuehao);/**输入学号**/
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
                    Sleep(500);/**延时500ms**/
                    system("cls");
                    printf("删除成功\n\a");
                    n--;
                    Sleep(800);/**延时800ms**/

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
            Sleep(800);/**延时800ms**/
            menu();/**返回主菜单**/
        }
    }

    void Modify(Link s)/**4.修改信息程序**/
    {
        int choose4=0;/**定义选择4**/
        system("cls");/**清屏**/
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
            Sleep(800);/**延时800ms**/
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
                Sleep(800);/**延时800ms**/
                free(s);/**清空s**/
                system("cls");/**清屏**/
                Modify(s);/**返回修改函数**/
            }
            printf("\n修 改 成 功！\n\a");
            Sleep(800);/**延时800ms**/
            Modify(s);/**返回修改函数**/
            break;
        case 3:
            printf("\n请输入需要更改的院系:");
            scanf("%s",&(s->data).Department);/**输入修改的院系**/
            printf("\n修 改 成 功！\n\a");
            Sleep(800);/**延时800ms**/
            Modify(s);/**返回修改函数**/
            break;
        case 4:
            printf("\n请输入需要更改的专业:");
            scanf("%s",&(s->data).professional);/**输入修改的专业**/
            printf("\n修 改 成 功！\n\a");
            Sleep(800);/**延时800ms**/
            Modify(s);/**返回修改函数**/
            break;
        case 5:
            printf("\n请输入需要更改的班级:");
            scanf("%d",&(s->data).Class);/**输入修改的班级**/
            printf("\n修 改 成 功！\n\a");
            Sleep(800);/**延时800ms**/
            Modify(s);/**返回修改函数**/
            break;
        case 6:
            printf("\n请输入需要更改的总分:");
            scanf("%d",&(s->data).TS);/**输入修改的总分**/
            printf("\n修 改 成 功！\n\a");
            Sleep(800);/**延时800ms**/
            Modify(s);/**返回修改函数**/
            break;
        case 0:menu();break;/**返回主菜单**/
        default:
            printf("\n您输入有误!\n请重新输入\n");
            Sleep(800);/**延时800ms**/
            Modify(s);/**返回修改函数**/
        }
    }

    void Insert(void)/**5.插入函数**/
    {
        int c=0;/**插入次数判断**/
        int choose5=0;/**定义选择5**/
        if(n==0)Entry();/**如果录入人数为0进入录入函数录入信息**/
        system("cls");/** 清屏 **/
        Node *p5,*p6,*p7;/**定义两个节点**/
        while(1)/**无限循环**/
        {
            p6 = (struct node*)malloc(LEN);/**开辟空间**/
            if(p6==NULL)
            {
                printf("申请空间失败！\a\n");
                Sleep(2000);/**延时2000ms**/
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
            system("cls");/** 清屏 **/
        }
    }

    void Sorting(void)/**排序函数选择**/
    {
        int choose6=0;/**定义选择6**/
        system("cls");/**清屏**/
        printf("\t\t请输入排序方式：\n");
        printf("\t\t<1>.成绩升序    <2>.成绩降序\n");
        printf("\t\t<3>.学号升序    <4>.学号降序\n");
        printf("\t         <0>返回菜单\n\t");
        scanf("%d",&choose6);/**输入选择**/
        switch(choose6)/**选择判断**/
        {
        case 1:R_Sorting(1);break;/**判断1进入排序执行函数**/
        case 2:R_Sorting(2);break;/**判断2进入排序执行函数**/
        case 3:R_Sorting(3);break;/**判断3进入排序执行函数**/
        case 4:R_Sorting(4);break;/**判断4进入排序执行函数**/
        case 0:menu();break;/**判断0进入菜单函数**/
        default:/**输入其它选项**/
            printf("您的输入有误！\n\a");
            Sleep(800);/**延时800ms**/
            Sorting();/**返回次函数**/
        }
    }

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

    void Statistics(void)/**7.统计函数**/
    {
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
        getch();/**读取一个字符**/
        menu();/**返回主菜单**/
    }

    void display(void)/**8.显示函数**/
    {
        if(n==0)
        {
            printf("还未录入信息！\n\a");
            printf("任意键退出！\n");
            getch();/**读取一个字符**/
            menu();/**返回主菜单**/
        }
        Node *p5;/**定义一个节点**/
        p5=head->next;/**头部指向p5**/
        system("cls");
        printf("\t\t学生信息\n");
        while(p5!=NULL)/**p5不为空循环**/
        {
            Output(p5);/**输出函数**/
            printf("\t|-----------------------\n");/**输出分割线**/
            p5=p5->next;
        }
        printf("任意键退出！\n");
        getch();/**读取一个字符**/
        menu();/**返回主菜单**/
    }

    void Save(void)/**文件保存**/
    {
        Node *p;/**定义个节点**/
            p=head->next;/**令头部指向节点p**/
            FILE *fp;/**创建文件**/
            fp=fopen("xueguan.txt","w");/**打开文件**/
        while(p!=NULL)/**p不为空循环**/
        {
            fprintf(fp,"%s\t%s\t%s\t%s\t%s",p->data.ID,p->data.name,p->data.Gender,p->data.Department,p->data.professional);/**保存信息**/
            fprintf(fp,"\t%d\t%d\n",p->data.Class,p->data.TS);
            p=p->next;/**p指向下一个节点**/
        }
        fprintf(fp,"\n");/**空行结束**/
        fclose(fp);/**关闭文件**/
        B=1;/**已保存标志**/
        system("cls");/**清屏**/
        printf("保存成功！\n");
        Sleep(800);/**延时800ms**/
        menu();/**返回主菜单**/
    }

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
            Sleep(800);/**延时**/
            menu();/**返回菜单**/
        }
    }

    void hello(void)
    {
        system("cls");
        printf("\n\n\t\t\t\t------------------------------------------\n");
        printf("\t\t\t\t|*****************************************|\n");
        printf("\t\t\t\t|*        欢     迎     使     用        *|\n");/**输出界面**/
        printf("\t\t\t\t|*                                       *|\n");
        printf("\t\t\t\t|* 学   生   信   息   管   理   系   统 *|\n");
        printf("\t\t\t\t|*****************************************|\n");
        printf("\t\t\t\t------------------------------------------\n\n");
        printf("\t\t\t\t           按任意键进入系统\n");
        getch();/**读取一个字符**/
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
                    Sleep(2000);/**延时2000ms**/
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
    int main()/**主函数**/
    {
        hello();
        return 0;
    }
