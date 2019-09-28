#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[20],n,mid,i,e,high,low;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("enter the elements in ascending order\n");
    for(i=0;i<n;i++)
    {
        printf("Enter Element %d ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched");#
    scanf("%d",&e);
    high=n;
    low=0;

   l: mid=(low+high)/2;
    if(a[mid]==e)
    {
        printf("Element %d found at %d",e,mid+1);
        exit(0);
    }
    else if(a[mid]>e)
        {
            high=mid-1;
            goto l;
        }
    else if(a[mid]<e)
        {
            low=mid+1;
            goto l;
        }
        else
            printf("Element not found!!!");
     return(0);
}
