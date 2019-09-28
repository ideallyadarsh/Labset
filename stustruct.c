#include<stdio.h>

struct student
{
    char name[20],usn[11],address[100];
    int sem;
    int submarks[5];
};



int main()
{
  struct student s;int i;
  printf("Enter Name,Address,USN,Semester\n");
  gets(s.name);
  gets(s.address);
  scanf("%s",s.usn);
  scanf("%d",&s.sem);
  printf("Enter Marks for 5 subjects\n");
  for( i=0;i<5;i++)
  {
      scanf("%d",&s.submarks[i]);
  }
  printf("Name\t Adress\t\t USN\t \tSemester\t Subject marks\n");
  printf("%20s\t %50s\t %11s \t%2d \t%2d ",s.name,s.address,s.usn,s.sem,s.submarks[0]);
  for(i=1;i<5;i++)
  {
      printf("\n\t\t\t\t\t\t\t%d",s.submarks[i]);
  }
}
