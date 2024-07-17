#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of vertices:\n");
    scanf("%d",&n);
    int arr[n][n],d_old[n][n],d_new[n][n],pi_old[n][n],pi_new[n][n];
    printf("Enter values in adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]>0 && arr[i][j]<999)
            {
                pi_old[i][j]=i+1;
            }
            else
            {
                pi_old[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            d_old[i][j]=arr[i][j];
        }
    }

    for(int k=0;k<n;k++)
    {
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(d_old[i][j]<=(d_old[i][k]+d_old[k][j]))
                {
                    d_new[i][j]=d_old[i][j];
                    pi_new[i][j]=pi_old[i][j];
                }
                else
                {
                     d_new[i][j]=d_old[i][k]+d_old[k][j];
                     pi_new[i][j]=pi_old[k][j];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                d_old[i][j]=d_new[i][j];
                pi_old[i][j]=pi_new[i][j];
            }
        }

    }
    printf("\n");

    printf("Distance matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",d_new[i][j]);
        }
        printf("\n");
    }

    printf("Pi matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",pi_new[i][j]);
        }
        printf("\n");
    }
    int x,y;
    printf("Enter vertex1,vertex2:");
    scanf("%d %d",&x,&y);
    printf("Minimum Distance between 2 given vertices is: %d\n",d_new[x-1][y-1]);
}