#include <stdio.h>
#include <stdlib.h>
//	int top =-1;
//	int size = 0;
typedef struct Stack{
	int top;
	int size;
	int *arr;
}stack;

	
void push(struct Stack *stack,int a){
	stack->arr  = (int*)malloc(sizeof(int));
	
	
}


void print(){
	
}

int main() {
	struct Stack st;
	printf("%d", st.top);

}
