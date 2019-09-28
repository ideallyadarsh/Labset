#include <stdio.h>
#include <stdlib.h>
int sum(int a, int b);
int main()
{    int a,b,c;
    printf("Enter any two integer \n");
    scanf("%d %d",&a,&b);
    c=sum(a,b);
    printf("sum of %d & %d is:%d",a,b,c);
    return(0);
}
int sum(int x,int y)
{
    int d;
    d=x+y;
    return(d);
}
