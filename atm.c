    #include<stdio.h>
    #include<stdlib.h>
    #include<windows.h>/***清屏和延时头文件**/
    #include<string.h>/**查数函数**/
/** ********************************************************* **/
    int n=0;/**注册数量**/
    int g;/**用户标号**/
/** ********************************************************* **/
    void holle(void);/**欢迎界面**/
    void registered(void);/**账户注册界面**/
    void Login(void);/**用户登录账户判断**/
    void judge(void);/**用户登录密码判断**/
    void Service(void);/**服务界面**/
    void case1(void);/**转账业务**/
    void case2(void);/**查询业务**/
    void case3(void);/**更改密码服务**/
    void one3(void);/**更改密码密码判断**/
    void case4(void);/**存款服务**/
    void case5(void);/**取款服务**/
    void one5(int y);/**取款服务金额确认界面**/
    void Management(void);/**管理员服务**/
    void Modify(int t);/**用户信息修改界面**/
    void user1(int k);/**修改后输出界面**/
/** ********************************************************* **/
    struct user/**定义结构体**/
    {
        char Account_number[20];/**账户名**/
        int Balance;/**账户余额**/
        char Password[7];/**原始密码**/
        char state[20];/**用户状态**/
    } user[100]; /**最多可添加100人**/
/** ********************************************************* **/
    void holle(void)/**欢迎界面**/
    {
        int choose1;/**定义选择项**/
        char Employee[20] = "201710733118";/**工号**/
        char e[20];/**输入的工号**/
        system("cls");/**清屏**/
        printf("\n\n\t\t\t △▽△▽△▽△▽△▽△▽△▽△▽△▽△▽△\n");
        printf("\t\t\t□                                        □\n");/**输出欢迎使用建设银行ATM**/
        printf("\t\t\t□        欢迎使用银行自助服务系统        □\n");
        printf("\t\t\t□                                        □\n");
        printf("\t\t\t ▽△▽△▽△▽△▽△▽△▽△▽△▽△▽△▽\n");
        printf("\n\n\t\t\t\t\t<1>账户注册\n\n\t\t\t\t\t<2>账户登录\n\n\t\t\t\t\t<3>员工管理系统\n\n");/**输出执行选项**/
        scanf("%d",&choose1);/**输入选择项**/
        switch(choose1)
        {
        case 1:/**选择1**/
            registered();/**进入账户注册**/
            break;
        case 2:/**选择2**/
            Login();/**进入用户登录**/
            break;
        case 3:/**员工管理系统**/
            printf("请输入员工工号进入管理系统：");
            scanf("%s",e);
            if(strcmp(e,Employee)==0)
                Management();/**管理员服务**/
            else
            {
                printf("\n\n\t\t\t\t无效工号！！！\n\n\a");
                Sleep(800);/**延时800毫秒**/
                holle();
            }
            break;
        default:/**输入除1-3之外的数字**/
            printf("\t\t\t您的输入有误\n\t\t\t请重新输入\n\a");/**输出您的输入有误请重新输入**/
            Sleep(800);/**延时800ms**/
            holle();/**返回此函数**/
            break;
        }
    }
