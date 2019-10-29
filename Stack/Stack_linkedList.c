#include <stdio.h>
#include <stdlib.h>		// for malloc



//null <- 10 <- 20(head)

typedef struct Stack{
	int data;
	struct Stack * next;
}stack;

void push(stack ** head,int x){

	stack * temp = (stack*)malloc(sizeof(stack));
	temp->data = x;
	temp-> next = *head;
	*head = temp;
}
void peek(stack *head){
	if(head == NULL){
		printf("Stack is empty !!");
		
	}else{
	printf("%d",head->data);
}
}

void pop(stack **head){
	if(*head == NULL){
		printf("There are no element to delete !!");
		return;
	}
	stack *temp = *head;
	*head = temp->next;
	free(temp);
}

void printStack(stack * head){
	if(head == NULL){
	printf("Stack is empty !!");
	return;
	}
	while(head != NULL){
		printf("%d",head->data);
		head = head->next;
	}
	
}
int main(){
	
	stack * head = NULL;
	
	push(&head,1);
	push(&head,2);
	push(&head,3);
	pop(&head);
	push(&head,4);
	pop(&head);
	push(&head,5);
	peek(head);
	printStack(head);
		push(&head,6);
	peek(head);
	
	
	
}
