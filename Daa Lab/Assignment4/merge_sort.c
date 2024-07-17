#include<stdio.h>
void merge(int arr[],int low,int mid,int high){
    int i,j;
    int k=low;
    int n1=mid-low+1;
    int n2=high-mid;

    int l[n1];
    int r[n2];

    for(int i=0;i<n1;i++){
        l[i]=arr[low+i];
    }
    for(int j=0;j<n2;j++){
        r[j]=arr[mid+1+j];
    }

    for(i=0,j=0;i<n1 && j<n2 ;){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }
        else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    for(;i<n1;i++){
        arr[k]=l[i];
        k++;
    }
    for(;j<n2;j++){
        arr[k]=r[j];
        k++;
    }
}
void merge_sort(int arr[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main(){
    int n;
    printf("enter size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Given Array: ");
    print(arr,n);
    printf("\nCalling Merge Sort...\n");
    merge_sort(arr,0,n-1);
    printf("Sorted array: ");
    print(arr,n);
}