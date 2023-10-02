#include<stdio.h>


void insertion(int arr[], int n, int insertElement, int insertIndex ){
  for (int j = 0 ;j<n;j++) {
    if (j == insertIndex){
      printf("%d ",insertElement);
      
    }
    printf("%d ",arr[j] );
  }
  if (insertIndex>=n){printf("%d",insertElement);}
}

void deletion (int arr[], int n, int deletionIndex){
  for (int j = 0 ;j<n;j++) {
    if (j != deletionIndex){
      printf("%d ",arr[j]);
    }

  }
}

int main(){
  
  int array[100],n,choice,x,y,z;
  printf("ENter size of array \n");
  scanf("%d",&n);  
  for (int i =0;i<n;i++) {
    printf("Enter elements in the array\n");
    scanf("%d",&array[i]);
  }
  printf("Which Function do you want to perform on the new array?\n");
  printf("1. Insertion\n");
  printf("2. Deletion\n");
  printf("Enter your choice: \n");
  scanf("%d",&choice);
  switch (choice) {
    case 1:
      printf("Which element do you want to add: \n");
      scanf("%d",&x);
      printf("At which index do you want to add:\n");
      scanf("%d",&y);
      insertion(array,n,x,y);
      break;

    case 2 :
      printf("Which index do you want to delete: \n");
      scanf("%d",&z);
      deletion(array,n,z);
      break;

    default : 
      printf("Invalid choice");  
      break;
  }
}
