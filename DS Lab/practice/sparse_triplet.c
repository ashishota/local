#include<stdio.h>
void display(int a[100][100],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}

void triplet(int a[100][100],int row,int col)
{
    int b[100][100];
    int k=1;
    b[0][0]=row;
    b[0][1]=col;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }

        }
    }
    b[0][2]=k-1;
    printf("\nTriplet Matrix: \n");
    display(b,k,3);

}

int check_sparse(int a[][100],int row,int col)
{
    int count=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(a[i][j]==0)
            count++;
        }
    }

    return count>(row*col)/2;
}

void input(int a[][100],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
int main()
{
    int m,n;
    printf("Enter rows and columns of sparse matrix: \n");
    scanf("%d%d",&m,&n);
    int arr[100][100];
    printf("Enter elements of sparse matrix: ");
    input(arr,m,n);
    
    if(check_sparse(arr,m,n))
    {
    printf("\nElements of Sparse Matrix are: \n");
    display(arr,m,n);
    triplet(arr,m,n);
    }
    else
    printf("This is not a sparse matrix.\n");

    return 0;

}