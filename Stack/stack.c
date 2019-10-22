


// 60. satýrdaki hata  ve  isEmpty() ekle    ve  GÝT e atmayý unutma !!    


#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
	int data;
	int counter;
//	struct Stack * tail;  // tail behaves like iterator, it follows position of (counter stack) -1 !!
	struct Stack * next;
}Stack;
int counter = -1;

Stack * push(Stack *s,int x){
	if(s == NULL){
		s = (Stack*)malloc(sizeof(Stack));
		counter = 0;
		s->counter = counter;
		s -> next = NULL;
		s -> data = x;
		printf("bir\n");
		return s;
	}else{
	Stack *iter = s;
	while(iter->next != NULL){
		iter = iter ->next;
	}
	
	Stack *	temp = (Stack*)malloc(sizeof(Stack)); 
	temp->counter = ++counter;
	temp -> next = NULL;
	temp -> data = x;
	iter -> next = temp;
	
	printf("iki\n");
	return s;
	}
}

void printStack(Stack * s){
	if(counter == -1){
		printf("Stack is empty");
	}else{
	Stack * iter = s;
	int i;
	for(i=0; i<=counter;i++){
		printf("%d",iter->data);
		iter = iter -> next;
	}
}
}
void pop(Stack *s){
	if(counter == -1){//ok
		printf("stack is empty");
		//return -1;
	}else if(s -> next == NULL){//ok
		int r_value = s -> data;
		free(s);
		counter--;
		//return r_value;
		//printf("asadadasa");
	}else{// null ve 1 ve 2 eleman varsa çalýþýyor ---  3 elemanda çalýþmýyor ??
	
	Stack *iter = s;
	while(s->next->next != NULL){
		iter = iter -> next;
	}
	
	Stack *temp = iter ->next;
	int r_value = temp -> data;
	free(temp);
	iter -> next = NULL;
	counter--;
//	return r_value;
}
}


int main(){
	Stack *stack = NULL;
	stack = push(stack,1);
	stack = push(stack,2);
	stack = push(stack,3);
//	printf("%d",stack ->next -> next->data);
//	printf("%d",pop(stack));
    pop(stack);
	printStack(stack);
//	printf("ss");
	//printf("%d->",stack->counter);
	//printf("%d->\n",stack->next ->counter);
	//printf("%d->\n",stack-> next-> next ->counter);
	//printf("%p\n",stack->tail);
	//printf("%p\n",stack->next->next);
	
}

