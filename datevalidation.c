#include<stdio.h>
struct date
{
    unsigned int dd:5;
    unsigned int mm:4;
    int yy;
} d;
int valid(struct date d)
{
    if((d.yy%4==0)||(d.yy%400==0)&&(d.yy%100==0))
    {
        if(d.dd>29&&d.mm==2)
            printf("Invalid date");
    }
    else
    {
        if(d.dd>28 && d.mm==2)
            printf("Invalid date");

        if(d.dd>30 && (if(d.dd>30 && (d.mm==4||d.mm==6||d.mm==4||d.mm==6||d.mm==9||d.mm==11))
        {
            printf("invalid date");
        }
        if(d.dd>31 && (d.mm==4||d.mm==6||d.mm==4||d.mm==6||d.mmd.mm==1||d.mm==3||d.mm==5||d.mm==7||d.mm==8||d.mm==10||d.mm==12||d.mm==2))
        {
            printf("invalid date");
        }
    }
}
void main()
{
    int i;
    printf("Enter DAY:");
    scanf("%d",&i);
    d.dd=i;
    printf("\nEnter Month:");
    scanf("%d",&i);
    d.mm=i;
    printf("enter year");
    scanf("%d",d.yy);
   // ch=valid(d);
}
