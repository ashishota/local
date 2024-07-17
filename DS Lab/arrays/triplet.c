#include<stdio.h>

void display(int k[][100],int row,int col)
{
    int i;
    for(i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",k[i][j]);
        }

        printf("\n");

    }
    printf("\n");
}

void triplet(int a[100][100],int row,int col)
{
    int b[100][100];
    int i,j,k=1;
    b[0][0]=row;
    b[0][1]=col;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        if(a[i][j]!=0)
        {
            b[k][0]=i;
            b[k][1]=j;
            b[k][2]=a[i][j];
            k++;

        }
        
    }
    b[0][2]=k-1;
    printf("Triplet matrix : \n");
    display(b,k,3);
}
void sparse(int k[][100],int row,int col)
{
    
    printf("Enter elements of sparse matrix: ");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&k[i][j]);
        }
    }
    printf("Entered sparse matrix is: \n");
    display(k,row,col);
    triplet(k,row,col);
}

int main()
{
    int m,n;
    printf("Enter the no of rows and columns of sparse matrix: ");
    scanf("%d%d",&m,&n);
    int a[100][100];
    sparse(a,m,n);
}