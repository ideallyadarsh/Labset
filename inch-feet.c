#include<stdio.h>
struct lenght
{
    int feet,inch;

}l.l1;
void main()
{
    printf("Enter any lenth feet,inch:");
    scanf("%d %d",&l.feet,&l.inch);
    l1.inch=l.inch+l.feet*12;
    l1.feet=(l1.inch/12);
printf("total length in inches:%d \n total lenth in feet:%d''%d'",l1.inch,l1.feet,l1.inch%12);
}
