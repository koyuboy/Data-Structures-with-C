#include <stdio.h>
#define SIZE 5

typedef struct Stack{
	int top;
	int m_arr[SIZE];
}stack;

void push(stack *head,int x){
	if(head->top +1 == SIZE){
		printf("Stack is full!!");
		return;
	}
	head->top++;
	head->m_arr[head->top]=x;
}

void printStack(stack *head){
	if(head->top == -1){
		printf("Stack is empty !!");
		return;
	}
	int i;
	for(i = 0;i<=head->top;i++){
		printf("%d",head->m_arr[i]);
	}
}

void pop(stack  *head){
	if(head->top == -1){
		printf("There are no element to delete !!");
		return;
	}
	head->top--;
	
}

void peek(stack *head){
	printf("%d =>TOP",head->m_arr[head->top]);
}
int main(){
	stack head;
	head.top = -1;
	
	push(&head,1);
	push(&head,2);
	pop(&head);
	push(&head,3);
	printStack(&head);
	peek(&head);
	
	
	
	
}
