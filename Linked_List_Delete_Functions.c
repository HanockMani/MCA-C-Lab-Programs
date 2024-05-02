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

void delete_beg(){
	if(head==NULL){
		printf("Empty Linked List!");
	}
	else{
		head=head->next;
	}
}

void delete_end(){
	node *t=head;
	if(head==NULL){
		printf("Empty Linked List!");
	}
	else if(head->next==NULL){
		head=head->next;
	}
	else{
		while(t->next->next!=NULL){
			t=t->next;
		}
		t->next=NULL;
	}
}

void delete_spec(int e){
	node *t=head;
	int flag=0;
	if(head==NULL){
		printf("\nNo elements in Linked List!");
	}
	else if(head->data==e){
		head=head->next;
	}
	else{
		while(t->next!=NULL){
			if(t->next->data==e){
				t->next=t->next->next;
			flag=1;
			break;
		}
		t=t->next;
	}
	if(flag==0)
		printf("Entered element not found!");
	}
}

void display(){
	node *t=head;
	if(head==NULL){
		printf("Empty Linked List!");
	}
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
	printf("\nMenu\n_______\n[1] Insert\n[2] Delete_Begining\n[3] Delete_End\n[4] Delete_Specific\n[5] Display\n[6] Exit\nEnter choice: ");
	scanf("%d",&ch);
	return ch;
}

int main(){
	int ch,e;
	for(ch=menu();ch!=6;ch=menu()){
	switch(ch){
		case 1: printf("\nEnter element to insert: ");
			scanf("%d",&e);
			insert(e);
			break;
		case 2: delete_beg();
			break;
		case 3: delete_end();
			break;
		case 4: printf("\nEnter element to delete: ");
			scanf("%d",&e);
			delete_spec(e);
			break;
		case 5: display();
			break;
			default:printf("Invalid Entry!");
			break;
		}
	}
	return 0;
}