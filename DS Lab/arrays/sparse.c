#include<stdio.h>
void display(int k[][100],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",k[i][j]);
        }
        printf("\n");
    }
    
}
void sparse(int a[100][100],int row,int col)
{
    int b[100][100];
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            b[i][j]=0;
        }
        printf("\n");
    }
    for(i=1;i<row;i++)
    {
    b[a[i][0]][a[i][1]]=a[i][2];
    }
    printf("The sparse matrix is: \n");
    display(b,row,col);
}

void triplet(int k[][100],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&k[i][j]);
        }
    }
    printf("Entered triplet matrix is: \n");

    int row1=k[0][0];
    int col1=k[0][1];

    display(k,row,col);

    

    sparse(k,row1,col1);

}
int main()
{
    int m;
    printf("Enter the number of rows of triplet matrix: ");
    scanf("%d",&m);
    int a[100][100];

    printf("Enter the elements of triplet matrix: ");

    triplet(a,m,3);

}