/** ********************************************************* **/
    void registered(void)/**账户注册**/
    {
        char mima[7];/**输入的密码**/
        int Length1;/**计数**/
        system("cls");/**清屏**/
        if(n>100)/**如果超过用户注册上限执行的程序**/
        {
            printf("\t\t***************************************\n");
            printf("\t\t*          用户注册已达上限           *\n");/**输出用户注册已达上限 请用已注册用户登录**/
            printf("\t\t*         请用已注册用户登录          *\n");
            printf("\t\t***************************************\n");
            Sleep(800);/**延时800ms**/
            holle();/**欢迎界面**/
        }
        printf("\t\t\t\t***************************************\n");
        printf("\t\t\t\t*    欢迎使用建设银行账户注册系统     *\n");/**输出欢迎使用建设银行账户注册系统**/
        printf("\t\t\t\t*     请按照要求填写信息进行注册      *\n");/**请按照要求填写信息进行注册**/
        printf("\t\t\t\t***************************************\n");
        printf("\n\t\t\t请输入真实姓名：");/**输出请输入真实姓名：**/
        scanf("%s",&user[n].Account_number);/**向Account_number赋值**/
        printf("\n\t\t\t请输入6位密码：");/**输出输入6位密码：**/
        scanf("%s",&mima);/**输入一个密码**/
        Length1=strlen(mima);/**计算除了\0外的字符数量**/
        if(Length1==6)
        {
            system("cls");/**清屏**/
            printf("\n\t\t\t\t账户注册成功!\n\a\n\t\t\t\t请重新登录\n\n");/**输出账户注册成功!请重新登录**/
            printf("\t\t\t\t账号：20170918%d  >>>>\n\n",n);
            printf("\t\t\t\t用户名：%s\n\n",user[n].Account_number);/**输出用户基本信息**/
            printf("\t\t\t\t用户类型：普通用户\n\n");
            printf("\t\t\t\t余额：%d\n\n",user[n].Balance);
            strcpy(user[n].Password,mima);/**将后面的函数值赋予前面的函数**/
            strcpy(user[n].state,"正常");/**对用户进行状态设定**/
            n++;/**用户数量编号加一**/
            Sleep(4000);/**延时4000ms**/
            holle();/**返回欢迎界面**/
        }
        else
        {
            printf("\t\t\t\t请输入6位密码\n\a");/**输出请输入6位密码**/
            Sleep(800);/**延时800ms**/
            registered();/**返回注册界面**/
        }
    }
/** ********************************************************* **/
    void Login(void)/**用户判断**/
    {
        char Lnput1[7];/**输入的密码**/
        long int number;/**输入的账号**/
        int i;/**登录用户编号**/
        printf("\t\t\t请输入账号：");/**输出请输入账号**/
        scanf("%ld",&number);/**向number赋值**/
        if(n<10)
            i=number-201709180;
        else
            i=number-2017091800;
        if(i<=n&&i>=0)
            if(strcmp("正常",user[i].state)==0)/**判断用户状态**/
            {
                g=i;/**给用户标号赋值**/
                judge();/**跳转到密码判断**/
            }

            else
            {
                system("cls");/**清屏**/
                printf("\n\n\t\t\t您的账户已锁定！\n\a\t\t\t请联系工作人员进行解锁！\n");/**您的账户已锁定！请联系工作人员进行解锁！**/
                Sleep(8000);/**延时1000ms**/
                holle();/**返回欢迎界面**/
            }
        else
        {
            printf("\t\t\t用户未注册或用户名输入错误!\a\n");
            Sleep(800);/**延时800ms**/
            holle();/**返回欢迎界面**/
        }
    }
/** ********************************************************* **/
    void judge(void)/**密码判断子函数**/
    {
        char mima1[7];
        int a = 0;/**输入密码的次数**/
        printf("\t\t\t请输入密码:");/**输出请输入密码**/
        scanf("%s",&mima1);/**输入一个密码**/
        if(strcmp(mima1,user[g].Password)==0)/**判断密码和此用户密码是否一样**/
        {
            Service();/**进入用户服务界面**/
        }
        else
        {
            for (a = 1;a <= 2;a++)/**两次循环**/
            {
                system("cls");/**清屏**/
                printf("\n\n\t\t您输入的密码错误!\n\n\a");
                printf("\t\t请重新输入!!!!\n\n\n\n");/**输出您的密码错误请重新输入，并发出警告**/
                printf("三次密码输入错误，将冻结用户\n");/**输出三次密码输入错误，将冻结用户**/
                printf("     请 输 入 密 码:    ");/**输出请输入密码**/
                scanf("%s", &mima1);/**输入密码**/

                if(strcmp(user[g].Password,mima1) == 0 )/**判断密码如果密码正确**/
                {
                    Service();/**跳入用户服务界面**/
                }

                else/**判断密码如果密码错误**/
                {
                        continue;/**结束循环**/
                }
            }
            system("cls");/**清屏**/
            printf("\t\t\t\t**********************\n");
            printf("\t\t\t\t****您的账户已冻结****\n\a");/**输出您的密码已锁定并发出警告声**/
            printf("\t\t\t\t**********************\n");
            printf("\t\t您输入密码已达最大次数，请联系工作人员进行解锁。\n");/**输出输入密码已达最大次数，请联系工作人员进行解锁。**/
            strcpy(user[n].state,"已锁定");/**对状态进行锁定**/
            Sleep(800);/**延时**/
            holle();/**跳回欢迎界面**/
        }
    }
