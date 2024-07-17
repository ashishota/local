#include<stdio.h>
#include<limits.h>

void display(int k[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
            printf("%d ",k[i]);
    }
    printf("\n");
}


void selectsort(int k[],int size)
{
    int i,j;
    for(i=0;i<size-1;i++)
    {
        int min=INT_MAX;
        int minidx=-1;
        for(j=i;j<=size-1;j++)
        {
            if(k[j]<min)
            {
                min=k[j];
                minidx=j;
            }
        }
        int temp=k[minidx];
        k[minidx]=k[i];
        k[i]=temp;
    }
    printf("Sorted array: ");
    display(k,size);

}

void input(int k[],int size)
{
    int i,j,l;
    for(i=0;i<size;i++)
    {
        scanf("%d",&k[i]);
    }

}


int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: ");
    input(arr,n);
    selectsort(arr,n);
}