#include<stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node* next;
};

struct node* createNode(){
	return (struct node*)malloc(sizeof(struct node));
}

struct node* insertFront(struct node* front, int data){
	struct node* newNode = createNode();
	newNode->data = data;
	newNode->next = front;
	front = newNode;
	return front;
}

struct node* insertRear(struct node* rear, int data){
	struct node* newNode = createNode();
	newNode -> data = data;
	rear -> next = newNode;
	rear = newNode;
	return rear;
}

struct node* deleteFront(struct node* front){
	struct node* temp = front;
	front = front -> next;
	return front;
}

struct node* deleteRear(struct node* head,struct node* rear){
	struct node* temp = head;
	struct node* ptr = head;
	while (ptr -> next != NULL){
		temp = ptr;
		ptr = ptr -> next;
	}
	rear = temp;
	rear -> next == NULL;
	free(ptr);
	return head;
}

void displayQueue(struct node* head){
	struct node* ptr = head;
	while (ptr -> next != NULL){
		printf(" %d",ptr->data);
		ptr = ptr ->next;
	}
	printf(" %d",ptr->data);
	printf(" \n");
}

void main(){
	struct node* front = createNode();
	front -> data = 10;
	struct node* rear = front;
	int menu = 1;
	int choice ;
	while (menu = 1){
		printf("MENU \n 1.Insertion at front \n 2.Insertion at rear \n 3. Deletion at front \n 4. Deletion at rear  \n 5.Display  \n 6.Quit");
		printf("\nEnter you choice");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				front = insertFront(front,20);
				displayQueue(front);
				break;
			case 2:
				rear = insertRear(rear,40);
				displayQueue(front);
				break;
			case 3:
				front = deleteFront(front);
				displayQueue(front);
				break;
			case 4:
				rear = deleteRear(front,rear);
				displayQueue(front);
				break;
			case 5 :
				displayQueue(front);
				break;
			case 6:
			default:  menu = 0; break;
		}
	}

}
