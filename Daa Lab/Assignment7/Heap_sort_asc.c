#include<stdio.h>
#include<math.h>

int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
int parent(int i){
    return (i-1)/2;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void max_heapify(int arr[],int n,int i){

    int left_idx=left(i);
    int right_idx=right(i);
    int largest=i;
    if(left_idx<n && arr[left_idx]>arr[largest])
    largest=left_idx;

    if(right_idx<n && arr[right_idx]>arr[largest])
    largest=right_idx;

    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        max_heapify(arr,n,largest);
    }
}
void build_max_heap(int arr[],int n){
    for(int i=n/2 - 1;i>=0;i--){
        max_heapify(arr,n,i);
    }
}
void heap_sort(int arr[],int n){
    build_max_heap(arr,n);
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        max_heapify(arr,i,0);
    }

}

int heap_extract_max(int arr[],int n){
    build_max_heap(arr,n);
    int max;
    if(n<1){
        printf("Heap Underflow");

    }
    else{
        max=arr[0];
        arr[0]=arr[n-1];
    }
    n=n-1;
    max_heapify(arr,n,0);
    return max;
}


void heap_increase_key(int arr[],int n,int i,int key){
    if(key<arr[i]){
        printf("Error... \n");
        return;
    }
    else{
        arr[i]=key;
    }
    while(i>0 && arr[parent(i)]<arr[i]){
        swap(&arr[i],&arr[parent(i)]);
        i=parent(i);
    }
    printf("\nKey Sucessfully Increased.\n");
    printf("After Increase Key array is: ");
    print(arr,n);

}

int main(){
    int n;
    printf("Enter Size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Given Array: ");
    print(arr,n);

    heap_sort(arr,n);
    printf("Sorted Array: ");
    print(arr,n);
    // printf("Maximum element: %d\n",heap_extract_max(arr,n));

    // heap_increase_key(arr,n,2,25);
    

}