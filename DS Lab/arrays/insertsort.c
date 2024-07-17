#include<stdio.h>


void display(int k[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
            printf("%d ",k[i]);
    }
    printf("\n");
}

void insertsort(int k[],int size)
{
    int i,j;
    for(i=1;i<=size-1;i++)
    {
        j=i;
        while(j>=1 && k[j]<k[j-1])
        {
            int temp=k[j];
            k[j]=k[j-1];
            k[j-1]=temp;
            j--;
        }
    }
    printf("Sorted array: ");
    display(k,size);

}

void input(int k[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        scanf("%d",&k[i]);
    }

}

int main()
{
    int n;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array: ");
    input(arr,n);
    printf("unsorted array: ");
    display(arr,n);
    insertsort(arr,n);

}