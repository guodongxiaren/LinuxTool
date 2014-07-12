#include <stdio.h>
#define N 5
#define M 3
int Max[N][M]={7,5,3,3,2,2,9,0,2,2,2,2,4,3,3};
int Allocation[N][M]={0,1,0,2,0,0,3,0,2,2,1,1,0,0,2};
int Need[N][M]={7,4,3,1,2,2,6,0,0,0,1,1,4,3,1};
int Available[M]={3,3,2};
void print()
{
  int i,j;
  printf("|资源情况|     Max   | Allocation|    Need   | Available |\n");
  printf("|  进程  |  A  B  C  |  A  B  C  |  A  B  C  |  A  B  C  | \n");
  
  for(i=0;i<N;i++)
  {
    printf("|   P%d   |",i);
    for(j=0;j<M;j++)
    {
      printf(" %2d",Max[i][j]);
    }
    printf("  |");
    for(j=0;j<M;j++)
    {
      printf(" %2d",Allocation[i][j]);
    }
    printf("  |");
    for(j=0;j<M;j++)
    {
      printf(" %2d",Need[i][j]);
    }
    printf("  |");
    if(i==0)
    for(j=0;j<M;j++)
    {
      printf(" %2d",Available[j]);
    }
    else
      printf("         ");
    printf("  |\n");
  }
}
//安全性算法
void security()
{
  int sq[5];
  int finish[5]={0,0,0,0,0};
  int work[3]={Available[0],Available[1],Available[2]};
  int pos=0,n=5;
  while(n--)
  {
    int i,j;
    for(i=0;i<5;i++)
    {
      if(!finish[i]&&Need[i][0]<=work[0]&&Need[i][1]<=work[1]&&Need[i][2]<=work[2])
      {
	sq[pos++]=i;
	work[0]+=Allocation[i][0];
	work[1]+=Allocation[i][1];
	work[2]+=Allocation[i][2];
	finish[i]=1;
	break;
      }
    }
    if(!n&&pos==5)
    {
      printf("安全序列为：");
      for(j=0;j<5;j++)
	printf("P%d ",sq[j]);
      printf("\n");
    }
    else if(!n)
      printf("无安全序列！\n");
  }
}
void request()
{
  int pid,req[3],i;
  printf("请输入要请求的进程号：");
  scanf("%d",&pid);
  printf("请依次输入对A，B，C三类资源的请求量：");
  scanf("%d%d%d",&req[0],&req[1],&req[2]);
  getchar();
  int ok=1;
  for(i=0;i<3;i++)
  {
    if(req[i]>Need[pid][i])
    {
      printf("错误！请求资源超过最大需求\n");
      ok=0;
      break;
    }
    if(req[i]>Available[i])
    {
      printf("资源不足，请等待！\n");
      ok=0;
      break;
    }
  }
  if(ok==1)
    for(i=0;i<3;i++)
      Allocation[pid][i]+=req[i];
}
main()
{
  char yn='y';
  print();
  security();
  while(1)
  {
    if(yn=='N'||yn=='n')
      break;
    request();
    printf("\n还要继续吗？请输入y，n:");
    scanf("%c",&yn);
  }
}