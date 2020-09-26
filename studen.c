    #include<stdio.h>
    #include<stdlib.h>
    #include<conio.h>/**getchͷ�ļ�**/
    #include<string.h>
    #include<windows.h>
    #define LEN sizeof(struct node)
    ///����
    typedef struct student/**����ѧ�������Ϣ�Ľṹ�壬���Ϊstudent**/
    {
        char ID[15];/**ѧ��**/
        char name[15];/**����**/
        char Gender[5];/**�Ա�**/
        char Department[20];/**Ժϵ**/
        char professional[50];/**רҵ**/
        int Class;/**�༶**/
        int TS;/**�ܷ�**/
    }STU;
    typedef struct node/**����ÿ����¼�Ľṹ�壬���Ϊnode**/
    {
        STU data;/**������**/
        struct node *next;/**ָ����**/
    }Node,*Link;
    ///ȫ�ֱ���
    int n=0;/**¼�������**/
    Node *head;/**����ͷ��**/
    int B;/**�����־��Ϣ**/
    ///�Զ��庯��
    void hello(void);/**��ӭ����**/
    void menu(void);/**���˵�����**/
    void Entry(void);/**1.������Ϣ����**/
    void Insert(void);/**2.���뺯��**/
    void Delete(void);/**3.ɾ����Ϣ**/
    void Modify(Link s);/**4.�޸Ľ���**/
    void Statistics(void);/**5.ͳ�ƺ���**/
    void Sorting(void);/**6.������**/
    void R_Sorting(int y);/**6.1����������**/
    void seek(void);/**7��ѯ��Ϣ����**/
    void seek1(int A);/**7.1ѧ�Ų�ѯ����**/
    void seek2(int x);/**7.2��ѯ����**/
    void ret(Link z,int A);/**7.3��ѯ���˳�����**/
    void display(void);/**8.��ʾ����**/
    void Save(void);/**9.���溯��**/
    void retreat(void);/**�˳�����**/
    void Output(Link l);/**�����Ϣ����**/

    void menu()/**���˵�**/
    {
        int choose=0;/**ѡ��**/
        system("cls");/** ���� **/
        printf("\t\t\t            <<<<ѧ���ɼ�����ϵͳ>>>>           \n");
        printf("\t\t\t                    ���˵�                     \n\n");
        printf("\t\t\t-----------------------------------------------\n");
        printf("\t\t\t|*********************************************|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*     1 ¼����Ϣ            2 ������Ϣ      *|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*     3 ɾ����Ϣ            4 �޸���Ϣ      *|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*     5 ͳ����Ϣ            6 ������Ϣ      *|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*     7 ������Ϣ            8 ��ʾ��Ϣ      *|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*     9 ������Ϣ            0 �˳�ϵͳ      *|\n");
        printf("\t\t\t|*                                           *|\n");
        printf("\t\t\t|*********************************************|\n");
        printf("\t\t\t-----------------------------------------------\n");
        scanf("%d",&choose);/**����ѡ��**/
        switch(choose)/**ѡ���ж�**/
        {
        case 1:Entry();break;/**����¼�뺯��**/
        case 2:Insert();break;/**������뺯��**/
        case 3:Delete();break;/**����ɾ������**/
        case 4:seek1(1);break;/**�����ѯ1ѧ�Ų��Һ���**/
        case 5:Statistics();break;/**����ͳ�ƺ���**/
        case 6:Sorting();break;/**����������**/
        case 7:seek();break;/**������Һ���**/
        case 8:display();break;/**������ʾ����**/
        case 9:Save();break;/**���뱣�溯��**/
        case 0:retreat();break;/**�����˳�����**/
        default:
            printf("\t�����������������룡\n\a");
            Sleep(800);/**����800����**/
            menu();/**����������**/
            break;
        }
    }

    void Entry(void)/**1.����ѧ����Ϣ**/
    {
        int choose1=0;/**ѡ��1**/
        if(n>0)Insert();/**���ע����������0������뺯��**/
        system("cls");/** ���� **/
        struct node*Head;/**����ͷ��**/
        Node *p1,*p2;/**���������ڵ�**/
        Head = (struct node*)malloc(LEN);/**��ͷ�����ٿռ�**/
        head = Head;/**����ͷ��**/

        while(1)/**����ѭ��**/
        {
            p2 = (struct node*)malloc(LEN);/**����һ���ռ�**/
            if(p2==NULL)
            {
                printf("����ռ�ʧ�ܣ�\a\n");
                Sleep(2000);/**��ʱ2000ms**/
                p1->next=NULL;/**p2ָ��ս�������**/
                menu();/**�������˵�����**/
            }
            printf("\t1.������ѧ��:");
            scanf("%s",&(p2->data).ID);/**����ѧ��**/
            printf("\t2.����������:");
            scanf("%s",&(p2->data).name);/**��������**/
            printf("\t3.�������Ա�:");
            scanf("%s",&(p2->data).Gender);/**�����Ա�**/
            printf("\t4.������Ժϵ:");
            scanf("%s",&(p2->data).Department);/**����Ժϵ**/
            printf("\t5.������רҵ:");
            scanf("%s",&(p2->data).professional);/**����רҵ**/
            printf("\t6.������༶:");
            scanf("%d",&(p2->data).Class);/**����༶**/
            printf("\t7.�������ܷ�:");
            scanf("%d",&(p2->data).TS);/**�����ܷ�**/
            n++;/**ѧ����������**/
            if(n==1) Head->next = p2;/**���ͷ��βָ�����ʹͷ��βָ��p3ͷ**/
            else p1->next=p2;/**����ʹp1��βָ��p2��ͷ**/
            p1=p2;/**��p1����p2**/
            printf("\t����¼���밴0\n\t���������������");
            scanf("%d",&choose1);/**����ѡ��**/
            if(choose1==0)/**����Ϊ0 **/
            {
                p1->next=NULL;
                p2->next=NULL;/**ʹ���һ����βָ���**/
                menu();/**�������˵�����**/
            }
            system("cls");/** ���� **/
        }
    }

    void seek(void)/**2.����ѧ����Ϣ����**/
    {
        int choose2=0;
        system("cls");/** ���� **/
        printf("\t\t\t�� ѯ �� ʽ ѡ ��\n");
        printf("\t\t\t  <1> ѧ  ��     \n");
        printf("\t\t\t  <2> ��  ��     \n");/**�����ѯ��ʽ**/
        printf("\t\t\t  <3> ר  ҵ     \n");
        printf("\t\t\t  <4> ��  ��     \n");
        printf("\t\t\t  <5> Ժ  ϵ     \n");
        printf("\t\t\t  <0> ��  ��     \n");
        scanf("%d",&choose2);/**����ѡ��2**/
        if(n==0)
        {
            printf("��δ¼�����Ϣ�޷���ѯ��\n\a");
            Sleep(800);
            menu();
        }
        switch(choose2)/**�ж�ѡ��2**/
        {
        case 0:menu();break;/**�������˵�����**/
        case 1:seek1(0);break;/**�����ѯ1����**/
        case 2:seek2(2);break;/**�����ѯ2����**/
        case 3:seek2(3);break;/**�����ѯ4����**/
        case 4:seek2(4);break;/**�����ѯ5����**/
        case 5:seek2(5);break;/**�����ѯ6����**/
        default:
            printf("\t�����������������룡\n\a");
            Sleep(800);/**��ʱ800����**/
            seek();/**������Һ���**/
            break;
        }
    }

    void seek1(int A)/**2.1ѧ�Ų�ѯ����**/
    {
        Node *p3,*p4;/**���������ڵ�**/
        p3=head->next;/**ʹp3Ϊ��һ����Ԫ**/
        int m=0;/**���ҳɹ���־��Ϣ**/
        char xuehao[15];/**�����ѧ��**/
        system("cls");/**����**/
        printf("\t��������Ҫ��ѯ��ѧ�ţ�");
        scanf("%s",xuehao);/**����ѧ��**/
        while(p3!=NULL)/**p3��Ϊ��ѭ��**/
        {
            if(strcmp(xuehao,(p3->data).ID)==0)/**���ѧ����ͬ**/
            {
                m=1;/**���ҳɹ�**/
                p4=p3;/**�����ʱ��p3**/
                Output(p3);/**���p3**/
            }
            p3=p3->next;/**p3ָ����һλ�ڵ�*/
        }
        if(m==1) ret(p4,A);/**�����ѯ�����뷵�ؽ��棬�����ڵ�p4**/
        else/**����**/
        {
            printf("\n\n\t\t\t\tδ���ҵ�ѧ����Ϣ\n");
            ret(p4,A);/**���ﷵ�ؽ���**/
        }
    }

    void seek2(int x)/**2.2������ѯ����**/
    {
        Node *p3;
        p3=head->next;
        int m=0;/**���ҳɹ���־��Ϣ**/
        char xm[15];/**���������**/
        char zhuanye[20];/**�����רҵ*/
        int banj;/**����İ༶**/
        char yuanx[20];/**�����Ժϵ**/
        system("cls");/**����**/
        switch(x)
        {
        case 2:
            printf("\t��������Ҫ��ѯ��������");
            scanf("%s",&xm);
            break;
        case 3:
            printf("\t��������Ҫ��ѯ��רҵ��");
            scanf("%s",&zhuanye);
            break;
        case 4:
            printf("\t��������Ҫ��ѯ�İ༶��");
            scanf("%d",&banj);
            break;
        case 5:
            printf("\t��������Ҫ��ѯ��Ժϵ��");
            scanf("%s",&yuanx);
            break;
        }
        while(p3!=NULL)/**p3��Ϊ��ѭ��**/
        {
            if(x==2)
            {
                if(strcmp(xm,(p3->data).name)==0)/**���������ͬ**/
                {
                    m=1;/**���ҳɹ�**/
                    Output(p3);/**���p3**/
                }
            }
            else if(x==3)
            {
                if(strcmp(zhuanye,(p3->data).professional)==0)
                {
                    m=1;/**���ҳɹ�**/
                    Output(p3);/**���p3**/
                }
            }
            else if(x==4)
            {
                if(banj==(p3->data).Class)
                {
                    m=1;/**���ҳɹ�**/
                    Output(p3);/**���p3**/
                }
            }
            else
            {
                if(strcmp(yuanx,(p3->data).Department)==0)
                {
                    m=1;/**���ҳɹ�**/
                    Output(p3);/**���p3**/
                }
            }
            p3=p3->next;/**p3ָ����һ�ڵ�**/
        }
        if(m==1) ret(p3,0);/**�����ѯ�����뷵�ؽ��棬�����ڵ�p3**/
        else/**����**/
        {
            printf("\n\n\t\t\t\tδ���ҵ�ѧ����Ϣ\n");
            ret(p3,0);/**���뷵�ؽ��棬�����ڵ�p4**/
        }
    }

    void Output(Link l)/**2.6�����Ϣ����**/
    {
        printf("\tѧ �ţ�%s\n",(l->data).ID);/**���ѧ��**/
        printf("\t�� ����%s\n",(l->data).name);/**�������**/
        printf("\t�� ��%s\n",(l->data).Gender);/**����Ա�**/
        printf("\tԺ ϵ��%s\n",(l->data).Department);/**���Ժϵ**/
        printf("\tר ҵ��%s\n",(l->data).professional);/**���רҵ**/
        printf("\t�� ����%d\n",(l->data).Class);/**����༶**/
        printf("\t�� �֣�%d\n\n",(l->data).TS);/**����ܷ�**/
    }

    void ret(Link z,int A)/**���غ���**/
    {
        int choose4=0;
        if(A==1)/**A����1ʱΪ�޸�**/
        {
            printf("1.�޸�ѧ����Ϣ\n2.�˳�");
            scanf("%d",&choose4);/**����ѡ��4**/
            switch(choose4)/**�ж�ѡ��4**/
            {
            case 1:Modify(z);break;/**�����޸Ľ���**/
            case 2:
                menu();/**�������˵�**/
                break;/**���ز˵�����**/
            default:
                printf("�������������������룡\n\a");
                Sleep(800);/**��ʱ800����**/
                ret(z,A);/**�����˳�����**/
                break;
            }
        }
        else/**����Ϊ��ͨ�˳�**/
        {
            printf("����������أ�\n\a");
            getch();/**��ȡһ���ַ�**/
            Sleep(800);/**��ʱ800����**/
            seek();/**���ز��Һ���**/
        }
    }

    void Delete()/**3.ɾ����Ϣ**/
    {
        Node *d1,*d2;/**���������ڵ�**/
        char xuehao[15];/**����ѧ��**/
        int m = 0 ;/**���ҳɹ���־��Ϣ**/
        d1=head;/**ͷָ��d1**/
        printf("������Ҫɾ����ѧ��ѧ��:");
        scanf("%s",&xuehao);/**����ѧ��**/
        while(d1->next!=NULL)/**ֱ��d1ָ���ֹͣѭ��**/
            {
                if(strcmp(xuehao,(d1->next->data).ID) == 0)/**���ѧ����ͬ**/
                {
                    m = 1;/**���ҳɹ���־��Ϣ**/
                    printf("\tѧ   �ţ�%s\n",(d1->next->data).ID);/**���ѧ��**/
                    printf("\t��   ����%s\n",(d1->next->data).name);/**�������**/
                    printf("\t��   ��%s\n",(d1->next->data).Gender);/**����Ա�**/
                    printf("\tԺ   ϵ��%s\n",(d1->next->data).Department);/**���Ժϵ**/
                    printf("\tר   ҵ��%s\n",(d1->next->data).professional);/**���רҵ**/
                    printf("\t��   ����%d\n",(d1->next->data).Class);/**����༶**/
                    printf("\t��   �֣�%d\n",(d1->next->data).TS);/**����ܷ�**/
                    d2 = d1->next;/**d2����ɾ����λ��**/
                    d1->next = d2->next;/**d1ָ��d2����һλ**/
                    free(d2);/**ɾ��d2**/
                    printf("ɾ���С�������\n\a");
                    Sleep(500);/**��ʱ500ms**/
                    system("cls");
                    printf("ɾ���ɹ�\n\a");
                    n--;
                    Sleep(800);/**��ʱ800ms**/

                }
                d1=d1->next;/**d1ָ����һλ**/
            }
        if(m==1)/**���mΪ1**/
        {
            menu();/**�������˵�**/
        }
        else
        {
            printf("��ѯ��Ч����\n");
            Sleep(800);/**��ʱ800ms**/
            menu();/**�������˵�**/
        }
    }

    void Modify(Link s)/**4.�޸���Ϣ����**/
    {
        int choose4=0;/**����ѡ��4**/
        system("cls");/**����**/
        int x=0;/**�����Ա�ѡ��**/
        printf("\t  ѧ   �ţ�%s�������޸ģ�\n",(s->data).ID);/**���ѧ��**/
        printf("\t1.��   ����%s\n",(s->data).name);/**�������**/
        printf("\t2.��   ��%s\n",(s->data).Gender);/**����Ա�**/
        printf("\t3.Ժ   ϵ��%s\n",(s->data).Department);/**���Ժϵ**/
        printf("\t4.ר   ҵ��%s\n",(s->data).professional);/**���רҵ**/
        printf("\t5.��   ����%d\n",(s->data).Class);/**����༶**/
        printf("\t6.��   �֣�%d\n",(s->data).TS);/**����ܷ�**/
        printf("\t0.��   ��\n");
        printf("��������Ҫ�޸ĵ���Ŀ:");
        scanf("%d",&choose4);/**����ѡ��4**/
        switch(choose4)/**�ж�ѡ��5**/
        {
        case 1:
            printf("\n��������Ҫ���ĵ�����:");
            scanf("%s",&(s->data).name);/**�����޸�������**/
            printf("\n�� �� �� ����\n\a");
            Sleep(800);/**��ʱ800ms**/
            Modify(s);/**�����޸ĺ���**/
            break;
        case 2:
            printf("\t3.��ѡ���Ա�:1��  2Ů\n");
            scanf("%d",&x);/**����ѡ��**/
            if(x==1) strcpy((s->data).Gender,"��");/**����1��Ϊ��**/
            else if(x==2) strcpy((s->data).Gender,"Ů");/**����2��ΪŮ**/
            else/**����**/
            {
                printf("\n������������������\n\a");
                Sleep(800);/**��ʱ800ms**/
                free(s);/**���s**/
                system("cls");/**����**/
                Modify(s);/**�����޸ĺ���**/
            }
            printf("\n�� �� �� ����\n\a");
            Sleep(800);/**��ʱ800ms**/
            Modify(s);/**�����޸ĺ���**/
            break;
        case 3:
            printf("\n��������Ҫ���ĵ�Ժϵ:");
            scanf("%s",&(s->data).Department);/**�����޸ĵ�Ժϵ**/
            printf("\n�� �� �� ����\n\a");
            Sleep(800);/**��ʱ800ms**/
            Modify(s);/**�����޸ĺ���**/
            break;
        case 4:
            printf("\n��������Ҫ���ĵ�רҵ:");
            scanf("%s",&(s->data).professional);/**�����޸ĵ�רҵ**/
            printf("\n�� �� �� ����\n\a");
            Sleep(800);/**��ʱ800ms**/
            Modify(s);/**�����޸ĺ���**/
            break;
        case 5:
            printf("\n��������Ҫ���ĵİ༶:");
            scanf("%d",&(s->data).Class);/**�����޸ĵİ༶**/
            printf("\n�� �� �� ����\n\a");
            Sleep(800);/**��ʱ800ms**/
            Modify(s);/**�����޸ĺ���**/
            break;
        case 6:
            printf("\n��������Ҫ���ĵ��ܷ�:");
            scanf("%d",&(s->data).TS);/**�����޸ĵ��ܷ�**/
            printf("\n�� �� �� ����\n\a");
            Sleep(800);/**��ʱ800ms**/
            Modify(s);/**�����޸ĺ���**/
            break;
        case 0:menu();break;/**�������˵�**/
        default:
            printf("\n����������!\n����������\n");
            Sleep(800);/**��ʱ800ms**/
            Modify(s);/**�����޸ĺ���**/
        }
    }

    void Insert(void)/**5.���뺯��**/
    {
        int c=0;/**��������ж�**/
        int choose5=0;/**����ѡ��5**/
        if(n==0)Entry();/**���¼������Ϊ0����¼�뺯��¼����Ϣ**/
        system("cls");/** ���� **/
        Node *p5,*p6,*p7;/**���������ڵ�**/
        while(1)/**����ѭ��**/
        {
            p6 = (struct node*)malloc(LEN);/**���ٿռ�**/
            if(p6==NULL)
            {
                printf("����ռ�ʧ�ܣ�\a\n");
                Sleep(2000);/**��ʱ2000ms**/
                p7->next=NULL;/**p2ָ��ս�������**/
                menu();/**�������˵�����**/
            }
            printf("\t1.������ѧ��:");
            scanf("%s",&(p6->data).ID);/**����ѧ��**/
            printf("\t2.����������:");
            scanf("%s",&(p6->data).name);/**��������**/
            printf("\t3.��ѡ���Ա�:");
            scanf("%s",&(p6->data).Gender);/**�����Ա�*/
            printf("\t4.������Ժϵ:");
            scanf("%s",&(p6->data).Department);/**����Ժϵ**/
            printf("\t5.������רҵ:");
            scanf("%s",&(p6->data).professional);/**����רҵ**/
            printf("\t6.������༶:");
            scanf("%d",&(p6->data).Class);/**����༶**/
            printf("\t7.�������ܷ�:");
            scanf("%d",&(p6->data).TS);/**�����ܷ�**/
            n++;/**������һ**/
            c++;/**����������һ**/
            if(c==1) p5=p6;/**����p6**/
            else p7->next=p6;/**���ͷ��βָ�����ʹͷ��βָ��p3ͷ**/
            p7=p6;/**��p7����p6**/
            printf("\t����¼���밴0\n\t���������������\n");
            scanf("%d",&choose5);/**����һ���ַ�**/
            if(choose5==0)/**���ѡ��0**/
            {
                p6->next = head->next->next;/**p6�ڵ�ָ��ԭ���ĵڶ�λ�ڵ�**/
                head->next->next = p5;/**��һλ�ڵ�ָ��p5**/
                B=0;
                menu();/**�������˵�**/
            }
            p6=p6->next;/**p6ָ����һ�ڵ�**/
            system("cls");/** ���� **/
        }
    }

    void Sorting(void)/**������ѡ��**/
    {
        int choose6=0;/**����ѡ��6**/
        system("cls");/**����**/
        printf("\t\t����������ʽ��\n");
        printf("\t\t<1>.�ɼ�����    <2>.�ɼ�����\n");
        printf("\t\t<3>.ѧ������    <4>.ѧ�Ž���\n");
        printf("\t         <0>���ز˵�\n\t");
        scanf("%d",&choose6);/**����ѡ��**/
        switch(choose6)/**ѡ���ж�**/
        {
        case 1:R_Sorting(1);break;/**�ж�1��������ִ�к���**/
        case 2:R_Sorting(2);break;/**�ж�2��������ִ�к���**/
        case 3:R_Sorting(3);break;/**�ж�3��������ִ�к���**/
        case 4:R_Sorting(4);break;/**�ж�4��������ִ�к���**/
        case 0:menu();break;/**�ж�0����˵�����**/
        default:/**��������ѡ��**/
            printf("������������\n\a");
            Sleep(800);/**��ʱ800ms**/
            Sorting();/**���شκ���**/
        }
    }

    void R_Sorting(int y)/**����ִ�к���**/
    {
        Node *x1,*x2,*x;/**���������ڵ�**/
        x1=head->next;/**ͷ��ָ��x1**/
        if(y==1||y==3)
        {
            for(;x1!=NULL;x1=x1->next)/**x1��Ϊ��ѭ��**/
            {
                x2=head->next;/**ͷ��ָ��x2**/
                for(;x2!=NULL;x2=x2->next)/**x��Ϊ��ѭ��**/
                {
                    if(y==1)
                    {
                        if(x1->data.TS < x2->data.TS)/**���x1���ִܷ���x2���ܷ�**/
                        {
                            x=(struct node*)malloc(LEN);/**��x����һ���ռ�**/
                            x->data = x1->data;
                            x1->data = x2->data;/**ͨ���м���xʵ��x1��x2��λ**/
                            x2->data = x->data;
                            free(x);/**�ͷ�x**/
                        }
                    }
                    else
                    {
                        if(strcmp((x1->data).ID,(x2->data).ID) < 0)/**���x1���ִܷ���x2���ܷ�**/
                        {
                            x=(struct node*)malloc(LEN);/**��x����һ���ռ�**/
                            x->data = x1->data;
                            x1->data = x2->data;/**ͨ���м���xʵ��x1��x2��λ**/
                            x2->data = x->data;
                            free(x);/**�ͷ�x**/
                        }
                    }
                }
            }
        }
        else
        {
            for(;x1!=NULL;x1=x1->next)/**x1��Ϊ��ѭ��**/
            {
                x2=head->next;/**ͷ��ָ��x2**/
                for(;x2!=NULL;x2=x2->next)/**x��Ϊ��ѭ��**/
                {
                    if(y==1)
                    {
                        if(x1->data.TS > x2->data.TS)/**���x1���ִܷ���x2���ܷ�**/
                        {
                            x=(struct node*)malloc(LEN);/**��x����һ���ռ�**/
                            x->data = x1->data;
                            x1->data = x2->data;/**ͨ���м���xʵ��x1��x2��λ**/
                            x2->data = x->data;
                            free(x);/**�ͷ�x**/
                        }
                    }
                    else
                    {
                        if(strcmp((x1->data).ID,(x2->data).ID) > 0)/**���x1���ִܷ���x2���ܷ�**/
                        {
                            x=(struct node*)malloc(LEN);/**��x����һ���ռ�**/
                            x->data = x1->data;
                            x1->data = x2->data;/**ͨ���м���xʵ��x1��x2��λ**/
                            x2->data = x->data;
                            free(x);/**�ͷ�x**/
                        }
                    }
                }
            }
        }
        display();/**������ʾ����**/
    }

    void Statistics(void)/**7.ͳ�ƺ���**/
    {
        Node *p4;/**����һ���ڵ�**/
        int x[2]={0};/**��¼����Ů������**/
        int b[10]={0};/**��¼��������**/
        int c=0;/**ѭ������**/
        p4=head->next;/**ͷ��ָ��p4**/
        while(p4!=NULL)/**p4��Ϊ��ѭ��**/
        {
            b[(p4->data).Class-1]++;/**�༶��һ**/
            if(strcmp((p4->data).Gender,"��")==0) x[0]++;/**����������һ**/
            if(strcmp((p4->data).Gender,"Ů")==0) x[1]++;/**Ů��������һ**/
            p4=p4->next;/**p4ָ����һ�ڵ�**/
        }
        printf("\t¼������Ϊ:%d\n",n);/**���������**/
        printf("\t��������Ϊ:%d\n",x[0]);/**�����������**/
        printf("\tŮ������Ϊ:%d\n",x[1]);/**���Ů������**/
        for(c=0;c<10;c++)/**ѭ��10��**/
        {
            if(b[c]!=0) printf("\t%d�������Ϊ%d\n",c+1,b[c]);/**����༶�Լ�����**/
            else  continue;/**û�н���ѭ��**/
        }
        printf("������˳���\n");
        getch();/**��ȡһ���ַ�**/
        menu();/**�������˵�**/
    }

    void display(void)/**8.��ʾ����**/
    {
        if(n==0)
        {
            printf("��δ¼����Ϣ��\n\a");
            printf("������˳���\n");
            getch();/**��ȡһ���ַ�**/
            menu();/**�������˵�**/
        }
        Node *p5;/**����һ���ڵ�**/
        p5=head->next;/**ͷ��ָ��p5**/
        system("cls");
        printf("\t\tѧ����Ϣ\n");
        while(p5!=NULL)/**p5��Ϊ��ѭ��**/
        {
            Output(p5);/**�������**/
            printf("\t|-----------------------\n");/**����ָ���**/
            p5=p5->next;
        }
        printf("������˳���\n");
        getch();/**��ȡһ���ַ�**/
        menu();/**�������˵�**/
    }

    void Save(void)/**�ļ�����**/
    {
        Node *p;/**������ڵ�**/
            p=head->next;/**��ͷ��ָ��ڵ�p**/
            FILE *fp;/**�����ļ�**/
            fp=fopen("xueguan.txt","w");/**���ļ�**/
        while(p!=NULL)/**p��Ϊ��ѭ��**/
        {
            fprintf(fp,"%s\t%s\t%s\t%s\t%s",p->data.ID,p->data.name,p->data.Gender,p->data.Department,p->data.professional);/**������Ϣ**/
            fprintf(fp,"\t%d\t%d\n",p->data.Class,p->data.TS);
            p=p->next;/**pָ����һ���ڵ�**/
        }
        fprintf(fp,"\n");/**���н���**/
        fclose(fp);/**�ر��ļ�**/
        B=1;/**�ѱ����־**/
        system("cls");/**����**/
        printf("����ɹ���\n");
        Sleep(800);/**��ʱ800ms**/
        menu();/**�������˵�**/
    }

    void retreat()/**�˳�����**/
    {
        Node *p,*q;/**����һ���ڵ�**/
        q=p=head->next;/**q,p�ڵ��ͷ��ʼ**/
        if(B==1)/**�ѱ���**/
        {
            n=0;
            B=0;
            while(q!=NULL)/**q��Ϊ��ѭ��**/
            {
                p=q->next;/**pΪq����һλ**/
                free(q);/**ɾ��q**/
                q=p;/**q����p**/
            }
            free(head);/**���head**/
            hello();/**����������**/
        }
        else/**δ����**/
        {
            printf("\t��¼�����Ϣ��δ�����뱣����˳���\n\a");
            Sleep(800);/**��ʱ**/
            menu();/**���ز˵�**/
        }
    }

    void hello(void)
    {
        system("cls");
        printf("\n\n\t\t\t\t------------------------------------------\n");
        printf("\t\t\t\t|*****************************************|\n");
        printf("\t\t\t\t|*        ��     ӭ     ʹ     ��        *|\n");/**�������**/
        printf("\t\t\t\t|*                                       *|\n");
        printf("\t\t\t\t|* ѧ   ��   ��   Ϣ   ��   ��   ϵ   ͳ *|\n");
        printf("\t\t\t\t|*****************************************|\n");
        printf("\t\t\t\t------------------------------------------\n\n");
        printf("\t\t\t\t           �����������ϵͳ\n");
        getch();/**��ȡһ���ַ�**/
        FILE *w= fopen("xueguan.txt","r");/**���ļ�**/
        if(w==NULL) menu();/**�ļ�Ϊ�ս������˵�**/
        else/**����ļ��е���Ϣ**/
        {
            struct node*Head;/**����ͷ��**/
            Head = (struct node*)malloc(LEN);/**��ͷ������һ���ռ�**/
            Node *p,*q;/**����һ���ڵ�**/
            head=Head;/**����ͷ��**/
            while(!feof(w))/**����ļ�û�н�����ѭ��**/
            {
                p = (Node*)malloc(sizeof(Node));/**�����¿ռ�**/
                if(p==NULL)
                {
                    printf("����ռ�ʧ�ܣ�\a\n");
                    Sleep(2000);/**��ʱ2000ms**/
                    hello();/**��ӭ����**/
                }
                fscanf(w,"%s\t%s\t%s\t%s\t%s",&(p->data).ID,&(p->data).name,&(p->data).Gender,&(p->data).Department,&(p->data).professional);/**���ѧ�ţ����֣��Ա�Ժϵ��רҵ**/
                fscanf(w,"\t%d\t%d\n",&(p->data).Class,&(p->data).TS);/**����༶���ܷ�**/
                n++;/**¼��������¼**/
                if(n==1) Head->next = p;/**���Ϊ��һ����Ϣ����ͷ��ָ������ڵ�**/
                else q->next=p;/**�����Ϊ��һ��������ǰһ���ڵ�ָ��ڵ�**/
                q=p;/**����һ���ڵ�**/
                q->next=NULL;/**��˽ڵ�ָ���**/
            }
            fclose(w);/**�ر��ļ�**/
            menu();/**�������˵�**/
        }
    }
    int main()/**������**/
    {
        hello();
        return 0;
    }
