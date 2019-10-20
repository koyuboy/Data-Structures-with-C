#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}*node;
//typedef Node* node;

// Node = n    data = x     
// node = node   next = next

void bastir(node r){		//okey
	r = r-> next;
	while(r!= NULL){
		printf("%d ",r->data);
		r=r->next;
	}
}
void ekle(node r,int x){//okey
	while(r->next != NULL){
	r = r -> next;
	}
	r -> next = (node*)malloc(sizeof(struct Node));
	r = r->next;
	r -> data = x;
	r -> next = NULL;

}
node getnode(){//okey
	node newnode;
	newnode = (node)malloc(sizeof(struct Node));
	newnode -> next = NULL;
	return newnode;
}

void pop(node root,int info){//var olmayan bir info girince program çöküyo //error  baþtan ardan sondan diye ayýr   // tek eleman girildiðinde ve çok eleman girilince sorun yok
	node temp;
	
	if(root == NULL ){
		printf("list empty\n");
		return NULL;		
	}
	while(root -> next ->data != info){
		root = root ->next;
	}if(root -> next == NULL){
		printf("Eleman bulunamadi");
	}else{
	temp = root -> next ;	
	root ->next = root -> next -> next;
	free(temp);
	printf("%d elemani pooped",info);
}
}
void search(node root, int x){//okey
	node p;
	int i=0;
	for(p = root;p!=NULL;p = p -> next){
		if(p -> data == x){
			printf("%d verisi listenin %d inci elemani",x,--i);
			return NULL;
		}
		i++;
	}
	printf("%d elemani bu listede bulunamadi !!",x);
}	
	

int main(){
	node a = getnode();
	ekle(a,2);
	int i;
	for(i = 0;i<5;i++){
//		ekle(a, i*10);
	}
	bastir(a);
	pop(a,2);
	bastir(a);
//	search(a,0);
//	bastir(a);
}
