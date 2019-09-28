#include<stdio.h>
struct date
{
    int day,mm,yy;
} d1,d,d2;
void main()
{int r,m;
    printf("Enter day,month,year\n");
    scanf("%d %d %d",&d.day,&d.mm,&d.yy);
    d1.day=d.day+45;
    if(d.mm==1||d.mm==3||d.mm==5||d.mm==7||d.mm==8||d.mm==10||d.mm==12)
    {
        d2.day=d1.day-31;
        d.mm++;
        if(d2.day>29)
        {
            d2.day=d2.day-30;
            d.mm++;
        }

        if(d.mm>11)
        {
            d.mm=d.mm-12;
            d.yy++;
        }
    }
    if(d.mm==4||d.mm==6||d.mm==9||d.mm==11)
    {
        d2.day=d1.day-30;
        d.mm++;

        if(d2.day>29)
        {
            d2.day=d2.day-31;
            d.mm++;
        }
        if(d.mm>11)
        {

            d.mm=d.mm-12;
            d.yy++;

        }
    }
    if(d.mm==2)
    {
        if(d.yy%4==0)
        {
         d2.day=d1.day-29;
        d.mm++;

        if(d2.day>29)
        {
            d2.day=d2.day-31;
            d.mm++;
        }
        }
        else
        {
         d2.day=d1.day-28;
        d.mm++;

        if(d2.day>29)
        {
            d2.day=d2.day-31;
            d.mm++;
        }
        }
    }
    printf("date is:%d/%d/%d",d2.day,d.mm,d.yy);
}
