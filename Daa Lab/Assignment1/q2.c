#include<stdio.h>

int  binarysearch(int arr[],int n,int key){
    int low=0;
    int high=n-1;
    for(int i=0;i<n;i++){
        int mid=(low+high)/2;
        if(arr[mid]==key)
        return mid;
        else if(arr[mid]>key){
            high=mid-1;
        }
        else
        low=mid+1;
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
    if(binarysearch(arr,n,key)==-1)
    {
    printf("Element is not present");
    return 0;
    }
    printf("Element is present at index: %d",binarysearch(arr,n,key));
    
}