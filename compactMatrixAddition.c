
// Read 2 Sparse matrices and display them
// Convert both to Compact matrix and display 
// Add those 2 compact matrices and display the resultant compact matrix
// then find the transpose of that final resultant compact matrix and display it

#include <stdio.h>

void read_matrix(int rows, int cols, int matrix[rows][cols]) {
    printf("\n");
    for (int i=0; i < rows; i++) {
        printf("Enter row-%d: ", i+1);
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }   
    }
}

void display_matrix(int rows, int cols, int matrix[rows][cols]) {
    printf("\n");
    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }   
        printf("\n");
    }
}

void to_compact_matrix(int rows, int cols, int matrix[rows][cols], int compact[][3]) {
    compact[0][0] = rows; 
    compact[0][1] = cols; 
    compact[0][2] = 0;    

    int k=1;
    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            if (matrix[i][j] == 0) continue;
            compact[k][0] = i; 
            compact[k][1] = j;
            compact[k][2] = matrix[i][j];
            k++;
        } 
    }
    compact[0][2] = k - 1;
}

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int matrix1[rows][cols];
    int matrix2[rows][cols];
    
    printf("\nEnter first sparse matrix: ");
    read_matrix(rows, cols, matrix1);
    printf("\nEnter second sparse matrix: ");
    read_matrix(rows, cols, matrix2);
    
    printf("\nFirst Sparse Matrix: ");
    display_matrix(rows, cols, matrix1);
    printf("\nSecond Sparse Matrix: ");
    display_matrix(rows, cols, matrix2);
    
    int compact1[rows * cols][3];
    int compact2[rows * cols][3];
    
    to_compact_matrix(rows, cols, matrix1, compact1);
    to_compact_matrix(rows, cols, matrix2, compact2);
    
    printf("\nCompact Matrix 1:");
    display_matrix(compact1[0][2]+1, 3, compact1);
    printf("\nCompact Matrix 2:");
    display_matrix(compact2[0][2]+1, 3, compact2);

    int r1 = compact1[0][2]+1;
    int r2 = compact2[0][2]+1;
    
    int result[r1+r2-1][3];
    result[0][0] = rows; 
    result[0][1] = cols; 
    result[0][2] = 0;

    int i=1, j=1, k=1;
    while (i<r1 && j<r2) {

        if ( (compact1[i][0] < compact2[j][0]) || 
                (compact1[i][0] == compact2[j][0] && compact1[i][1] < compact2[j][1]) ) {
            result[k][0] = compact1[i][0];
            result[k][1] = compact1[i][1];
            result[k][2] = compact1[i][2];
            k++, i++;
        } 

        else if ((compact1[i][0] > compact2[j][0]) || 
                (compact1[i][0] == compact2[j][0] && compact1[i][1] > compact2[j][1])) {
            result[k][0] = compact2[j][0];
            result[k][1] = compact2[j][1];
            result[k][2] = compact2[j][2];
            k++, j++;
        }

        else {
            if (compact1[i][1] == compact2[j][1]) {
                result[k][0] = compact1[i][0];
                result[k][1] = compact1[i][1];
                result[k][2] = compact1[i][2] + compact2[j][2];
                k++, i++, j++;
            }
        }
    }

    while (i < r1) {
        result[k][0] = compact1[i][0];
        result[k][1] = compact1[i][1];
        result[k][2] = compact1[i][2];
        k++, i++;
    }
    while (j < r2) {
        result[k][0] = compact2[j][0];
        result[k][1] = compact2[j][1];
        result[k][2] = compact2[j][2];
        k++, j++;
    }

    result[0][2] = k - 1;

    printf("\nResultant Compact Matrix:");
    display_matrix(k, 3, result);

    int transposeMat[3][k];
    for (int i=0; i<k; i++) {
        for (int j=0; j<3; j++) {
            transposeMat[j][i] = result[i][j];
        }
    }
    printf("\nTranspose of Resultant Compact Matrix:");
    display_matrix(3, k, transposeMat);

    return 0;
}
