#include <stdio.h>

struct queue{
        int queue[100];
        int front;
        int rear;
        int maxSize;
};

struct queue enqueue(struct queue q,int a){
        if (q.front == (q.rear + 1)%q.maxSize ){
                printf("Queue full \n ");
        }else if (q.front == -1 && q.rear == -1 ) {
		q.front = 0;
                q.queue[++(q.rear)] = a;
        }else{
		q.rear = (q.rear + 1)%q.maxSize;
                q.queue[q.rear] = a;
        }
        return q;
}

struct queue dequeue(struct queue q){
        if (q.front == -1){
                printf("Queue empty \n ");
        }else if (q.front == q.rear){
		q.front = -1;
		q.rear = -1;
	}else {
                q.front = (q.front + 1)%q.maxSize;
        }
	return q;
}

void display(struct queue q){
        printf("The queue is  \n");
        for (int i = q.front; i != q.rear; i=(i+1)%q.maxSize){
                printf(" %d ",q.queue[i]);
        }
}

int main(){
        struct queue Q;
        Q.front = -1;
        Q.rear = -1;
        printf("Enter max size of Queue");
        scanf("%d",&Q.maxSize);
        printf(" \n MENU \n 1.Enqueu \n 2.Dequeue \n 3.Display \n ");
        int choice;
        int c = 1;
        while(c == 1){
        printf("Enter your choice");
        scanf("%d",&choice);
        switch(choice){
                case 1:
                        printf("Enter element to Enqueue");
                        int a;
                        scanf("%d",&a);
                        Q = enqueue(Q,a);
                        break;
                case 2:
                        Q = dequeue(Q);
                        break;
                case 3 :
                        display(Q);
                        break;
                case 4 :
                        c = 0;
                        break;
        }
        }
}
















