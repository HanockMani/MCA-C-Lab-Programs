#include<stdio.h>
int stack[10],top=-1;

void push(){
	int e;
	if(top==9){
		printf("\nStack is FULL!!");
	}
	else{
		printf("\nEnter the number to push: ");
		scanf("%d",&e);
		stack[++top]=e;
	}	
}

void pop(){
	if(top==-1){
		printf("\nStack is EMPTY!!");
	}
	else{
		printf("\nPopped element is: %d",stack[top]);
		top--;
	}
}

void peak(){
	printf("\nElement at top of stack is: %d",stack[top]);
}

int menu(int ch){
	printf("\nMENU\n______\n[1] PUSH\n[2] POP\n[3] PEAK\n[4] EXIT\n\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}

int main(){
	int ch;
	for(ch=menu(ch);ch!=4;ch=menu(ch)){
		switch(ch){
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: peak();
				break;
			default: printf("INVALID ENTRY!!");
				break;
		}
	}
	return 0;
}