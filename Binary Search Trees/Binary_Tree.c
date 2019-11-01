#include <stdio.h>
#include <stdlib.h>

typedef struct binaryTree{
	int data;
	struct binaryTree *right;
	struct binaryTree *left;
}tree;

void insert(tree ** head,int x){
	tree * iter = *head;
	if(iter == NULL){
		tree * node = (tree*)malloc(sizeof(tree));
		node->left=NULL;
		node->right=NULL;
		node->data = x;
		*head = node;
		return;
	}
	if(x < iter->data){
		insert( &(iter)->left,x);
	}else if(x > iter->data){
		insert( &(iter)->right,x);
	}
	
}

void printTree(tree * head){		//LDR
	if(head != NULL){
		printTree(head->left);
		printf("%d =>",head->data);
		printTree(head->right);
	}
		
}

///  other traverse  options

/*
void printTree(tree * head){		//DLR
	if(head != NULL){
		printf("%d =>",head->data);
		printTree(head->left);
		printTree(head->right);
	}	
}
*/
/*
void printTree(tree * head){		//LRD
	if(head != NULL){
		printTree(head->left);
		printTree(head->right);
		printf("%d =>",head->data);
	}	
}
*/

void search(tree *head,int x){
	
	if(head == NULL){
		printf("tree empty \n");
		return;
	}
	
	tree *iter = head;
	
	while(iter->data != x && iter != NULL){
		printf("%d=>",iter->data);
		if(x < iter->data){
			iter = iter->left;
		}else if(x > iter->data){
			iter = iter->right;
		}
	}
	printf("%d\n",iter->data);
	
	if(iter == NULL){
		printf("number not found!\n");
	}
	
}

int findmin(tree *head){
	while(head->left != NULL){
		head = head->left;
	}
	return head->data;
}

int findmax(tree *head){
	while(head->right != NULL){
		head = head->right;
	}
	return head->data;
}

		
tree* deleteNode(tree* head, int x)
{
	if(head==NULL){
		printf("there ara nothing to delete!!");
		return NULL;
	}
	
	if(head->data == x){
		if(head->left == NULL && head->right == NULL){
			return NULL;
		}
		if(head->right != NULL){
			head->data = findmin(head->right);
			head->right = deleteNode(head->right,findmin(head->right));
			return head;
		}
		head->data = findmax(head->left);
		head->left = deleteNode(head->left,findmax(head->left));
		return head;
	}
	
	if(x > head->data){
		head->right = deleteNode(head->right,x);
		return head;
	}
	
	// this  if (x < head->data)
	head->left = deleteNode(head->left,x);
	return head;
	
}

	


int main(){
	tree * head = NULL;	
	
	int current = 1;
	int choice;
	int element;
	while(current){
		
		printf("1->insert\n");
		printf("2->print\n");
		printf("3->search\n");
		printf("4->find min\n");
		printf("5->find max\n");
		printf("6->delete\n");
		printf("7->exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter element to add tree: ");
				scanf("%d",&element);
				insert(&head,element);
				break;
			case 2:
				if(head==NULL){
					printf("tree empty!!\n");
				}else{
					printTree(head);
					printf("\n");	
				}
				break;
			case 3:
				printf("enter the number that you want to search: ");
				scanf("%d",&element);
				search(head,element);
				break;
			case 4:
				printf("%d\n",findmin(head));
				break;
			case 5:
				printf("%d\n",findmax(head));
				break;
			case 6:
				printf("enter the number that you vant to delete: ");
				scanf("%d",&element);
				head = deleteNode(head,element);	
				printTree(head);
				break;
			case 7:
				current = 0;		
					
		}
		
	}
	
}
