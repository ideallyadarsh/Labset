#include<stdio.h>
#include<ctype.h>

struct label
{
    char stack[20];
    int sp;
} ;
void push(struct label *st,char ch)
{

    if(st->sp==19)
    {
        printf("overflow");
    }
    st->sp++;
    st->stack[st->sp]=ch;
}
char pop(struct label *st)
{
    char ele;
    if(st->sp==-1)
    {
        printf("Underflow");

    }
    ele=st->stack[st->sp];
    st->sp--;

    return ele;
}
int priority(char ch)
{
    switch(ch)
    {
    case '(':
        return 0;
        break;
    case '+':
    case'-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return -1;
    }
}
int main()
{
    struct label st;
    st.sp=-1;
    char infix[20];
    char *ch;
    char u,x;
    printf("Enter a valid infix expression:");
    scanf("%s",infix);
    ch=infix;

    while(*ch!='\0')
    {
        x=*ch;
        if(isalnum(*ch))
            printf("%c",*ch);

        else if(*ch==')')
        {
            while((u=pop(&st))!='(')
                printf("%c",u);
        }
        else if(*ch=='(')
            push(&st,*ch);

        else
        {
            if(priority(st.stack[st.sp])> priority(*ch))
            {
                printf("%c",pop(&st));
            }
          else if(priority(st.stack[st.sp])==priority(*ch))
              {

                push(&st,*ch);
                printf("%c",pop(&st));

              }
            else
             push(&st,*ch);
        }


        ch++;
    }
    while(st.sp!=-1)
    {
        printf("%c",pop(&st));
    }
    return 0;
}
