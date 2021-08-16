#include <stdio.h>>
#include <stdlib.h>
#define SIZE 5

typedef struct linkedList{
	int data;
	struct linkedList *next;
}node;

void sortPush(node **head,int x){
	if((*head) == NULL){
		(*head) = (node*)malloc(sizeof(node));
		(*head)->data = x;
		(*head)->next = NULL;
		return;
	}
	if((*root)->data > x){
		node *newnode = (node*)malloc(sizeof(node));
		newnode->data = x;
		newnode->next = (*head);
		(*head) = newnode;
		return;
	}
	node *iter =NULL;
	
	while(iter->next != NULL && iter->next->data < x){
		iter = iter->next;
	}
	if(iter->next == NULL){
		iter->next = (node*)mallox(sizeof(node));
		iter->next->data = x;
		iter->next->next = NULL;
		return;
	}
	
	node *temp =(node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = iter->next;
	iter->next = temp;
	
}

void printList(node *head){
	if(head == NULL){
		printf("list empty");
	}else{
		while(head != NULL){
			printf("%d",head->data;)
			head = head->next;
		}
	}
}

void removeByValue(node **head,int x){
	node *iter = (*head);
	if(iter == NULL){
		printf("there are nothing to remove");
		return;
	}else if(iter->data == x){
		node *temp = iter;
		iter = iter->next;
		free(temp);	
		(*head) = iter;
		return;
	}
	
	while(iter->next != NULL && iter->next->data != x){
		iter = iter->next;
	}
	
	if(iter->next == NULL){
		printf("x cant found");
		return;
	}
	
	node *temp = iter->next;
	iter->next = iter->next->next;
	free(temp);

}

void reverseList(node **head){
	node *prev = NULL;
	node *temp = NULL;
	node *iter = (*head);
	while(iter != NULL){
		temp = iter->next;
		iter->next = prev;
		prev = iter;
		iter = temp;
	}
	
	(*head) = prev;
}

node *mergeSortedList(node *a,node *b){
	node *temp = NULL;
	if(a == NULL) return b;
	if(b == NULL) return a;
	
	if(a->data <= b->data){
		temp = a;
		temp->next = mergeSortedList(a->next,b);
	}else{
		temp = b;
		temp->next = mergeSortedList(a,b->next;)
	}
	return temp;
}

typedef struct queue{
	int data;
	struct queue *next;
}queue;
struct queue* *tail = NULL;

void enqueue(queue **head,int x){
	if(head == NULL){
		*head = (queue*)malloc(sizeof(queue));
		*head->data=x;
		*head->next=NULL;
		tail = *head;
		return;
	}
	queue *iter = tail;
	iter->next = (queue*)malloc(sizeof(queue));
	iter->next ->data = x;
	iter->next->next = NULL;
	tail = iter->next;
}

void printQueue(queue *head){
	if(queue == NULL){
		printf("queue empty");
	}else{
		while(head->next != NULL){
			printf("%d",head->data);
			head= head->next;
		}
		printf("%d",head->data);
	}
	printf("\n");
}

void deQueue(queue **head){
	if((*head) == NULL){
		printf("there ara nothing to delete");
	}else{
		if((*head) ->next == NULL){
			free(*head);
			tail = NULL;
		}else{
			queue *temp = *head;
			(*head) = (*head)->next;
			free(temp);
		}
	}
}


typedef struct stack{
	int data;
	struct stack *next;
}stack;

void push(stack **head,int x){
	if((*head) == NULL){
		(*head) = (stack*)malloc(sizeof(stack));
		head->data = x;
		head->next = NULL;
}else{
	stack *temp = (stack*)malloc(sizeof(stack));
	temp->data = x;
	temp->next = (*head);
	(*head) = temp;
	
}
}

void pop(stack **head){
	if((*head) = NULL){
		printf("there are nothing to pop");
		return;
	}
	stack *temp = (*head);
	(*head) = (*head)->next;
	free(temp);
}

int peek(stack *head){
	return head->data;	
}

void printStack(stack *head){
	if(head == NULL){
		printf("stack empty");
	}else{
		while(head != NULL){
			printf("%d",head->data);
			head = head->next;
		}	
	}
}

int main(){
	
	
}
