#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int start,int end){
    int i,j;
    int pivot=arr[start];
    int count=0;
    
    for(i=start+1;i<=end;i++){
        if(arr[i]<=pivot)
        count++;
    }
    
    int pivot_index=start+count;
    swap(&arr[pivot_index],&arr[start]);

    i=start;
    j=end;
    while(i<j){
        while(arr[i]<=pivot && i<j){
            i++;
        }
        while(arr[j]>pivot && i<j){
            j--;
        }
        if(i<j){
            swap(&arr[i++],&arr[j--]);
        }

    }

    return pivot_index;
}


void quick_sort(int arr[],int start,int end){
    if(start>=end)
    return;

    int pi=partition(arr,start,end);
    
    quick_sort(arr,start,pi-1);
    quick_sort(arr,pi+1,end);

}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={5,4,3,2,1};
    int n=5;
    printf("Given Array: ");
    print(arr,n);
    quick_sort(arr,0,n-1);
    printf("Sorted Array: ");
    print(arr,n);
}