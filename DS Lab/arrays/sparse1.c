#include <stdio.h>
#include <stdlib.h>

void triplet_to_sparse(int triplet[][3], int num_triplets, int sparse[][3]) {
    // determine size of sparse matrix
    int max_row = 0;
    int max_col = 0;
    for (int i = 0; i < num_triplets; i++) {
        if (triplet[i][0] > max_row) {
            max_row = triplet[i][0];
        }
        if (triplet[i][1] > max_col) {
            max_col = triplet[i][1];
        }
    }
    
    // initialize sparse matrix
    int num_rows = max_row + 1;
    int num_cols = max_col + 1;
    int num_nonzeros = num_triplets;
    int row_ptr[num_rows + 1];
    int col_idx[num_nonzeros];
    int val[num_nonzeros];
    for (int i = 0; i <= num_rows; i++) {
        row_ptr[i] = 0;
    }
    for (int i = 0; i < num_triplets; i++) {
        row_ptr[triplet[i][0] + 1]++;
    }
    for (int i = 1; i <= num_rows; i++) {
        row_ptr[i] += row_ptr[i-1];
    }
    
    // copy data from triplet to sparse matrix
    for (int i = 0; i < num_triplets; i++) {
        int row = triplet[i][0];
        int col = triplet[i][1];
        int v = triplet[i][2];
        int idx = row_ptr[row];
        col_idx[idx] = col;
        val[idx] = v;
        row_ptr[row]++;
    }
    for (int i = num_rows; i > 0; i--) {
        row_ptr[i] = row_ptr[i-1];
    }
    row_ptr[0] = 0;
    
    // write sparse matrix to output array
    for (int i = 0; i < num_nonzeros; i++) {
        sparse[i][0] = col_idx[i];
        sparse[i][1] = row_ptr[col_idx[i]];
        sparse[i][2] = val[i];
        row_ptr[col_idx[i]]++;
    }
}