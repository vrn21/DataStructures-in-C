#include <stdio.h>

void createMat(int mat[][100], int row, int col){
    printf("Enter your matrix");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("Enter element at %d, %d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Matrix input successful \n");
}

void convertToSparseMatrix(int matrix[][100], int rows, int cols, int sparseMatrix[][3]) {
    int count = 0;

    // Count the number of non-zero elements in the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }

    // Set the dimensions of the sparse matrix
    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;
    sparseMatrix[0][2] = count;

    int k = 1;

    // Store the non-zero elements of the matrix in the sparse matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }
}

void printMat(int mat[][100], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int row, col;
    printf("Enter your matrix details\n");
    printf("Rows: ");
    scanf("%d", &row);
    printf("Columns: ");
    scanf("%d", &col);
    int matrix[100][100], sparseMat[100][3];
    createMat(matrix, row, col);
    printMat(matrix, row, col);
    convertToSparseMatrix(matrix, row, col, sparseMat);
    printf("\n\nSparse Matrix is:\n");
    for (int i = 0; i <= sparseMat[0][2]; i++) {
        printf("%d %d %d\n", sparseMat[i][0], sparseMat[i][1], sparseMat[i][2]);
    }
    float sparcity = (float)sparseMat[0][2]/(sparseMat[0][0]*sparseMat[0][1]);
    printf("The sparcity of the matrix is %f", sparcity);
    
    printf("Enter second matrix details");
    
    
    
    
    
    return 0;
}
