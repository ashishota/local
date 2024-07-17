#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

int  matrix_chain_order(int p[],int n){
    int m[n][n];
    int s[n][n];
    for(int i=1;i<n;i++){
            m[i][i]=0;  
    }
    for(int i=1;i<n;i++){
            s[i][i]=0;
        
    }
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++){
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }

    printf("\nM-table: \n");
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
             if (j < i) {
                printf(" \t");
            } else {
                printf("%d\t", m[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nS-TABLE: \n");
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
             if (j < i) {
                printf(" \t");
            } else {
                printf("%d\t", s[i][j]);
            } 
        }
        printf("\n");
    }

    return m[1][n-1];
    

}





int main(){
    int n;
    printf("Enter The no of matrices to multiply: ");
    scanf("%d",&n);
    int p[n];
    printf("Enter the order of Matrices entered: ");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    
    printf("Minimum number of multiplications is %d\n",matrix_chain_order(p,n));


}