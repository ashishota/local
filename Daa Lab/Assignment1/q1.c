#include<stdio.h>

int linearsearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key)
        return i;
    }
    return -1;
}

int main(){
    int n,key;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d",&key);
    if(linearsearch(arr,n,key)==-1)
    {
    printf("Element is not present");
    return 0;
    }
    printf("Element is present at index: %d",linearsearch(arr,n,key));
    
}