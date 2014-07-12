///////////////////////////////////////////////
//实验二
//模拟信号量的p,v操作
///////////////////////////////////////////////
#include <stdio.h>
#define MaxSize 10
typedef struct{
  char data[MaxSize];
  int front,rear;
}queue;
queue q;
int S=0;
void init()
{
  q.front=q.rear=0;
}

void in(char c)
{
  q.rear = (q.rear+1)%MaxSize;
  q.data[q.rear]=c;
  S++;
}
void out(char *c)
{
  q.front = (q.front+1)%MaxSize;
  *c=q.data[q.front];
  S--;
}
void produce(char c)
{
  if(S<9)
  {
    printf("生产了%c\n",c);
    in(c);
  }
  else
    printf("缓冲器已满，不能生产！\n");
}
void consume()
{
  if(S>0)
  {
    char c;
    out(&c);
    printf("消费了%c\n",c);
  }
  else
    printf("缓冲器已空，不能消费！\n");
}
char randCreate(int a)
{
  if(a<26)
    return a+'A';
  else
    return a+'a'-26;
}
int main()
{
  int i,op;
  srand((unsigned)time(NULL));
  while(1)
  {
    printf("请选择你要执行的操作：1.生产, 2.消费, 3.结束:");
    scanf("%d",&op);
    if(1==op)
      produce(randCreate(rand()%52));
    else if(2==op)
      consume();
    else if(3==op)
      break;
    else
      printf("输入有误！\n"); 
  }
  return 0;
}