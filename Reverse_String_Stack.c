#include<stdio.h>

int push(char stack[], int top, char e){
	if(top==19){
		printf("\nStack is Full!!");
	}
	else{
		stack[++top]=e;
	}
	return top;
}

int pop(char stack[], int top){
	if(top==-1){
		printf("\nStack is Empty!!");
	}
	else{
		printf("%c",stack[top]);
		top--;
	}
	return top;
}

int main(){
	char string[20],e;
	int top=-1;
	printf("\nEnter an String: ");
	while(e!='\n'){
		scanf("%c",&e);
		top=push(string,top,e);
	}
	printf("Reversed String is: ");
	while(top!=-1){
		top=pop(string,top);
	}
}