/** ********************************************************* **/
    void Service(void)/**用户服务界面**/
    {
        int choose2 = 0;/**选择2**/
        system("cls");/**清屏**/
        printf("\n\n\n\t\t\t    请选择您要执行的业务：\n");
        printf("\t\t\t1:<转账>          \t2:<查询>\n\n");
        printf("\t\t\t3:<修改密码>      \t4:<存款>\n\n");/**输出6个任务选项供用户选择**/
        printf("\t\t\t5:<取款>          \t0:<退出>\n\n");
        printf("\t\t\t      请输入0-5进行选择：\n");
        scanf("%d", &choose2);/**输入序号**/
        switch(choose2)/**switch选择语句**/
        {
            case 1:/**输入1**/
                case1();/**进入转账界面**/
                break;
            case 2:/**输入2**/
                case2();/**进入查询页面**/
                break;
            case 3:/**输入3**/
                case3();/**进入修改密码界面**/
                break;
            case 4:/**输入4**/
                case4();/**进入存款界面**/
                break;
            case 5:/**输入5**/
                case5();/**进入取款界面**/
                break;
            case 0:/**输入0**/
                holle();/**返回主界面**/
                break;
            default:/**输入除0-5之外的数字**/
                printf("\t\t您的输入有误\n\t\t请重新输入\n");
                Sleep(800);/**延时800**/
                Service();/**跳入界用户服务面**/
                break;
         }
    }
/** ********************************************************* **/
    void case1(void)/**转账业务**/
    {
        long int number2;
        int v=0;
        int T_money;/**转账金额**/
        system("cls");
        printf("\n\n\t\t\t请输入转账账号:");
        printf("<\n\n\t\t<0>退出\n");
        scanf("%d",&number2);
        if(number2==0)
            Service();
        else
        {
            v=number2-201709180;
            if(v<=n&&v>=0)
            {
                if(v==g)/**判断是否为自己的账户**/
                {
                    printf("\t\t\t无法向自己的用户转账！\n\a");
                    Sleep(800);
                    case1();
                }
                else/**如果不是**/
                {
                    system("cls");/**清屏**/
                    printf("\n\n\t\t\t请输入转账金额:\n");
                    scanf("%d", &T_money);/**输入转账金额**/
                    if(T_money > user[g].Balance)/**判断余额是否充足**/
                    {
                        system("cls");/**清屏**/
                        printf("\n\n\t\t\t卡内余额不足\n\a");/**输出卡内余额不足，并发出警告**/
                        Sleep(800);/**延时800ms**/
                        case1();/**返回重新输入转账金额**/
                    }
                    else
                    {
                    system("cls");/**清屏**/
                    printf("\n\n\t\t\t向 %s 转账成功\n", user[v].Account_number);/**输出向x用户转账成功**/
                    Sleep(800);/**延时800ms**/
                    user[g].Balance = user[g].Balance-T_money;/**本用户余额减少**/
                    user[v].Balance = user[v].Balance+T_money;/**接收用户余额增多**/
                    Service();/**返回用户服务界面**/
                    }
                }
            }
            else
            {
                printf("您输入的账号有误！\n\n\a");
                Sleep(800);
                case1();
            }
        }
    }
