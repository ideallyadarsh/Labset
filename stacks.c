#include<stdio.h>
#define SIZE 10
struct stack
{
    int a[SIZE];
    int sp;
};
void push(struct stack *st,int ele)
{

    if(st->sp==SIZE)
    {
        printf("overflow \n");
        return ;
    }
    st->sp++;
    st->a[(st->sp)]=ele;
    return;
}
int pop(struct stack *st)
{  int m=-1;
    if(st->sp==-1)
    {
        printf("Underflow \n");
        return m;
    }
    m=st->a[(st->sp)];

       st->sp--;

    return m;
}
void display(struct stack *st)
{
    int i;
    if(st->sp==-1)
    {
        printf("Stack is empty\n");
    }
   else
   {for(i=0; i<10; i++)
    {
        printf("Element %d=%d\n",i+1,st->a[i]);
    }}
}
int main()
{
     struct stack p;
p.sp=-1;
    int i,e,m,j=1;

 do{
    printf("\n1.Push \n2.Pop \n3.Display \nEnter your choice:");
    scanf("%d",&i);
    switch(i)
    {
    case 1:while(j<11){
        printf("Enter %dth element to be pushed:",j);
        scanf("%d",&e);
        push(&p,e);j++;
    }
        break;
    case 2:
           m=pop(&p);
           printf("Popped value=%d",m);
        break;
    case 3:
        display(&p);
        break;
    default:
        printf("Invalid Choice");
    }

} while(i<=3);
}
