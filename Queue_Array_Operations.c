#include <stdio.h>
int queue[5], front=-1, rear=-1;

void enqueue(int e){
	if(front==-1){
		front=rear=0;
		queue[rear]=e;
	}
	else if(front==(rear+1)%5){
		printf("\nQueue is full");
	}
	else{
		rear=(rear+1)%5;
		queue[rear]=e;
	}
}

void dequeue(){
	if(front==-1){
		printf("\nEmpty Queue!");
	}
	else if(front==rear){
		printf("\nDeleted element is: %d",queue[front]);
		front=rear=-1;
	}
	else{
		printf("\nDeleted element is: %d",queue[front]);
		front=(front+1)%5;
	}
}

int menu(){
	int ch=0;
	printf("\nMENU\n________\n[1] Enqueue\n[2] Dequeue\n[3] Exit\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}

int main(){
	int ch,e;
	for(ch=menu();ch!=3;ch=menu()){
		switch(ch){
			case 1: printf("\nEnter element to insert: ");
				scanf("%d",&e);
				enqueue(e);
				break;
			case 2: dequeue();
				break;
			default:printf("Invalid Entry!");
				break;
		}
	}
	return 0;
}
