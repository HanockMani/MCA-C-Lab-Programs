#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *front=NULL;
node *rear=NULL;

void enqueue(int data){
	node *t;
	t=(node*)malloc(sizeof(node));
	t->data=data;
	t->next=NULL;
	if(front==NULL){
		front=t;
		rear=t;
	}
	else if(front==rear){
		front->next=t;
		rear=t;
	}
	else{
		rear->next=t;
		rear=t;
	}
}

void dequeue(){
	node *t;
	if(front==NULL){
		printf("\nQueue is Empty");
	}
	else if(front==rear){
		front=rear=NULL;
	}
	else{
		front=front->next;
	}
}

void display(){
	node *t;
	t=front;
	if(t==NULL){
		printf("\nQueue is Empty");
	}
	else{
		while(t!=NULL){
			printf("%d\t",t->data);
			t=t->next;
		}
	}
}

int menu(){
	int ch;
	printf("\nMENU\n________\n[1] ENQUEUE\n[2] DEQUEUE\n[3] DISPLAY\n[4] EXIT\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}

int main(){
	int ch,e;
	for(ch=menu();ch!=4;ch=menu()){
		switch(ch){
			case 1: printf("\nEnter element to insert: ");
				scanf("%d",&e);
				enqueue(e);
				break;
			case 2: dequeue();
				break;
			case 3:	display();
				break;
			default:printf("Invalid Entry!");
				break;
		}
	}
	return 0;
}