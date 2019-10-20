#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}*node;
//typedef Node* node;

// Node = n    data = x     
// node = node   next = next

void bastir(node r){		//
	r = r-> next;
	while(r!= NULL){
		printf("%d ",r->data);
		r=r->next;
	}
}
void ekle(node r,int x){
	while(r->next != NULL){
	r = r -> next;
	}
	r -> next = (node*)malloc(sizeof(struct Node));
	r = r->next;
	r -> data = x;
	r -> next = NULL;

}
node getnode(){
	node newnode;
	newnode = (node)malloc(sizeof(struct Node));
	newnode -> next = NULL;
	return newnode;
}

void pop(node root,int info){
	node temp;
	if(root == NULL || root->next == NULL){
		printf("list empty\n");
		exit(1);
	}else if(root->next == NULL){
		free(root);
		printf("free root");
	}
	while(root -> next ->data != info){
		root = root ->next;
	}
	temp = root ;	
	root ->next = root -> next -> next;
	free(temp->next);
	printf("%d elemani pooped",info);
}
void search(node root, int x){
	node p;
	int i=0;
	for(p = root;p!=NULL;p = p -> next){
		if(p -> data == x){
			printf("%d verisi listenin %d inci elemani",x,--i);
		}
		i++;
	}
	//printf("%d elemani bu listede bulunamadi !!",x);
}	
	

int main(){
	node a = getnode();
/*	node * root;
	root=(node*)malloc(sizeof(node));
	root -> data = 500;
	root -> next = NULL;*/
	/*
	root -> next = (node*)malloc(sizeof(node));
	root -> next -> data = 20;
	root -> next -> next = (node*)malloc(sizeof(node));
	root -> next -> next -> data = 30;
	root -> next -> next -> next = NULL;
	
	printf("%d",iter->data);
	iter = iter -> next;
	printf("%d",iter -> data);
	*/
//	node * iter;
	//iter = root;
/*	while(iter -> next != NULL){
		printf("%d",iter->data);
		iter = iter -> next;	
	}*/
	int i;
	ekle(a,2);
	for(i = 0;i<5;i++){
	//	ekle(a, i*10);
		/*
		iter -> next = (node*)malloc(sizeof(node));
		iter = iter ->next;
		iter -> data  = i*10;
		iter -> next = NULL;
		*/
	}
	bastir(a);
	pop(a,40);
	bastir(a);
	search(a,2);
	bastir(a);
}
