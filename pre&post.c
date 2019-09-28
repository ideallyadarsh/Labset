#include<stdio.h>
#include<ctype.h>
struct stack{
char sdata[20];
int sp;
};
int prec(char x)
{
    switch(x)
    {
    case '(':
    case '#': return 1; break;
    case '+':
    case '-': return 2; break;
    case '*':
    case '/': return 3; break;
    case '^': return 4; break;

    }
}
int main()
{
    struct stack st,st1;
    int i=0,j=0,m,n=0,k;
    char infix[20];
    char postfix[20];
    char ch;
    st.sp=-1;
    st1.sp=-1;
    printf("Enter infix Expression: ");
    scanf("%s",infix);
    printf("If you want postfix expression press 1 if you want prefix press 0: ");
    scanf("%d",&m);
    if(m==0)
    {
           while(infix[i]!='\0')
    {
        ++i;
    }
    n=i-1;
    k=n;
    i=0;
    }
    ++st.sp;
    st.sdata[st.sp]='#';
    for(i=0;infix[i]!='\0';i++)
    {
        if(m==0)
        {
               ch=infix[n-i];
        }
        if(m==1)
        {
        ch=infix[i];
        }

        if(isalpha(ch)||isdigit(ch))
        {
            postfix[j++]=ch;
        }

        else
        {
            if(prec(ch)<=prec(st.sdata[st.sp]))
            {
                postfix[j++]=st.sdata[st.sp];
                --st.sp;
            }
            st.sdata[++st.sp]=ch;
        }
    }
    while(ch=st.sdata[st.sp]!='#')
    {
        postfix[j++]=st.sdata[st.sp];
        --st.sp;
    }
    postfix[j]='\0';
    if(m==0)
    {
        printf("Infix=%s\n",infix);
        printf("Prefix: ");
       for(j=0;postfix[j]!='\0';j++)
    {
        printf("%c",postfix[k-j]);
    }

    }
    if(m==1)
    {
printf("infix=%s\npostfix=%s",infix,postfix);
    }
}
