#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct student)
typedef struct student
{
    int num;
    int age;
    float score;
    struct student* next;
}stu;
int n;
stu *creat(void)
{
    stu *head,*p1,*p2;
    n=0;
    p1=p2=(stu *)malloc(LEN);
    scanf("%d%d%f",&p1->num,&p1->age,&p1->score);
    head=NULL;
    while(p1->num!=0)
    {
        n++;
        if(n==1)
            head=p1;
        else
            p2->next=p1;
        p2=p1;
        p1=(stu *)malloc(LEN);
        scanf("%d%d%f",&p1->num,&p1->age,&p1->score);
    }
    p2->next=NULL;
    return head;
}
main()
{
    stu *p,*head;
    head=creat();
    p=head;
    if(head!=NULL)
    do
    {
        printf("%d,%d,%f\n",p->num,p->age,p->score);
        p=p->next;
    }while(p!=NULL);
}
