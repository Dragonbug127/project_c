#include"student.h"
void Sorting(void)/**排序函数选择**/
    {
        int choose6=0;/**定义选择6**/
       system("clear");/**清屏**/
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
            sleep(1);/**延时800ms**/
            Sorting();/**返回次函数**/
        }
    }
