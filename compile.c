#include<stdio.h>
struct initialise{
char name[29];
int sem;
};
int main()
{struct initialise s={"adarsh",3};
    //s.sem=3;
    printf("%s \t %d",s.name,s.sem);

}
