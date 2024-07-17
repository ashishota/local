//adding at beginning
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *head;

struct node *add_at_beg(struct node *head,int data)
{
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;

    ptr->link=head;
    head=ptr;
    return head;
}

int main()
{
    head=malloc(sizeof(struct node));
    head->data=60;
    head->link=NULL;

    struct node *ptr;
    head=add_at_beg(head,50);
    head=add_at_beg(head,40);
    head=add_at_beg(head,30);

    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}