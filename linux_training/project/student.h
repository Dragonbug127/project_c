#ifndef NN
#define NN 
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<unistd.h>
    #define LEN sizeof(struct node)
#endif
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
    int n;/**录入的人数**/
    Node *head;/**储存头部**/
    int B;/**保存标志信息**/

