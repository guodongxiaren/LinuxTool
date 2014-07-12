/**/
#include <stdio.h>
#include <string.h>
typedef struct
{
  char id[10];
  double arrivetime;
  double servicetime;
}process;
process p[100];
sort(int n)
{
  char *s;
  double d;
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n-i-1;j++)
    {
      if(p[j].arrivetime>p[j+1].arrivetime)
      {
	strcpy(s,p[j].id);
	strcpy(p[j].id,p[j+1].id);
	strcpy(p[j+1].id,s);
	d=p[j].arrivetime;
	p[j].arrivetime=p[j+1].arrivetime;
	p[j+1].arrivetime=d;
	d=p[j].servicetime;
	p[j].servicetime=p[j+1].servicetime;
	p[j+1].servicetime=d;
      }
    }
}
int main()
{
  int n,i;
  double zhou[100];
  double  wz[100];
  double time=0;
  printf("请输入进程的数量：");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("请输入进程名，到达时间，服务时间：");
    scanf("%s%lf%lf",p[i].id,&p[i].arrivetime,&p[i].servicetime);
  }
  sort(n);
  
  for(i=0;i<n;i++)
  {
    time+=p[i].servicetime;
    zhou[i]=time-p[i].arrivetime;
    if(time<p[i+1].arrivetime)
     time=p[i+1].arrivetime;
  }
  for(i=0;i<n;i++)
    wz[i]=zhou[i]/p[i].servicetime;
  for(i=0;i<n;i++)
  {
    printf("%s %lf %lf\n",p[i].id,zhou[i],wz[i]);
  }
  return 0;
}