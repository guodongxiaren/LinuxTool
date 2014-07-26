#include<stdio.h>
#include<string.h>
int main()
{
    char s[]="welcome to mrsoft\n";
    printf("s before memset:%s\n",s);
    memset(s,'*',strlen(s)-1);
    printf("s after memset:%s\n",s);
    return 0;
}
//strlen的值包括最后的\0.所以要减去1

