#include"student.h"
void ret(Link z,int A)/**返回函数**/
    {
        int c;
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
                sleep(1);/**延时800毫秒**/
                ret(z,A);/**返回退出函数**/
                break;
            }
        }
        else/**否则为普通退出**/
        {
            printf("按任意键返回！\n\a");
            scanf("%d",&c);
            sleep(1);/**延时800毫秒**/
            seek();/**返回查找函数**/
        }
    }
