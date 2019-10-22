// merge  , sort  ve sortla ekleme  , reverse   ekle  

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
	node * temp = root->next;
	root->next = newnode;
	newnode->next = temp;
	
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
// Note :: removeStartNode and removeEndNot  function will be adding removeEndNode ...
int main(){
	node * root;	// pointer to point beginning of the list
	root=malloc(sizeof(node));
	
	init(root,2);
	pushEnd(root,10);
	printList(root);
	pushStart(&root,20);
	printList(root);
	pushAfterNode(root,100,1);
	printList(root);
	removeStartNode(&root);
	printList(root);
	removeEndNode(root);
	printList(root);
	removebyValue(root,100);
	printList(root);
}
