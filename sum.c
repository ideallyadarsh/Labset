#include<stdio.h>
#include<stdlib.h>
int sum(int n);
int main()
{
    int a[20],n,s;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    s=sum(n);
    printf("Sum is %d",s);
    return(0);

}
int sum(int x)
{    int a[20],i,c;
c=0;
            for(i=0;i<x;i++)
    {
        printf("Enter Element %d",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<x;i++)
    {
      c+=a[i];
    }
    return(c);
}
