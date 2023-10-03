#include <stdio.h>

void printArray(int arr[], int n){
	printf("Current state of array is ");
	for (int k = 0; k<n; k++){printf(" %d",arr[k]);}
	printf("\n \n");
}


void linearSearch(int arr[], int n, int a){
	int choice = 0;
	for(int i = 0;i<n;i++){
		printf("Checking whether element %d and %d are equal or not index %d \n",arr[i],a,i);
		if (arr[i] == a ){
			printf("\n \n");
			printf("Element found at index %d\n ",i);
			choice = 1;
			printf("\n \n");
		}
	}
	if (choice == 0){
		printf("\n \n");
		printf("Not found");
		printf("\n \n");
	}
}


void binarySearch(int arr[] , int n, int a ){
	int f,m,l;
	l = n-1;
	f = 0;
	m = (l+f)/2;
	while (f<=l){
		printf("Looking at element %d at index %d  \n",arr[m],m);
		if (arr[m] > a){
			l = m;
		}if (arr[m] < a){
			f = m;
		}if (arr[m] == a){
			printf("Element found at %d index ",m);
			f = 100000;
		}
	m = (l+f)/2;

	}

}


void bubbleSort(int arr[], int n){
	int temp;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n-1-i;j++){
			printf("Comparing elements %d and %d  at index %d and %d \n ",arr[j],arr[j+1],j,j+1);
			if (arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				printf("\n Elements %d and %d are swapped \n",arr[j],arr[j+1]);
				printArray(arr,n);
			}
		}
	}

}

void selectionSort(int arr[], int n){
	int largestIndex = 0,temp;
	for (int i = 0; i<n; i++){
		for(int j = 0; j<n-1-i; j++){
			printf("Comparing elements %d and largest number till now %d  \n",arr[j],arr[largestIndex]);
			printArray(arr,n);
			if (arr[j] > arr[largestIndex]){
				largestIndex = j;
				printf("Largest number changed to %d \n ",arr[largestIndex]);
			}
		}
		printf("Largest number %d  and  %d are swapped \n",arr[largestIndex],arr[n-1-i]);
		temp = arr[n-1-i];
		arr[n-1-i] = arr[largestIndex];
		arr[largestIndex] = temp;
		largestIndex = 0;
	}
	printf("Sorting completed \n");
	printArray(arr,n);

}


int main(){

	int n,array[100],x;
	printf("Enter size of array:");
	scanf("%d",&n);
	for (int i = 0;i<n;i++){
		printf("ENter elements:");
		scanf("%d",&array[i]);
	}
	printf("\n \n");
	printf("Enter element to search");
	scanf("%d",&x);
	//linearSearch(array,n,x);
	//bubbleSort(array, n);
	//selectionSort(array, n);
	binarySearch(array,n,x);
}

