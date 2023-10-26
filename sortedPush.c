#include <stdio.h>

typedef struct stack{
        int stack[100];
        int stackTop;
        int maxSize;
}s1;

struct stack push(struct stack s1,int a){
        if(s1.stackTop == s1.maxSize ){
                printf("Stack is already full cant push");

        }else if(s1.stackTop == -1){
                s1.stackTop = 0;
                s1.stack[s1.stackTop] = a;
        }

        else{
		if(s1.stackTop < a){
			int temp = s1.stack[s1.stacktop];
			s1.stack[s1.stackTop] = 0;
	                (s1.stackTop)--;
			
		}
                s1.stackTop++;
                s1.stack[s1.stackTop] = a;
        }
        return s1;
}

struct stack pop(struct stack s1){
        if (s1.stackTop == -1){
                printf("The stack is empty cant pop");
        }else{
                if(s1.stack[s1.stackTop] == s1.smallest[s1.smallestTop]){
                        s1.smallest[s1.smallestTop] = 0;
                        (s1.smallestTop)--;
                }
                s1.stack[s1.stackTop] = 0;
                (s1.stackTop)--;
        }
        return s1;
}

void display(struct stack s1){
        for(int i = 0; i<s1.stackTop; i++){
                printf("%d ",s1.stack[i]);
        }
}

void smallest(struct stack s1){
        printf(" \n Smallest value in stack is  %d  \n",s1.smallest[s1.smallestTop]);
}

void main(){
        int n;
        struct stack s1;
        s1.stackTop = -1;
        printf("Enter max size of the stack");
        scanf("%d",&s1.maxSize);

        int Menu = 1;
        while(Menu == 1){
        printf("Stack Menu \n 1.PUSH \n 2.POP \n  3.DISPLAY \n 4. Smallest value in stack 5.Exit \n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
                case 1:
                        printf("Enter element to push");
                        int pushX;
                        scanf("%d",&pushX);
                        s1 = push(s1,pushX);
                        break;
                case 2:
                        s1 = pop(s1);
                        break;
                case 3:
                        display(s1);
                        break;
                case 5:
                        Menu = 0;
                        break;
                case 4:
                        smallest(s1);
                        break;
                default:
                        printf("Invalid choice \n");
        }
        }
}



















