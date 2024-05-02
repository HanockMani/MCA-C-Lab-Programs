#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;
node *top=NULL;
void push(int data){
	node *t;
	t=(node*)malloc(sizeof(node));
	t->data=data;
	t->next=top;
	top=t;
}

void pop(){
	if(top==NULL){
		printf("\nStack is Empty");
	}
	else{
		top=top->next;
	}
}

void peek(){
	if(top==NULL){
		printf("\nStack is Empty");
	}
	else{
		printf("\nElement at top is %d",top->data);
	}
}

int menu(){
	int ch;
	printf("\nMENU\n________\n[1] PUSH\n[2] POP\n[3] PEEK\n[4] EXIT\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}

int main(){
	int ch,e;
	for(ch=menu();ch!=4;ch=menu()){
	switch(ch){
		case 1: printf("\nEnter element to insert: ");
			scanf("%d",&e);
			push(e);
			break;
		case 2: pop();
			break;
		case 3:	peek();
			break;
		default:printf("Invalid Entry!");
			break;
		}
	}
	return 0;
}