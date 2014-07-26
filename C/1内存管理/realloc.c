#include<stdio.h>
#include<stdlib.h>
main()
{
    char *p;
    p=(char *)malloc(100);
    if(p)
        printf("Memory allocated at:%x",p);
    else
        printf("Not Enought Memory!\n");
    getchar();
    p=(char *)realloc(p,256);
    if(p)
        printf("Memory reallocated at:%x",p);
    else
        printf("Not Enought Memory!\n");
    free(p);
    getchar();
    return 0;
}

