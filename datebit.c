#include<stdio.h>
struct date
{
    unsigned int dd:5;
    unsigned int mm:4;
    int yy;
} d;

void main()
{
    int i;
    printf("Enter DAY:");
    scanf("%d",&i);
    d.dd=i;
    printf("\nEnter Month:");
    scanf("%d",&i);
    d.mm=i;

    printf("\nEnter Year:");
    scanf("%d",&d.yy);
    printf("\nPresent Date:%d/%d/%d\t\t",d.dd,d.mm,d.yy);
    if(d.mm==1||d.mm==3||d.mm==5||d.mm==7||d.mm==8||d.mm==10||d.mm==12)
    {
        if(d.dd<31)
            d.dd++;
        if((d.mm==12)&&(d.dd==31))
        { d.dd=1;
         d.yy++;
         d.mm=1;
        }
    }
if(d.mm==4||d.mm==6||d.mm==9||d.mm==11)
    {
        if(d.dd<31)
            d.dd++;
        else
           {

            d.dd=1;
            d.mm++;}
    }
    if(d.mm==2)
    {
        d.mm++;
    }
printf("Next Date:%d/%d/%d",d.dd,d.mm,d.yy);
printf("\nSize:%d",sizeof(d));
}
