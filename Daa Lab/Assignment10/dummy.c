#include<stdio.h>
int n;
struct items{
    int id;
    char a[50];
    int p;
    int w;
    float ratio;
};
void knapsack(struct items items[], int n, int cap){
    for(int i=0;i<n;i++){
        items[i].ratio=(float)items[i].p/items[i].w;
    }
    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(items[j].ratio<items[j+1].ratio){
                struct items temp=items[j];
                items[j]=items[j+1];
                items[j+1]=temp;
            }
        }
    }
    int tw=0;
    int tp=0;

    printf("items in knapsack:\n");
    for(int i=0;i<n;i++){
        if(tw+items[i].w <= cap){
            printf("id = %d,name = %s,price = %d, weight = %d\n",items[i].id,items[i].a,items[i].p,items[i].w);
            tw += items[i].w;
            tp += items[i].p;
        }
    }
    printf("total profit = %d\n",tp);
}
int main(){
    int n, cap;
    printf("enter number of products: ");
    scanf("%d", &n);
    struct items items[n];
    printf("enter the values for each product:\n");
    for (int i = 0; i < n; i++) {
        printf("product %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &items[i].id);
        printf("name: ");
        scanf("%s", items[i].a);
        printf("price: ");
        scanf("%d", &items[i].p);
        printf("weight: ");
        scanf("%d", &items[i].w);
    }
    printf("enter the capacity of the knapsack: ");
    scanf("%d", &cap);
    knapsack(items, n, cap);
    return 0;
}