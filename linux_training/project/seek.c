#include"student.h"
void seek(void)/**2.查找学生信息界面**/
    {
        int choose2=0;
       system("clear");/** 清屏 **/
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
            sleep(1);
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
            sleep(1);/**延时800毫秒**/
            seek();/**进入查找函数**/
            break;
        }
    }
