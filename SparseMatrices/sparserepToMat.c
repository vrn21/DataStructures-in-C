#include<stdio.h>

void displayMat(int mat[][]){
	for(int i = 0; i<mat[0][0]; i++){
		for(int j = 0; j<mat[0][1]; j++){
			int count = 0;
			for(int k = 1; k<mat[0][2]; k++){
				//check mat[i][0] s for i and mat[i][1] for j k=1 because of first row being the size
				if(mat[k][0] == i){
					if(mat[k][1] == j){
						printf("%d ",&mat[k][2]);
						count++;
					}
				}
		
			}
			if (count == 0){
				printf("0 ");
			}
		}
	}

}

int linearSearch(int m[], int x, int n){
	for(int i =0; i<n;i++){
		if(m[i] == x){
			return 1;
		}
	}
	return 0;
}

void main(){
	int mat[100][3];
	printf("Enter size of sparse matrix");
	printf("Rows");
	scanf("%d",&mat[0][0]);
	printf("Columns");
	scanf("%d",&mat[0][1]);
	printf("Enter number of non zero matrix elements ");
	scanf("%d",&mat[0][2]);
	for(int i = 0; i < mat[0][2]; i++){
		printf(" \nEnter co-ordinates of %d element \n",i);
		printf("Row number:");
		scanf("%d",&mat[i][0]);
		printf("Column number:");
		scanf("%d",&mat[i][1]);
		printf("Value:");
		scanf("%d",&mat[i][2]);
	}
	printf("Matrix input succes!\n");
	printf("The matrix is \n");
	displayMat(mat);


}
