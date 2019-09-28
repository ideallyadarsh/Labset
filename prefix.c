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
    char infix[20],prifix[20];
    char *ch;int j=0,i;
    char u,x;
    printf("Enter a valid infix expression:");
    scanf("%s",infix);
    ch=strrev(infix);

    while(*ch!='\0')
    {
        x=*ch;
        if(isalnum(*ch))
            prifix[j++]=*ch;

        else if(*ch==')')
        {
            while((u=pop(&st))!='(')
                prifix[j++]=u;
        }
        else if(*ch=='(')
            push(&st,*ch);

        else
        {
            if(priority(st.stack[st.sp])> priority(*ch))
            {
                prifix[j++]=pop(&st);
            }
          else if(priority(st.stack[st.sp])==priority(*ch))
              {

                push(&st,*ch);
                prifix[j++]=pop(&st);

              }
            else
             push(&st,*ch);
        }


        ch++;
    }
    while(st.sp!=-1)
    {
        prifix[j++]=pop(&st);
    }

    for(i=strlen(prifix);i>=0;i--)
    {
        printf("%c",prifix[i]);
    }
    return 0;
}
