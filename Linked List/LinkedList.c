#include <stdlib.h>	//for malloc
#include <stdio.h>

typedef struct Node{	
	int data;
	struct Node* next;
}node;

void init(node * root, int x){	// give value of first node
	root -> data = x;
	root -> next = NULL;
}

void pushEnd(node* root, int x){  //add end of the list 
	
		node* iter = root;
		while(iter->next != NULL){
			iter = iter->next;
		}
		iter->next = (node*)malloc(sizeof(node));
		iter->next->data =x;
		iter ->next->next=NULL;	
}
void pushStart(node ** root_ref,int x){	// add  beginning of the list,,, root_ref is a pointer to point beginning adress of root
	node * newnode=(node*)malloc(sizeof(node));
	newnode -> next = *root_ref;
	newnode -> data = x;
	*root_ref = newnode;
	
}
void pushAfterNode(node * root,int x,int index){ // add  after given index
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	int i;
	for(i=0;i<index;i++){
		root = root->next;
	}
	while(root->next->data != x){
		root = root->next;
	}
	node * temp = root->next;
	root->next = newnode;
	newnode->next = temp;
	
}

void sortPush(node ** root,int x){
	
	if((*root)==NULL){
		*root =(node*)malloc(sizeof(node));
		(*root)->next = NULL;
		(*root)->data = x;
		return;
	}
	if((*root)->data > x){
		node * newnode =(node*)malloc(sizeof(node));
		newnode->next = (*root);
		newnode->data = x;	
		(*root) = newnode;
		return;
	}
	
		node *iter = *root;

		while(iter->next != NULL  &&  iter->next->data <= x  ){
			iter = iter->next;
		}
		if(iter->next == NULL){
			iter->next = (node*)malloc(sizeof(node));;
			iter->next->data = x;
			iter->next->next = NULL;
			return;
		}
		node *temp=(node*)malloc(sizeof(node));
		temp->data = x;
		temp ->next= iter->next;
		iter->next = temp;
	
}
	

void printList(node *root){		// print out elements of list
	node * iter = root;
	printf("Your List:\n");
	if(root==NULL){
		printf("List is empty!!\n");
		
	}else{
		while(iter != NULL){
			printf("%d ",iter->data);
			iter = iter->next;
		}
		printf("\n");
	}
}

void removeStartNode(node **root){ // remove beginning node of list 
	
	node *temp =NULL;
	temp = (*root)->next;
	free(*root);
	(*root) = temp;
}

void removeEndNode(node *root){		// remove end node of list
	node * temp = root;
	while(temp -> next->next!=NULL){
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

void removebyValue(node *root, int x){	//remove given node of list
	node *iter = root;
	while(iter -> next -> data != x){
		iter = iter->next;
	}
	node * temp = NULL;
	temp = iter -> next;
	iter->next = iter -> next -> next;
	free(temp);
	
}

void reverseList(node **root){
	node *temp = NULL;
	node *prev = NULL;
	node *iter = *root;
	
	while(iter != NULL){
		temp = iter -> next;
		iter -> next = prev;
		prev = iter;
		iter = temp;
	}
	
	*root = prev;
}



node *mergeSorted(node *a, node *b){			//merged 2 sorted linked list		recursively
	node *temp = NULL;
	if(a == NULL){
		return b;
	}else if(b == NULL){
		return a;
	}
	
	if(a->data <= b->data){
		temp = a;
		temp->next = mergeSorted(a->next,b);
	}else{
		temp = b;
		temp->next = mergeSorted(a,b->next);
	}
	return temp;
}



int main(){
	node * root = NULL;	// pointer to point beginning of the list
//	root=(node*)malloc(sizeof(node));
//	node * root2 = NULL;
//	root2 = (node*)malloc(sizeof(node));



	sortPush(&root,400);

	sortPush(&root,40);
	sortPush(&root,4);
	sortPush(&root,450);
	sortPush(&root,50);
	
	//printf("%d",root->data);
//	printf("%d",root->next->data);
//	printf("%d",root->next->next->data);
//	sortPush(&root,10);
//	sortPush(&root,8);
	printList(root);

	

//	pushStart(&root2,10);
//	pushEnd(root2,20);
//	pushEnd(root2,50);
	
	//init(root,2);
//	pushStart(&root,30);
//	pushEnd(root,40);
//	pushEnd(root,60);
	
	
//	printList(root);
//	printList(root2);
	
//	mergeSorted(root,root2);
	
//	printList(root);
//	printList(root2);
	
//	init(root,2);
//	pushEnd(root,10);
//	printList(root);
//	pushStart(&root,20);
//	printList(root);
//	pushAfterNode(root,100,);
//	printList(root);
//	removeStartNode(&root);
//	printList(root);
//	removeEndNode(root);
//	printList(root);
//	removebyValue(root,100);
//	printList(root);
//	reverseList(&root);
//	printList(root);








}
