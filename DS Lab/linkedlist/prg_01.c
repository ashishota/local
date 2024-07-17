
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL;

void count_of_nodes(struct node *head)
{
    int count=0;
    struct node *ptr=NULL;
    if(head==NULL)
    {
        printf("List is empty");
    }
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    printf("%d\n",count);
}

void print_node(struct node *head)
{
    struct node *ptr=NULL;
    if(head==NULL)
    {
        printf("List is empty");
    }
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

}

//time complexity=O(n)
void add_nodes_at_end(struct node *head,int data)
{
    struct node *ptr,*temp;
    ptr=head;

    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    print_node(head);
}
int main()
{
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    
    struct node *current;
    current=malloc(sizeof(struct node));
    current->data=90;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=20;
    current->link=NULL;
    head->link->link=current;

    count_of_nodes(head);
    
    add_nodes_at_end(head,47);






}