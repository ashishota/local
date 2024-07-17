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
            temp=newnode;
        }
        printf("Continue->1\n");
        scanf("%d",&choice);
    }

}
void del_dup()
{
    struct node *ptr=head,*cptr=NULL,*temp=NULL;
    
    if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    while(ptr->next!=NULL)
    {
        temp=ptr;
        cptr=ptr->next;
        while(cptr!=NULL)
        {
            if(ptr->data == cptr->data)
            {
                ptr->next=cptr->next;
                free(cptr);  
            }
            else
            {
                temp=cptr;
            }
            cptr=cptr->next;
        }
        ptr=ptr->next;
    }
    printf("Duplicates are deleted.\n");
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
    else
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n1.create\n2.delete_duplicate\n3.display\n4.exit\n");
        printf("enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            create();
            break;
            case 2:
            del_dup();
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