#include <stdio.h>
#define SIZE 5

typedef struct Queue{
	int size, front ,rear,dimension;
	int *arr;
}queue;

queue* createQueue(int capacity){
	queue * newqueue = (queue*)malloc(sizeof(queue));
	newqueue-> dimension = capacity;
	newqueue-> size = 0;
	newqueue-> front = -1;
	newqueue-> rear = -1;
	newqueue->arr = (int*)malloc(sizeof(int)*newqueue->dimension);
	return newqueue;
}

int isEmpty(queue *head){
	return (head->size == 0);
}
int isFull(queue *head){
	return (head->size == head->dimension);
}

void enQueue(queue *head,int x){
	if(isEmpty(head)){
		head->size = 1;
		head->front = 0;
		head -> rear = 0;
		head->arr[head->rear] = x;
	}else if(isFull(head)){
		printf("There ara no place to insert an element !!");
	}else{
		head->size++;
		head->rear++;
		head->arr[head->rear] = x;
	}
	
}

void printQueue(queue *head){
	
	if(isEmpty(head)){
		printf("Queue is empty !!");
		return;
	}
	int i;
	for(i=head->front;i<=head->rear;i++){
		printf("%d",head->arr[i]);
	}
}

void deQueue(queue **head){
	queue * temp = *head;
	temp->size--;
	temp->front++;
	*head = temp;
	shift(head);
}

void shift(queue **head){
	queue *temp = *head;
	int i;
	for(i = temp->front;i>0;i--){
		temp->front--;
		temp->rear--;
		*head = temp;
	}
}

int main(){
	queue * head = createQueue(6);
	
	
	enQueue(head,1);
	enQueue(head,2);
	enQueue(head,3);
	enQueue(head,4);
	deQueue(&head);
	printQueue(head);
	printf("%d",head->arr[0]);
	printf("%d",head->arr[2]);
}
