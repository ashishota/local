#include<stdio.h>
#include<time.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    int i,j;
    int pivot=arr[high];
    j=low-1;
    for(i=low;i<high;i++){
        if(arr[i]<=pivot){
            j++;
            swap(&arr[i],&arr[j]);
            
        }
    }
    swap(&arr[j+1],&arr[high]);
    return j+1;
}

void quickSort(int arr[],int low,int high){
    if(low>=high)
    return;

    int pi=partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    clock_t start_t,end_t;
    double total_t;
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Given Array: ");
    print(arr,n);
    start_t=clock();
    quickSort(arr,0,n-1);
    end_t=clock();
    total_t=(double)(end_t - start_t)/ CLOCKS_PER_SEC;
    printf("Execution time of quickSort is: %.5f seconds\n",total_t);

    printf("Sorted Array: ");
    print(arr,n);

}