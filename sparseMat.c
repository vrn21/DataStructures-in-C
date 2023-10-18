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
void printMat(int mat[][100], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void printSparseMat(int sparseMatTranspose[][100]){
     for (int i = 0; i <= sparseMatTranspose[0][2]; i++) {
        printf("%d %d %d\n", sparseMatTranspose[i][0], sparseMatTranspose[i][1], sparseMatTranspose[i][2]);
    }
}
void convertToSparseMatrix(int matrix[][100], int rows, int cols, int sparseMatrix[][3]) {
    
    // Set the dimensions of the sparse matrix
    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;

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
    sparseMatrix[0][2] = k-1;
}




void sparseAdd(int sparseA[100][3], int sparseB[100][3], int sparseSum[100][3]){
	sparseSum[0][0] = sparseA[0][0];
    sparseSum[0][1] = sparseA[0][1];

	int k = 1;
	for(int i =1; i<sparseA[0][2]; i++){
		for(int j =1; j<sparseB[0][2]; j++){
                if (sparseA[i][0] == sparseB[j][0] && sparseA[i][1] == sparseB[j][1]){
                    sparseSum[k][2] = sparseA[i][2] + sparseB[j][2];
                    sparseSum[k][0] = sparseA[i][0];
                    sparseSum[k][1] = sparseA[i][1];
                    k++;
                }
                else{
                    sparseSum[k][2] = sparseA[i][2];
                    sparseSum[k][0] = sparseA[i][0];
                    sparseSum[k][1] = sparseA[i][1];
                    k++;
                    sparseSum[k][2] = sparseB[j][2];
                    sparseSum[k][0] = sparseB[j][0];
                    sparseSum[k][1] = sparseB[j][1];
                    k++;
                }

            }
		}
      sparseSum[0][2] = k-2;  
	}
	
void sparseTranspose(int sparseA[100][3], int transposeA[100][3]){
    transposeA[0][0] = sparseA[0][0];
    transposeA[0][1] = sparseA[0][1];
    transposeA[0][2] = sparseA[0][2];

    for (int i = 0; i < sparseA[0][2]; i++){
        int temp = sparseA[i][0];
        sparseA[i][0] = sparseA[i][1];
        sparseA[i][1] = temp;
    }

    printMat(sparseA, sparseA[0][2], 3);
    int smallest = 1;
    for (int i = 1; i <= sparseA[0][2]; i++){
        for (int j = 1; j <= sparseA[0][2]; j++){
            if (sparseA[j][0] < sparseA[smallest][0]){
                int temp1 = sparseA[smallest][0];
                int temp2 = sparseA[smallest][1];
                sparseA[smallest][0] = sparseA[j][0];
                sparseA[smallest][1] = sparseA[j][1];
                sparseA[j][0] = temp1;
                sparseA[j][1] = temp2;
                smallest = j;
            }
            else if(sparseA[j][0] == sparseA[smallest][0]){

                if (sparseA[j][1] < sparseA[smallest][1]){
                    int temp1 = sparseA[smallest][0];
                    int temp2 = sparseA[smallest][1];
                    sparseA[smallest][0] = sparseA[j][0];
                    sparseA[smallest][1] = sparseA[j][1];
                    sparseA[j][0] = temp1;
                    sparseA[j][1] = temp2;
                    smallest = j;
                }   


            }
        }

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

    printf(" \nTranspose \n");
    int sparseMatTranspose[100][3];
    sparseTranspose(sparseMat, sparseMatTranspose);
   

    printf("\n");
    for (int i = 0; i <= sparseMatTranspose[0][2]; i++) {
        printf("%d %d %d\n", sparseMatTranspose[i][0], sparseMatTranspose[i][1], sparseMatTranspose[i][2]);
    }
    
    printf("Enter second matrix details");
    printf("Both matrices must be of same size");
    int matB[100][100],sparseB[100][3];
    createMat(matB, row, col);
    printMat(matB,row,col);
    convertToSparseMatrix(matB, row, col, sparseB);
    for (int i = 0; i <= sparseB[0][2]; i++) {
        printf("%d %d %d\n", sparseB[i][0], sparseB[i][1], sparseB[i][2]);
    }
    int sparseSum[100][3];
    sparseAdd(sparseMat, sparseB,sparseSum);
    printf("\n");
    for (int i = 0; i <= sparseSum[0][2]; i++) {
        printf("%d %d %d\n", sparseSum[i][0], sparseSum[i][1], sparseSum[i][2]);
    }
    
    
    return 0;
}



