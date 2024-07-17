#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation
#include <string.h>
#include <stdbool.h> // For boolean data type

#define MAX_NAME_LENGTH 100
#define EPSILON 0.0001 // Small value for floating-point comparison

typedef struct Product {
    int id;
    char name[MAX_NAME_LENGTH];
    float profit;
    float weight;
    float ratio;
} item;

// Swap two items
void swap(item *a, item *b) {
    item temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort to sort items based on their profit to weight ratio
void bubble_sort(item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void greedy_fractional_knapsack(item arr[], int n, int W) {
    bubble_sort(arr, n);
    
    int tw = 0;
    float tp = 0.0;
    printf("Items in knapsack:\n");
    for (int i = 0; i < n; i++) {
        if (tw + arr[i].weight <= W) {
            printf("ID: %d, Name: %s, Profit: %.2f, Weight: %.2f\n", arr[i].id, arr[i].name, arr[i].profit, arr[i].weight);
            tw += arr[i].weight;
            tp += arr[i].profit;
        } else {
            // Take fractional part of item
            float remaining_weight = W - tw;
            float fraction = remaining_weight / arr[i].weight;
            printf("ID: %d, Name: %s, Profit: %.2f, Weight: %.2f (Fraction: %.2f)\n", arr[i].id, arr[i].name, arr[i].profit * fraction, remaining_weight, fraction);
            tp += arr[i].profit * fraction;
            break; // No more items can be added
        }
    }
    printf("Total profit: %.2f\n", tp);
}

int main() {
    int n;
    printf("Enter Number of items: ");
    scanf("%d", &n);
    
    item *arr = (item *)malloc(n * sizeof(item)); // Dynamic memory allocation

    for (int i = 0; i < n; i++) {
        printf("Enter Product %d id: ", i + 1);
        scanf("%d", &arr[i].id);

        printf("Enter Product %d name: ", i + 1);
        while (getchar() != '\n'); // Clear input buffer
        fgets(arr[i].name, MAX_NAME_LENGTH, stdin);
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0'; // Remove trailing newline if present

        printf("Enter Product %d profit: ", i + 1);
        scanf("%f", &arr[i].profit);

        printf("Enter Product %d weight: ", i + 1);
        scanf("%f", &arr[i].weight);

        arr[i].ratio = (arr[i].profit / arr[i].weight);
    }

    printf("\nProducts Entered:\n");
    for (int i = 0; i < n; i++) {
        printf("Product %d:\n", i + 1);
        printf("ID: %d\n", arr[i].id);
        printf("Name: %s\n", arr[i].name);
        printf("Profit: %.2f\n", arr[i].profit);
        printf("Weight: %.2f\n", arr[i].weight);
        printf("Profit to Weight Ratio: %.2f\n", arr[i].ratio);
        printf("\n");
    }

    int cap;
    printf("Enter Capacity Of Knapsack: ");
    scanf("%d", &cap);
    greedy_fractional_knapsack(arr, n, cap);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
