#include<stdio.h>
int m,n;
void printLCS( char f[m][n],char x[],int i,int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(f[i][j]=='#')
    {
        printLCS(f,x,i-1,j-1);
        printf("%c",x[i]);
    }
    else if(f[i][j]=='$')
    {
        printLCS(f,x,i-1,j);
    }
    else
    {
        printLCS(f,x,i,j-1);
    }
}
int main()
{
    char x[100],y[100];
    printf("Enter length of string x:");
    scanf("%d",&m);
    printf("Enter length of string y:");
    scanf("%d",&n);
    printf("Enter string x:\n");
    for(int i=0;i<=m;i++)
    {
        scanf("%c",&x[i]);
    }

    printf("Enter string y:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%c",&y[i]);
    }
    char b[m][n];
    int c[m+1][n+1];
    for(int i=1;i<=m;i++)
    {
        c[i][0]=0;
    }
    for(int j=0;j<=n;j++)
    {
        c[0][j]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='#';//# for diagonal
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='$';//up 
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='@';//left
            }
        }
    }
    printLCS(b,x,m,n);
    printf("\nc-table\n");
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    printf("\nb-table\n");
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%c\t",b[i][j]);
        }
        printf("\n");
    }
}