

//  front of queue    (head)1->2->3(tail)->NULL	end of queue

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
	int data;
	struct Queue *next;
	
}queue;
struct Queue *tail;
void enQueue(queue ** head,int x){
	if(*head == NULL){
		queue *temp = (queue*)malloc(sizeof(queue));
		temp->data = x;
		temp->next = NULL;
		*head = temp;
		tail = *head;
		return;
	}
	queue *iter = tail;
	iter -> next = (queue*)malloc(sizeof(queue));
	iter->next->data= x;
	iter->next->next = NULL;
	tail = iter->next;
}


void printQueue(queue *head){
	if(head == NULL){
		
		printf("Queue is empty !!");
	}else{
		while(head->next != NULL){
			printf("%d",head->data);
			head = head->next;
		}
		printf("%d",head->data);
	}
	printf("\n");
}

void deQueue(queue **head){
	if(*head == NULL){
		printf("Queue is already empty !!");
	}else{
		queue *temp = *head;
		if(temp->next == NULL){
			free(temp);
			free(tail);
			*head = NULL;
		}else{
			*head = temp->next;
			free(temp);
		}
	}
	
}

int getHead(queue *head){
	return head->data;
}

int getTail(queue *head){
	return tail->data;
}

int main(){
	
	queue *head = NULL;
	
	enQueue(&head,1);
	enQueue(&head,2);
	deQueue(&head);
	enQueue(&head,3);
	//deQueue(&head);
	
	printQueue(head);
	
	printf("head->%d________tail->%d",getHead(head),getTail(head));
	
}
