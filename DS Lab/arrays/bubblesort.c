#include<stdio.h>
#include<stdbool.h>

void display(int k[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
            printf("%d ",k[i]);
    }
    printf("\n");
}


void bubblesort(int k[],int size)
{
    int i;
    for(i=0;i<size-1;i++)
    {
        bool flag=true;
        for(int j=0;j<=size-1-i;j++)
        {
            if(k[j]>k[j+1])
            {
                int temp=k[j];
                k[j]=k[j+1];
                k[j+1]=temp;
                flag=false;
            }
        }
        printf("\n%d",flag);
        if(flag==true)
        break;
    }
    printf("\nSorted array: \n");
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
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array: ");
    input(arr,n);
    bubblesort(arr,n);
}