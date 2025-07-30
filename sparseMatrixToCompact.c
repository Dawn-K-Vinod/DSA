/*
Description: This program reads a sparse matrix from the user,
             converts it to a compact representation,
             and displays both the original and compact form.
*/

#include <stdio.h>

// Function to read a matrix from user input
void read_matrix(int rows, int cols, int mat[rows][cols]) {
    printf("Enter the elements of the matrix:\n");
    for (int i=0; i<rows; i++) {
        printf("Row %d: ", i + 1);
        for (int j=0; j<cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display a matrix
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

    // Input the size of the matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Declare the sparse matrix
    int sparse[rows][cols];

    // Read the sparse matrix from user
    read_matrix(rows, cols, sparse);

    // Display the original sparse matrix
    printf("\nThe given Sparse matrix:\n");
    display_matrix(rows, cols, sparse);

    // Prepare compact representation array:
    // Each row stores: [row_index, col_index, value]
    // First row stores: [rows, cols, number of non-zero elements]
    int sparse_compact[rows * cols][3];
    sparse_compact[0][0] = rows; // store total rows
    sparse_compact[0][1] = cols; // store total cols

    int k=1; // Index for compact matrix rows
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (sparse[i][j]!=0) { // If element is non-zero
                sparse_compact[k][0] = i;      // store row index
                sparse_compact[k][1] = j;      // store col index
                sparse_compact[k][2] = sparse[i][j]; // store value
                k++;
            }
        }
    }
    sparse_compact[0][2] = k-1; // Store count of non-zero elements

    // Display the compact representation
    printf("\nCompact representation of the sparse matrix:\n");
    display_matrix(k, 3, sparse_compact);

    return 0;
}
