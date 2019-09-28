#include<stdio.h>

struct student
{
    char name[20],usn[11],address[100];
    int sem;
    int submarks[5];
};
int main()
{
    struct student s[100];int n,i,j;
    printf("Enter the number of students(<100):");
    scanf("%d",&n);
    int c[100]={0};
    for(i=0;i<n;i++)
    {   printf("enter name of student %d\n",i+1);
        gets(s[i].name);
getchar();
        printf("Enter the 5 subject marks for student %d ",i+1);
            for(j=0;j<5;j++)
            {
                scanf("%d",&s[i].submarks[j]);
               c[i]+=s[i].submarks[j];
            }

    }
    for(i=0;i<n;i++)
    {  printf("Name(%d):%s\t",i+1,s[i].name);
       printf("Average marks of student %d:%d",i+1,c[i]/5);
       printf("\n");
    }
}
