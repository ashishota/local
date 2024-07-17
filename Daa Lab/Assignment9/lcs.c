#include<stdio.h>

void lcs(char x[], char y[], int m, int n) {
    char b[m][n];
    int c[m][n];

    //0th row all elements to 0
    for (int i = 0; i < m; i++)
        c[i][0] = 0;

    //0th col all elements to 0
    for (int j = 0; j < n; j++)
        c[0][j] = 0;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\'; // Diagonal arrow
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '|'; // Up arrow
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '-'; // Left arrow
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            printf("%c ", b[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m,n;
    printf("Enter string 1 length: ");
    scanf("%d",&m);
    printf("Enter string 2 length: ");
    scanf("%d",&n);
    char X[m];
    char Y[n];
    printf("Enter elements of first sequence: ");

    scanf("%s",X);

    printf("Enter elements of second sequence: ");

    scanf("%s",Y);


    lcs(X, Y, m, n);
}