/** ********************************************************* **/
    void case2(void)/**用户查询**/
    {
        int choose3;
        system("cls");/**清屏**/
        printf("\n\n\n\n\t\t\t  ~用户信息~\n");
        printf("\t\t\t账号：20170918%d  >>>>\n\n",g);/**输出账号**/
        printf("\t\t\t用 户 名：%s\n",user[g].Account_number);/**输出用户名**/
        printf("\t\t\t余 额：%d.00\n\n",user[g].Balance);/**输出余额**/
        printf("\t\t1、返回用户服务界面\n\n\t\t2、退出\n");/**输出两项选择**/
        scanf("%d",&choose3);/**输入执行的编号**/
        switch(choose3)/**switch选择语句**/
        {
        case 1:/**选择1**/
            Service();/**返用户服务界面**/
            break;
        case 2:/**选择2**/
            holle();/**返回欢迎界面**/
            break;
        default:/**输入除1-2之外的数字**/
            printf("\t\t您的输入有误\n\t\t请重新输入\n");
            Sleep(800);/**延时800**/
            case2();/**跳回查询界面**/
            break;
        }
    }
/** ********************************************************* **/
    void case3(void)/**更改密码服务密码判断**/
    {
        char Lnput3[7];/**输入的密码**/
        system("cls");/**清屏**/
        printf("\n\n\t\t\t请输入原始密码：");/**输出请输入原始密码**/
        scanf("%s", &Lnput3);/**输入密码**/
        if((Lnput3,user[g].Password)==0)/**判断密码是否正确**/
            one3();/**进入更改程序**/
        else
        {
            printf("\n\n\t\t\t原密码输入错误，请重新输入。\n\a");
            Sleep(800);/**延时800ms**/
            case3();/**返回此程序**/
        }
    }
/** ********************************************************* **/
    void one3(void)/**修改密码服务更改程序**/
    {
        char Change1[7];/**第一次输入的修改密码**/
        char Change2[7];/**第二次输入的修改密码**/
        int Length4 = 0;/**密码长度**/
        system("cls");/**清屏**/
        printf("\n\n\t\t\t请输入更改后密码：");/**输出请输入更改后密码：**/
        scanf("%s", &Change1);/**第一遍输入密码**/
        printf("\n\t\t\t请再次输入更改后密码：");/**输出请再次输入更改后密码：**/
        scanf("%s", &Change2);/**第二遍输入密码**/
        Length4=strlen(Change1);/**判断密码长度**/
        if(Length4==6)/**如果密码为6位**/
        {
            if(strcmp(Change1,Change2)==0)/**判断两次输入密码是否一样**/
            {
                if(strcmp(Change1,user[g].Password)==0)/**判断与原密码是否一样**/
                {
                    printf("\t\t更改的密码不能与原密码相同!!!\a\n");/**输出更改的密码不能与原密码相同**/
                    Sleep(800);/**延时800ms**/
                    one3();/**返回此函数**/
                }
                else/**如果不一样**/
                {
                    strcpy(user[g].Password,Change2);/**将新密码赋值**/
                    printf("\n\n\t\t\t修改密码成功\n请牢记新密码\n\a");/**输出修改密码成功请牢记新密码**/
                    Sleep(800);/**延时800ms**/
                    holle();/**返回欢迎界面**/
                }
            }
            else
            {
                system("cls");/**清屏**/
                printf("\n\n\t\t\t两次密码输入不相同\n\t\t请重新输入\n");/**输出两次密码输入不相同\请重新输入**/
                Sleep(800);/**延时800ms**/
                one3();/**返回此程序**/
            }
        }
        else
        {
            printf("请输入6位密码！\n\a");/**输出请输入6位密码！**/
            Sleep(800);/**延时800ms**/
            one3();/**返回此程序**/
        }

    }
