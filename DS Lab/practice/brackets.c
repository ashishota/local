#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 100
int top=-1;
char stack[max];
int isFull()
{
    return top==max-1;
}
int isEmpty()
{
    return top==-1;
}
void push(char data)
{
    if(isFull())
    {
        printf("Stack is overflow\n");
        return;
    }
    stack[++top]=data;

}

char pop()
{
    char c;
    c=stack[top--];
    return c;
}
int match_char(char a,char b)
{
    if(a=='[' && b==']')
    return 1;
    if(a=='{' && b=='}') 
    return 1;
    if(a=='(' && b==')')
    return 1;

    return 0;
}
int check_balance(char *s)
{
    int i;
    char temp;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='[' || s[i]=='{' || s[i]=='(')
        {
            push(s[i]);
        }
        if(s[i]==']' || s[i]=='}' || s[i]==')')
        {
            if(isEmpty())
            {
                printf("Right brackets are more than left brackets\n");
                return 0;
            }
            else
            {
                temp=pop();
                if(match_char(temp,s[i])==0)
                {
                    printf("mismatched brackets\n");
                    return 0;
                }
            }
        }
    }
    if(isEmpty())
    {
        printf("Brackets are well balanced\n");
        return 1;
    }
    else
    {
        printf("left brackets are more than right brackets\n");
        return 0;
    }
}
int main()
{
    char expr[max];
    int balanced;
    printf("Enter an expression: ");
    gets(expr);
    balanced=check_balance(expr);
    if(balanced==1)
    printf("Valid Expression");
    else
    printf("Invalid expression");

    return 0;

}