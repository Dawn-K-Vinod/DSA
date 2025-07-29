/*
Description: This program reads a sparse matrix from the user,
                converts it to a compact representation,
                and displays both the original and compact form.
*/

#include <stdio.h>

void read_matrix(int rows, int cols, int mat[rows][cols]) {
    printf("Enter the elements of the matrix:\n");
    for (int i=0; i<rows; i++) {
        printf("Row %d: ", i + 1);
        for (int j=0; j<cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void display_matrix(int rows, int cols, int mat[][cols]) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}  

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    //Sparse matrix//
    int sparse[rows][cols];
    read_matrix(rows, cols,sparse);
    printf("\nThe given Sparse matrix:\n");
    display_matrix(rows, cols, sparse);

    //Compact representation//
    int sparse_compact[rows * cols][3];
    sparse_compact[0][0] = rows;
    sparse_compact[0][1] = cols;
    
    int k=1;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (sparse[i][j]!=0) {
                sparse_compact[k][0] = i; 
                sparse_compact[k][1] = j;
                sparse_compact[k][2] = sparse[i][j];  
                k++;
            }
        }
    }
    sparse_compact[0][2] = k-1;
    printf("\nCompact representation of the sparse matrix:\n");
    display_matrix(k, 3, sparse_compact);
    return 0;
}