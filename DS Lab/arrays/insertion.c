#include<stdio.h>

void display(int k[],int size)
{
    int i;
    printf("New array is: ");
    for(i=0;i<size;i++)
    {
        printf("%d ",k[i]);
    }
    printf("\n");

}
void insertion(int k[],int size,int pos,int elm)
{
    int i;
    for(i=size-1;i>=pos-1;i--)
    {
        k[i+1]=k[i];

    }
    size++;
    k[pos-1]=elm;
    display(k,size);

}

void input(int k[],int size)
{
    int i,j,l;
    for(i=0;i<size;i++)
    {
        scanf("%d",&k[i]);
    }
    printf("Enter the position and element: ");
    scanf("%d%d",&j,&l);
    insertion(k,size,j,l);

}

int main() 
{
    int n,k,l;
    printf("Enter size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array: ");
    input(arr,n);
    
}