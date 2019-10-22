#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;

};
typedef struct node Node;
Node *insertend(Node *start)
{
    Node *newn,*temp;
    int ele;
    if((newn=(Node *)malloc(sizeof(Node)))==NULL)
    {
        printf("Memory AllocATION error");
        return;
    }
    printf("Enter data to be inserted:");
    scanf("%d",&ele);
    newn->data=ele;
    newn->next=NULL;
    if(start==NULL)
    {
        start=newn;
        return start;
    }
    temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newn;
    return start;
}
Node *delete(Node *start)
{
    Node *temp=NULL;
    int ele;
    if(start==NULL)
    {
        printf("List is empty");
        return start;
    }
    temp=start;
    start=start->next;
    ele=temp->data;
    printf("Deleted element is:%d",ele);
    free(temp);
    return start;
}
Node *insertpos(Node *start)
{
    Node *newn,*temp;
    int i=1,j=0,ele,pos;
    if((newn=(Node *)malloc(sizeof(Node)))==NULL)
    {
        printf("Memory Allocation Error");
        return start;
    }

    printf("Enter element:");
    scanf("%d",&ele);
    printf("Position:");
    scanf("%d",&pos);
    newn->data=ele;
    newn->next=NULL;
    if(start==NULL && pos>1)
        return newn;
    if(pos==1)
    {
        newn->next=start;
        start=newn;
        return start;
    }
    temp=start;
    while(i<(pos-1) && temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    if(i==(pos-1))
    {
        newn->next=temp->next;
        temp->next=newn;
    }
    else
    {
        printf("Element not found insert at end");
        temp->next=newn;
    }
    return start;
}


void display(Node *start)
{
    if(start==NULL)
    {
        printf("List is empty:");
        return ;
    }
    printf("List:");
    while(start->next!=NULL)
    {
        printf("%d->",start->data);
        start=start->next;
    }
    printf("%d",start->data);
}
Node *revlist(Node *start)
{
    Node *next,*cur,*prev;
    if(start==NULL)
    {
        printf("List is empty");
        return start;
    }
    next=prev=NULL;
    cur=start;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    start=prev;
    return start;
}
int main()
{
    Node *start=NULL;
    int choice;
    do
    {
        printf("\n1.Insert at end \n2.Delete \n3.Display \n4.Insert position \n5.Reverse List \n6.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            start=insertend(start);
            break;
        case 2:
            start=delete(start);
            break;
        case 3:
            display(start);
            break;
        case 4:
            start=insertpos(start);
            break;
        case 5:
            start=revlist(start);
            display(start);
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong Choice:");
        }
    }
    while(1);
    return 0;
}
