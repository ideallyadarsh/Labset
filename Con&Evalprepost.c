#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define size 30
struct stack
{
    float stack[size];
    int sp;
} st;
struct label
{
    char stack[20];
    int sp;
};
void eval(char exp[],int choice)
{
    int i ;
    float op1,op2,res;
    float sym[26];
    st.sp=-1;
    for(i=0; i<26; i++)
    {
        sym[i]=-1;

    }
    i=0;
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
            st.stack[++st.sp]=exp[i]-'0';

        else if(isalpha(exp[i]))
        {
            if(exp[i]>='a'&&exp[i]<='z')
                exp[i]=exp[i]-32;
            if(sym[exp[i]-'A']==-1)
            {
                printf("Enter value of %c",exp[i]);
                scanf("%f",&sym[exp[i]-'A']);
            }
            st.stack[++st.sp]=sym[exp[i]-'A'];
        }
        else
        {
            if(choice==1)
            {
                op2=st.stack[st.sp--];
                op1=st.stack[st.sp--];
            }
            else if(choice==2)
            {
                op1=st.stack[st.sp--];
                op2=st.stack[st.sp--];
            }
            switch(exp[i])
            {
            case '+':
                res=op1+op2;
                break;
            case '-':
                res=op1-op2;
                break;
            case '*':
                res=op1*op2;
                break;
            case '/':
                res=op1/op2;
                break;
            }

            st.stack[++st.sp]=res;
        }
        i++;

    }

    printf("\nResult:%f\n",st.stack[st.sp--]);
}
void push(struct label *s,char ch)
{

    if(s->sp==19)
    {
        printf("overflow");
    }
    s->sp++;
    s->stack[s->sp]=ch;
}
char pop(struct label *s)
{
    char ele;
    if(s->sp==-1)
    {
        printf("Underflow");

    }
    ele=s->stack[s->sp];
    s->sp--;

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
void convert(char infix[],int choice)
{  struct label s;
    s.sp=-1;
    char *ch;char u;
    int i=0,j=0;
    char expression[30];
    ch=infix;
    while(*ch!='\0')
    {
        if(isalnum(*ch))
            expression[j++]=*ch;

        else if(*ch==')')
        {
            while((u=pop(&s))!='(')
                expression[j++]=u;
        }
        else if(*ch=='(')
            push(&s,*ch);

        else
        {
            if(priority(s.stack[s.sp])> priority(*ch))
            {
                expression[j++]=pop(&s);
            }
            else if(priority(s.stack[s.sp])==priority(*ch))
            {

                push(&s,*ch);
                expression[j++]=pop(&s);

            }
            else
                push(&s,*ch);
        }


        ch++;
    }//End of while loop
    while(s.sp!=-1)
    {
        expression[j++]=pop(&s);
    }
    expression[j]='\0';
    //End of Conversion
    //Printing of Expressions
    if(choice==1)
    {
        printf("\nInfix=%s--->Postfix=%s",infix,expression);

    }
    else if(choice==2)
    {
        printf("\nInfix=%s--->Prefix=",infix);
        for(i=j-1; i>=0; i--)
        {
            printf("%c",expression[i]);
        }
    }
}//End of convert function
int main()
{
    //struct label st;
    //st.sp=-1;
    char infix[20],exp[20];
    int choice;
 do{   printf("\nPOSTFIX & PREFIX");
    printf("\n\t1.Convert to Postfix\n\t2.Convert to Prefix\n\t3.Evaluation\n\t4.Exit\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Conversion of Infix to Postfix\n ");
        printf("Enter a valid infix expression:");
        scanf("%s",infix);
        convert(infix,choice);
        break;
    case 2 :
        printf("Conversion of Infix to Postfix\n ");
        printf("Enter a valid infix expression:");
        scanf("%s",infix);
        convert(strrev(infix),choice);
        break;
    case 3:
        printf("\nEvaluation of expression:\n\t1.Postfix\n\t2.Prefix\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {

        case 1:
            printf("Enter a valid postfix expression:");
            scanf("%s",exp);
            eval(exp,choice);
            break;
        case 2:
            printf("Enter a valid prefix expression:");
            scanf("%s",exp);
            eval(strrev(exp),choice);
            break;
        default:
            printf("Wrong Choice!!!");
        }
        break;//End of case 3
    case 4:
        exit(0);
    default:
        printf("Wrong Choice!!!");
    }
 }while(1);
    return 0;
}
