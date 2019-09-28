#include<stdio.h>

struct nested
{
    char name[20];
    struct date
{
    int dd,mm,yy;
}d;

}s;


int main()
{
    printf("enter name\n");
    scanf("%s",s.name);
    printf("Enter dob mm dd yy\n");
    scanf("%d %d %d",&s.d.dd,&s.d.mm,&s.d.yy);
    printf("Name:%s DOB:%d/%d/%d",s.name,s.d.dd,s.d.mm,s.d.yy);

}
