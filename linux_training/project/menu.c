#include"student.h"

void menu()/**主菜单**/
    {
        int choose=0;/**选择**/
	while(1)
	{
	        system("clear");/** 清屏 **/
		fflush(stdin);
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
		    sleep(1);/**延时1秒**/
		    break;
		}
	}
    }
