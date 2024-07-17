#include<stdio.h>
#include<stdlib.h>

int value;
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void create()
{
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter a value: ");
    scanf("%d",&value);

    head->data=value;
    head->next=NULL;
}

void insert_end(int data)
{
    struct node *temp;
    struct node *ptr=malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Overflow");
    }
    else
    {
        ptr->data=data;
        if(head==NULL)//checks if only one node is present
        {
            ptr->next=NULL;
            head=ptr;
            printf("Node Inserted.\n");
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("Node Inserted.\n");

        }
    }
}

void insert_beg(int data)
{
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Memory Not alloctaed.");
        return;
    }
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    printf("Node Inserted.\n");
}

void insert_pos(int data,int pos)
{
    struct node *temp;
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    if(ptr==NULL)
    {
        printf("Overflow\n");
    }
    else
    {
    temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
        if(temp==NULL)//checks if wanted node is last
        {
            printf("Can't Insert\n");
            return;
        }
    }
    ptr->next=temp->next;
    temp->next=ptr;

    printf("Node Inserted.\n");
    }

}

void del_beg()
{
    if(head==NULL)
    {
        printf("Underflow\n");
        return;
    }
    struct node *ptr=head;
    if(head->next==NULL)
    {
        free(head);
        printf("Only node deleted.\n");
    }
    else
    {
    head=head->next;
    free(ptr);
    printf("Node Deleted.\n");
    }
}

void del_end()
{
    struct node *ptr=head;
    struct node *temp;
    if(head==NULL)
    {
        printf("No Node Present.\n");
    }
    else
    {
        if(head->next==NULL)
        {
            head=NULL;
            free(head);
            printf("Only node deleted.\n");
        }
        else
        {
        while(ptr->next->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        free(ptr);
        printf("Node Deleted.\n");
        }
    }

}

void del_pos(int pos)
{
    struct node *ptr=head;
    struct node *temp;
    if(head==NULL)
    {
        printf("No Node Present.\n");
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            temp=ptr;
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("Can't Delete.\n");
                return;
            }
        }
        temp->next=ptr->next;
        free(ptr);
        printf("Node Deleted.\n");

    }
}

void display()
{
    if(head==NULL)
    {
        printf("List is Empty");
        return;
    }

    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
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
            exit(1);
            
        }
    }

    return 0;

}