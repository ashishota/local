#include<stdio.h>
#include<stdlib.h>

int* input(int *size){
    printf("Enter size: ");
    scanf("%d", size);
    int *arr = (int*)malloc(*size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter Elements Of array: ");
    for(int i = 0; i < *size; i++){
        scanf("%d", &arr[i]);
    }
    return arr;
}

void display(int* arr, int size){
    printf("Elements of array are: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_asc(int* arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    display(arr, size);
}

void selection_desc(int* arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    display(arr, size);
}

void insertion_asc(int* arr, int size){
    int key, j;
    for(int i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    display(arr, size);
}

int main(){
    int *x;
    int size;
    int ch = 1;
    while(ch){
        printf("\n1. Input\n2. Display\n3. Bubble Sort Ascending\n4. Selection Sort Descending\n5. Insertion Sort Ascending\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                x = input(&size);
                break;
            case 2:
                display(x, size);
                break;
            case 3:
                bubble_asc(x, size);
                break;
            case 4:
                selection_desc(x, size);
                break;
            case 5:
                insertion_asc(x, size);
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("Would you like to continue? (1->continue 0->exit) ");
        scanf("%d", &ch);
    }
    free(x);
    return 0;
}
