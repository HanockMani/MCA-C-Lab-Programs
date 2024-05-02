#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;
node *head=NULL;

void insert(int e){
	node *t=head;
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->data=e;
		head->next=NULL;
	}
	else{
		while(t->next!=NULL){
		t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		t->next->data=e;
		t->next->next=NULL;
	}
}

void display(){
	node *t=head;
	if(head==NULL){
		printf("Empty Linked List!");}
	else{
		printf("\nLinked List Elements are: ");
		while(t!=NULL){
			printf("%d\t",t->data);
			t=t->next;
		}    
	}
}

int menu(){
	int ch;
	printf("\nMenu\n_______\n[1] Insert\n[2] Display\n[3] Exit\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}

int main(){
	int ch,e;
	for(ch=menu();ch!=3;ch=menu()){
	switch(ch){
		case 1: printf("\nEnter element to insert: ");
			scanf("%d",&e);
			insert(e);
			break;
		case 2: display();
			break;
		default:printf("Invalid Entry!");
			break;
		}
	}
	return 0;
}