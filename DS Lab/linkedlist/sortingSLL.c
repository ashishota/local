#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void create()
{
    int choice=1,data;
    while(choice==1)
    {
        struct node *newnode;
        struct node *temp;
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->next=NULL;
            temp=newnode;
        }
        printf("Continue->1\n");
        scanf("%d",&choice);
    }

}
void sort()
{
    struct node *ptr,*cptr;
    ptr=head;
    
    while(ptr->next!=NULL)
    {
        cptr=ptr->next;
        while(cptr!=NULL)
        {
            if(ptr->data > cptr->data)
            {
                int temp=ptr->data;
                ptr->data=cptr->data;
                cptr->data=temp;
            }
            cptr=cptr->next;
        }
        ptr=ptr->next;
    }
    printf("List is sorted\n");
    return;

}
void display()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else if(temp->next==NULL)
    {
        printf("%d",temp->data);
    }
    else{}
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n1.create\n2.sort\n3.display\n4.exit\n");
        printf("enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            create();
            break;
            case 2:
            sort();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Invlaid Choice\n");
        }
    }
}