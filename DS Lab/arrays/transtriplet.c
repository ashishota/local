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

void transpose(int k[][100],int row,int col) 
{
    int c[100][100];
    int i,j,t=1;
    c[0][0]=k[0][1];
    c[0][1]=k[0][0];
    c[0][2]=k[0][2];
    int n=k[0][2];
    for(i=0;i<k[0][1];i++)//row of transpose=col of triplet
    {
        for(j=1;j<=n;j++)//col of transpose=row of triplet
        { 
            if(i==k[j][1])
            {
                c[t][0]=i;//stores the col value of triplet in row of transpose
                c[t][1]=k[j][0];//stores the row of triplet in col of transpose
                c[t][2]=k[j][2];//
                t++;

            }

        }
    }
    printf("Transpose of triplet matrix is: \n");
    display(c,t,3);
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
    transpose(b,k,3);
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