#include<stdio.h>


void insertion(int arr[], int n, int insertElement, int insertIndex ){
  for (int j = 0 ;j<n;j++) {
    if (j == insertIndex){
      printf("%d ",insertElement);
      
    }
    printf("%d ",arr[j] );
  }
}

void main(){
  
  int array[100],n;
  printf("ENter size of array \n");
  scanf("%d",&n);  
  for (int i =0;i<n;i++) {
    printf("Enter elements in the array\n");
    scanf("%d",&array[i]);
  }
   insertion(array,n,69,0);
}
