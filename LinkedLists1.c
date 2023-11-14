#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
};

struct node* newNode(){
	return (struct node*)malloc(sizeof(struct node));
}

void addNode(struct node* head,int data){
	struct node* ptr = head;

	if (ptr->data == NULL){
		ptr->data = data;
	}else{
		while (ptr->next != NULL){
			ptr = ptr->next;
		}
		struct node* newN = newNode();
		ptr->next = newN;
		ptr->next->data = data;
	}
}

void insertNodeAfter(struct node* head, int data,int target){
	struct node* ptr = head;
	if (ptr->data == NULL){
                ptr->data = data;
        }else{
		while(ptr->data != target && ptr->next != NULL){
			ptr = ptr->next;
		}
		struct node* newN = newNode();
		newN->next = ptr->next;
		newN->data = data;
		ptr->next = newN;
	}
}

void insertNodeBefore(struct node* head, int data,int target){
	struct node* ptr = head;
	if (ptr->data == NULL){
                ptr->data = data;
        }else if(ptr->data == data){
		struct node* newN = newNode();
		newN->next = ptr;
		newN->data = data;
		head = newN;
		ptr = ptr->next;
	}
	else{
		while(ptr->next->data != target && ptr->next->next != NULL){
			ptr = ptr->next;
		}
		struct node* newN = newNode();
		newN->next = ptr->next;
		newN->data = data;
		ptr->next = newN;
	}
}

void insertNodeIndex(struct node* head, int data, int index){
	struct node* ptr = head;
	int n = 0;
	while (n+1 != index && ptr->next != NULL){
		ptr = ptr->next;
		n++;
	}
	struct node* newN = newNode();
	newN->next = ptr->next;
	ptr->next = newN;
	newN->data = data;
}

void deletionData(struct node* head, int target){
	struct node* ptr = head;
	struct node* prev = ptr;
	if (ptr->data == target){
		head = ptr->next;
		free(ptr);
	}else{
		while(ptr->data != target && ptr->next != NULL){
			prev = ptr;
			ptr = ptr->next;
		}
		if (ptr->next == NULL){
			free(ptr);
			prev->next = NULL;
		}else{
			prev->next = ptr->next;
			free(ptr);
		}

	}
}


void displayList(struct node* head){
	printf("THe current linked list is ");
	struct node* ptr = head;
	while (ptr->next != NULL){
		printf(" %d",ptr->data);
		ptr = ptr->next;
	}
	printf(" %d ",ptr->data);
}

void main(){
	printf("Enter number of nodes you want to add  right now");
	struct node* head = newNode();
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		int d;
		printf("ENter daata");
		scanf("%d",&d);
		addNode(head,d);
	}
	displayList(head);
	printf("Insertion \n");
	int target,insertData;
	//printf("Input Data to delete: ");
	scanf("%d\n%d ",&target,&insertData);
	//deletionData(head,target);
	//insertNodeIndex(head,insertData,target);
	insertNodeAfter(head,insertData,target);
	//insertNodeAfter(head,insertData,target);
	displayList(head);
	
}
