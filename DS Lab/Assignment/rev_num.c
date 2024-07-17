#include<stdio.h>
#include<stdlib.h>

#define max 100
int stack[max];
int top=-1;

void push(int data)
{
    if(top==max-1)
    {
        printf("stack overflow\n");
        exit(1);
    }
    top=top+1;
    stack[top]=data;
}
int pop()
{
    if(top==-1)
    {
        printf("Stack is Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int main()
{
    int num,rev=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    int temp=num;
    while(temp!=0)
    {
        push(temp%10);
        temp/=10;
    }
    int i=1;
    while(top!=-1)
    {
        rev=rev + pop()*i;
        i=i*10;
    }
    printf("reverse number: %d\n",rev);

    return 0;
}



