#include"student.h"
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
