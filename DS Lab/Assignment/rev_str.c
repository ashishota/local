#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 100
int stack[max];
int top=-1;


void push(char data)
{
    top=top+1;
    stack[top]=data;
}
char pop()
{
    char value;
    value=stack[top];
    top=top-1;
    return value;
}


int main()
{
    int i,n;
    printf("Enter size of the string: ");
    scanf("%d",&n);
    char str[n];
    printf("Enter a string: ");
    for(i=0;i<n;i++)
    {
        scanf(" %c",&str[i]);
    }

    //pushing elemnts of string

    for(i=0;i<n;i++)
    {
    push(str[i]);
    }

    //printing the string
    printf("Input string: ");
    for(i=0;i<n;i++)
    {
    printf("%c",str[i]);
    }
    printf("\n");
    printf("Reversed string: ");
    for(i=0;i<n;i++)
    {
    printf("%c",pop());
    }
    printf("\n");
}