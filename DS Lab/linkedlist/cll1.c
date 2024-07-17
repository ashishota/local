#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *add_at_empty() {
    int value;
    struct node *temp = malloc(sizeof(struct node));
    printf("Enter a value: ");
    scanf("%d", &value);
    temp->data = value;
    temp->next = temp;

    printf("Node Created.\n");
    return temp;
}

void add_at_beg(struct node *tail) {
    int value;
    struct node *newp = malloc(sizeof(struct node));
    printf("Enter a value: ");
    scanf("%d", &value);
    newp->data = value;
    newp->next = (tail)->next;
    (tail)->next = newp;

    printf("Node inserted.\n");
}

void add_at_end(struct node *tail) {
    int value;
    struct node *newp = malloc(sizeof(struct node));
    printf("Enter a value: ");
    scanf("%d", &value);
    newp->data = value;
    newp->next = (tail)->next;
    (tail)->next = newp;
    (tail) = newp;

    printf("Node inserted.\n");
}

void print(struct node *tail) {
    if (tail == NULL) {
        printf("list is empty.");
        return;
    }
    struct node *p = tail->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);

    printf("\n");
}

void add_at_pos(struct node *tail) {
    int value, pos;
    struct node *p, *newp;
    newp = malloc(sizeof(struct node));
    printf("Enter a value: ");
    scanf("%d", &value);
    printf("Enter the position where to insert: ");
    scanf("%d", &pos);
    newp->data = value;
    newp->next = NULL;
    p = (tail)->next;
    while (--pos > 1) {
        p = p->next;
    }
    newp->next = p->next;
    p->next = newp;
    if (p == tail) {
        tail = (tail)->next;
    }
}

int main() {
    struct node *tail = NULL;
    int choice;
    while (1) {
        printf("\n0.create\n1.insert_at_beginning\n2.insert_at_end\n3.insert_at_position\n");
        printf("4.display\n5.exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                tail = add_at_empty();
                break;
            case 1:
                add_at_beg(tail);
                break;
            case 2:
                add_at_end(tail);
                break;
            case 3:
                add_at_pos(tail);
                break;
            case 4:
                print(tail);
                break;
            case 5:
                exit(1);
        }
    }

    return 0;
}
