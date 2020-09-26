#include"student.h"
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
       system("clear");/**清屏**/
        printf("保存成功！\n");
        sleep(1);/**延时800ms**/
        menu();/**返回主菜单**/
    }
