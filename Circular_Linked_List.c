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
		head->next=head;
	}
	else{
		while(t->next!=head){
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		t->next->data=e;
		t->next->next=head;
	}
}

void delete_spec(int e){
	node *t;
	int flag=0;	
	if(head==NULL){
		printf("\nEmpty Linked List!");
	}
	else if(head->data==e && head->next==head){
		head=NULL;
	}
	else if(head->data==e){
		t=head;
		flag=1;
		do{
			t=t->next;
		}while(t->next!=head);
		t->next=head->next;
		head=head->next;
	}
	else{
		t=head;
		do{
			if(t->next->data==e){
				t->next=t->next->next;
				flag=1;
				break;
			}
			t=t->next;
		}while(t->next!=head);
		if(flag==0)
			printf("\nElement not found!");
	}
}

void display(){
	node *t=head;
	if(head==NULL){
		printf("Empty Linked List!");
	}
	else{
		printf("\nLinked List Elements are: ");
		do{
			printf("%d\t",t->data);
			t=t->next;
		}while(t!=head);    
	}
}

int menu(){
	int ch;
	printf("\nMenu\n_______\n[1] INSERT\n[2] DELETE\n[3] DISPLAY\n[4] EXIT\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}

int main(){
	int ch,e;
	for(ch=menu();ch!=4;ch=menu()){
	switch(ch){
		case 1: printf("\nEnter element to insert: ");
			scanf("%d",&e);
			insert(e);
			break;	
		case 2: printf("\nEnter element to delete: ");
			scanf("%d",&e);
			delete_spec(e);
			break;
		case 3: display();
			break;
			default:printf("Invalid Entry!");
			break;
		}
	}
	return 0;
}