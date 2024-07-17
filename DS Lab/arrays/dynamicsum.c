#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int *ptr;
    ptr=(int*)malloc(n*sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory not allocated.");
        exit(0);
    }
    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
    //sum
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=*(ptr+i);
    }
    //printing the sum

    printf("%d is the sum of elements\n",sum);
    free(ptr);
    ptr=NULL;

    return 0;
    
}