/** ********************************************************* **/
    void case4(void)/**存款服务**/
    {
        int zhangshu1 = 0;/**存入张数**/
        int cunkuan1 = 0;/**存款**/
        system("cls");/**清屏**/
        printf("\n\n\t\t\t请将钞票整齐放入存钞口\n");/**输出请将钞票整齐放入存钞口**/
        printf("\t\t\tATM机只能识别100元钞票\n\n");/**输出ATM机只能识别100元钞票**/
        printf("\t\t\t   请勿将杂物放入\n\a");/**输出请勿将杂物放入**/
        scanf("%d", &zhangshu1);/**输入存入张数**/
        system("cls");/**清屏**/
        printf("\t\t\t100元张数；%d\n",zhangshu1);/**输出100元张数**/
        cunkuan1 = 100*zhangshu1;/**计算金额**/
        printf("\t\t\t存款金额：CNY %d\n",cunkuan1);/**输出存入金额**/
        user[g].Balance = user[g].Balance + cunkuan1;/**此账户的余额增加**/
        Sleep(800);/**延时800ms**/
        Service();/**返回用户服务界面**/
    }
/** ********************************************************* **/
    void case5(void)/**取款业务**/
    {
        int W_money;/**定义取款数目**/
        int l;/**取款数目**/
        system("cls");/**清屏**/
        printf("\n\n\n\t\t\t<1>100            \t<4>1000\n");
        printf("\t\t\t<2>200            \t<5>5000\n");
        printf("\t\t\t<3>500            \t<0>取消\n");
        printf("\t\t\t  <请输入取款数目或者选择>\n");
        scanf("%d",&W_money);/**输入取款项目或者取款数目**/
        if(W_money % 100 == 0)/**判断是否能被整除**/
            one5(W_money);/**跳入取款确认界面**/
        switch(W_money)/**当选择取款选项时**/
        {
            case 1:/**选择1**/
                l=100;/**给l复制**/
                one5(l);
                break;
            case 2:/**选择2**/
                l=200;/**给l复制**/
                one5(l);
                break;
            case 3:/**选择3**/
                l=500;/**给l复制**/
                one5(l);
                break;
            case 4:/**选择4**/
                l=1000;/**给l复制**/
                one5(l);
                break;
            case 5:/**选择5**/
                l=5000;/**给l复制**/
                one5(l);
                break;
            case 0:/**选择0**/
                Service();/**返回用户服务界面**/
                break;
            default:/**输入除0-5之外的数字**/
                printf("\n\t\t\t您的输入有误\n\t\t\t请重新输入\n");/**您的输入有误\n\t\t请重新输入**/
                Sleep(800);/**延时800ms**/
                break;
        }
    }
/** ********************************************************* **/
    void one5(int y)/**取款确认界面**/
    {
        int choose4 = 0;
        if(y > user[g].Balance)/**判断余额是否充足**/
        {
            printf("余额不足！\n\a");/**输出余额不足**/
            Sleep(800);/**延时800ms**/
            case5();/**返回转账函数**/
        }
        else
        {
            if(y > 5000)/**取款额度大于5000**/
            {
                printf("\t最大单次取款额度5000元\n\a\t请重新输入或选择取款数目\n");/**输出最大单次取款额度5000元\n\a\t请重新输入或选择取款数目**/
                Sleep(800);/**延时800ms**/
                case5();/**返回转账函数**/
            }
            printf("\t您要取款的数目为 %d 元\n",y);
            printf("\t<1>确认       <2>取消\n");
            scanf("%d",&choose4);
            switch(choose4)
            {
                case 1:/**选择1**/
                    system("cls");/**清屏**/
                    user[g].Balance =  user[g].Balance - y;/**此用户余额减少**/
                    printf("\n\n\t\t\t请收好您的钱款\n\a");/**输出请收好您的钱款**/
                    Sleep(800);/**延时800ms**/
                    Service();/**返回用户服务界面**/
                    break;
                case 2:/**选择2**/
                    case5();/**返回取款业务界面**/
                    break;
                default:
                    system("cls");/**清屏**/
                    printf("\n\n\t\t\t您的输入有误\n\t\t\t请重新输入\n");/**输出您的输入有误，请重新输入**/
                    Sleep(800);/**延时800ms**/
                    one5(y);/**返回此函数，并向其传值y**/
                    break;
            }
        }
    }
