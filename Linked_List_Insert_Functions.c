#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;
node *head=NULL;
void insert_beg(int e){
	node *t;
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->data=e;
		head->next=NULL;
	}
	else{
		t=(node*)malloc(sizeof(node));
		t->data=e;
		t->next=head;
		head=t;
	}
}

void insert_end(int e){
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

void insert_spec(int aft_e, int e){
	node *t1, *t=head;
	int flag=0;
	if(head==NULL){
		printf("\nNo elements in Linked List!");
	}
	else{
		while(t!=NULL){	
			if(t->data==aft_e){
				t1=(node*)malloc(sizeof(node));
				t1->data=e;
				t1->next=t->next;
				t->next=t1;
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
	printf("\nMenu\n_______\n[1] Insert_Beginning\n[2] Insert_End\n[3] Insert_Specific\n[4] Display\n[5] Exit\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}

int main(){
	int ch,aft_e,e;
	for(ch=menu();ch!=5;ch=menu()){
		switch(ch){
		case 1: printf("\nEnter element to insert: ");
			scanf("%d",&e);
			insert_beg(e);
			break;
		case 2: printf("\nEnter element to insert: ");
			scanf("%d",&e);
			insert_end(e);
			break;
		case 3: printf("\nEnter element after which new element is to be inserted: ");
			scanf("%d",&aft_e);
			printf("\nEnter element to insert: ");
			scanf("%d",&e);
			insert_spec(aft_e,e);
			break;
		case 4: display();
			break;
			default:printf("Invalid Entry!");
			break;
		}
	}
	return 0;
}