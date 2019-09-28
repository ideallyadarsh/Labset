#include<stdio.h>
struct employee
{
 char name[25],dept[25],add[30];
 int id,sal;

}e;
void read(char filename[]);
void write(char filename[]);
void search(int i,char filename[]);

void main()
{
     FILE *fp;
    char filename[25];int i, n;
    printf("enter filename:");
    gets(filename);
    printf(" 1.Write\n 2.Read\n 3.search\n Enter your choice:");
    scanf("%d",&n);
    switch(n)
    {
    case 2:
        read(filename);break;
    case 1:
        write(filename);break;
        case 3:
            printf("enter id to be searched\n");
            scanf("%d",&i);
        search(i,filename);break;
        default:
            printf("Wrong Choice");

    }
}
void read(char filename[])
{
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL)
    {printf("Error opening of file");return;}
        printf("Employee_id Name\t\tDepartment\t\t\tAddress\t\t\tSalary\n");
        while(fread(&e,sizeof(e),1,fp)==1)
    {
       printf("%-11d %-25s %-25s %-25s %-d\n" ,e.id,e.name,e.dept,e.add,e.sal);
    }
    fclose(fp);
}
void write(char filename[])
{
    FILE *fp;int i,n;
    fp=fopen(filename,"a");
    if(fp==NULL)
    {printf("Error opening of file");return;}
    printf("Enter number of records to be entered:");scanf("%d",&n);
   for(i=0;i<n;i++){
        printf("Enter Employee_id:");
        scanf("%d",&e.id);
        fflush(stdin);
        printf("Enter Employee Name:");
        gets(e.name);
        fflush(stdin);
        printf("Enter Employee Department:");
        gets(e.dept);
        fflush(stdin);
        printf("Enter Employee Address:");
        gets(e.add);
        fflush(stdin);
        printf("Enter Employee Salary:");
        scanf("%d",&e.sal);


    fwrite(&e,sizeof (struct employee ),1,fp);}

    fclose(fp);
}
void search(int i,char filename[])
{
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL)
    {printf("Error opening of file");return;}
     while((fread(&e,sizeof(struct employee),1,fp))==1)
     {
         if(i==e.id)
          {
              printf("\nRecord found\n");
             printf("Employee_id:%d \nName:%s \nDepartment:%s \nAddress:%s\nSalary:%d",e.id,e.name,e.dept,e.add,e.sal);
             return;
             }
         else
          {

          printf("\nNo such record exist");
     }
     }


    fclose(fp);
}
