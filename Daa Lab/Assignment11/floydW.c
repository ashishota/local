//wap to take input for a graph using adjacency matrix 
//implementation of floyd warshall alogorithm to find all pairs shortest path
//using pi n

#include<stdio.h>
#include<limits.h>

#define inf INT_MAX
int n=4;

void filldistancematrix(int mat[n][n],int d[n][n]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==j)
            d[i][j]=0;
            else if(mat[i][j]=inf)
            d[i][j]=inf;
            else
            d[i][j]=mat[i][j];

        }
    }
}


void floyd_warshall(int mat[n][n],int d[n][n]){
    filldistancematrix(mat,d);
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k]<inf && d[k][j]<inf){
                    if(d[i][k]+d[k][j]>d[i][j])
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
}


int main(){
    
    int mat[4][4]={
        {0,2,inf,5},
        {inf,0,3,2},
        {5,inf,0,1},
        {inf,inf,inf,0}
        };
    int d[4][4];
    floyd_warshall(mat,d);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(d[i][j]==inf)
            printf("inf ");
            else
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
    
}
