#include<stdio.h>
#include<string.h>
#include<math.h>

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
void push(int data)
{
    if(isFull())
    {
        printf("Stack is overflow\n");
        return;
    }
    top=top+1;
    stack[top]=data;

}

int pop()
{
    int value;
    value=stack[top];
    top=top-1;
    return value;
}

int post_eval(char *s)
{
    int a,b;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0' && s[i]<='9')
        push(s[i]-'0');

        else
        {
            a=pop();
            b=pop();
            switch(s[i])
            {
                case '+':
                push(b+a);
                break;
                case '-':
                push(b-a);
                break;
                case '*':
                push(b*a);
                break;
                case '/':
                push(b/a);
                break;
                case '^':
                push(pow(b,a));
                break;
            }
        }
    }
    return pop();

}
int main()
{
    char post[max];
    printf("Enter an expression: ");
    gets(post);
    int result=post_eval(post);
    printf("%d",result);

    return 0;

}