/** ********************************************************* **/
    void Management(void)/**管理员服务**/
    {
        int a;/**循环输出计数**/
        int b;/**输入选项**/
        int h;/**修改用户编号**/
        system("cls");/**清屏**/
        printf("\n\n\t\t\t账户注册数量：%d\n",n);/**输出当前已注册的用户数量**/
        printf("\t\t\t账户注册上限：100 \n");/**输出注册上限**/
        for(a=0;a<=n-1;a++)
        {
            printf("\t\t\t编号： <<<<  %d  >>>>\n",a);/**输出用户编号**/
            printf("\t\t\t账号：20170918%d  >>>>\n",a);/**输出此用户的账号**/
            printf("\t\t\t<1> 用户名：%s\n",user[a].Account_number);
            printf("\t\t\t<2> 余额：%d\n",user[a].Balance);
            printf("\t\t\t<4> 用户状态:**%s**\n",user[a].state);                   /**输出用户基本信息**/
            printf("\t\t\t<3> 用户类型：普通用户\n");
        }
        printf("\n\t\t\t<<1>>修改用户信息\t\t<<2>>退出\n");/**输出选项**/
        scanf("%d",&b);/**选择**/
        switch(b)
        {
        case 1:
            printf("\t\t\t\t请输入需要修改的用户编号：");/**输入修改的用户编号**/
            scanf("%d",&h);/**输入编号**/
            Modify(h);/**调用修改界面并向其传值**/
            break;
        case 2:
            holle();/**返回主界面**/
            break;
        default:/**输入除1-2之外的数字**/
            printf("\t\t\t您的输入有误\n\t\t\t请重新输入\n\a");/**输出您的输入有误请重新输入**/
            Sleep(800);/**延时800ms**/
            Management();
            break;
        }
    }
/** ********************************************************* **/
    void Modify(int t)/**用户信息修改界面**/
    {
        int d;
        printf("\n\n\t\t\t解除锁定请按<1>,锁定用户请按<2>\n\t\t\t\t按任意键取消修改\n\n");
        scanf("%d",&d);
        switch(d)
        {
        case 1:
            printf("\t\t\t用户状态已修改！\n");
            strcpy(user[t].state,"正常");
            Sleep(800);/**延时800ms**/
            user1(t);
            break;
        case 2:
            printf("用户状态已修改！\n");
            strcpy(user[t].state,"锁定");
            Sleep(800);/**延时800ms**/
            user1(t);
            break;
        default:/**输入除1-2之外的数字**/
            printf("\n\n\t\t\t修改已取消！\n\n\a");
            Sleep(800);/**延时800ms**/
            Management();
            break;
        }
    }
/** ********************************************************* **/
    void user1(int k)/**修改后输出界面**/
    {
        printf("\t\t\t账号：20170918%d  >>>>\n\n",k);/**输出此用户的账号**/
        printf("\t\t\t<1> 用户名：%s\n",user[k].Account_number);
        printf("\t\t\t<2> 余额：%d\n",user[k].Balance);
        printf("\t\t\t<4> 用户状态:**%s**\n",user[k].state);                   /**输出用户基本信息**/
        printf("\t\t\t<5> 用户类型：普通用户\n");
        Sleep(2000);/**延时2000ms**/
        Management();
    }
/** ********************************************************* **/
    int main()/**主函数**/
    {
        holle();/**进入欢迎界面**/
        return 0;
    }
