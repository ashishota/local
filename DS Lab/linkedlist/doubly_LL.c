#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
int value;
void create()
{
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter A Value: ");
    scanf("%d",&value);
    head->prev=NULL;
    head->data=value;
    head->next=NULL;
    printf("Node Created.\n");
}
void insert_beg(int data)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->prev=NULL;
    ptr->data=data;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
        printf("Node Inserted.\n");
    }
    else
    {
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
        printf("Node Inserted.\n");
    }


}
void insert_end(int data)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->prev=NULL;
    ptr->data=data;
    ptr->next=NULL;

    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        head=ptr;
        printf("Node Inserted\n");
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
    printf("Node Inserted.\n");
}
void insert_pos(int data,int pos)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->prev=NULL;
    ptr->data=data;
    ptr->next=NULL;

    struct node *temp,*temp2;
    temp=head;
    if(head==NULL)
    {
        create();
        return;
    }
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Can't Insert\n");
            return;
        }
    }
    ptr->next=temp->next;
    ptr->prev=temp;
    temp->next=ptr;

    if(temp->next!=NULL)
    temp->next->prev=ptr;

    printf("Node Inserted.\n");
}
void del_beg()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        if(head->next==NULL)
        {
            head=NULL;
            free(head);
            printf("Only node deleted\n");
        }
        else
        {
        temp=head;
        head=temp->next;
        head->prev=NULL;
        head->next=temp->next->next;
        printf("Node deleted\n");
        }
    }

}
void del_end()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("List is Empty.\n");
    }
    else
    {
        if(head->next==NULL)
        {
            head=NULL;
            free(head);
            printf("Only node deleted\n");
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->prev->next=NULL;
            temp=NULL;
            free(temp);
            printf("Node Deleted.\n");
        }

    }


}
void del_pos(int pos)
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("List is Empty.\n");
    }
    else
    {
        if(head->next==NULL)
        {
            head=NULL;
            free(head);
            printf("Only Node Deleted.\n");
        }
        else
        {
            for(int i=1;i<pos;i++)
            {
                temp=temp->next;
                if(temp==NULL)
                {
                    printf("Invalid Position.\n");
                    return;
                }
            }
            temp->prev->next=temp->next;

            if(temp->next!=NULL)
            temp->next->prev=temp->prev;

            free(temp);
            printf("Node Deleted.\n");
        }
    }

}
void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()  
{
    int choice;
    int pos;
    while(1)
    {
        printf("\n0.create\n1.insert_at_beg\n2.insert_at_end\n3.insert_at_pos\n");
        printf("4.delete_at_beg\n5.delete_at_end\n6.delete_at_pos\n");
        printf("7.display\n8.exit\n\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
            create();
            break;
            case 1:
            printf("Enter a value: ");
            scanf("%d",&value);
            insert_beg(value);
            break;
            case 2:
            printf("Enter a value: ");
            scanf("%d",&value);
            insert_end(value);
            break;
            case 3:
            printf("Enter a value: ");
            scanf("%d",&value);
            printf("Enter the position where to insert: ");
            scanf("%d",&pos);
            insert_pos(value,pos);
            break;
            case 4:
            del_beg();
            break;
            case 5:
            del_end();
            break;
            case 6:
            printf("Enter the position where to delete: ");
            scanf("%d",&pos);
            del_pos(pos);
            break;
            case 7:
            display();
            break;
            case 8:
            exit(0);
            
        }
    }

    return 0;

}