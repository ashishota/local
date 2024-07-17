//adding a node at the end
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *head;
//time complexity of function is O(n)
struct node* add_at_end(struct node *ptr,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    ptr->link=temp;//updates the adress of current node
    return temp;
}

int main()  
{
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    struct node *ptr=head;//ptr poitning to first node of list

    ptr=add_at_end(ptr,98);//stores the adress of new node
    ptr=add_at_end(ptr,3);
    ptr=add_at_end(ptr,67);

    ptr=head;//ptr points to first  head  node
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;

}