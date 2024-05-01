#include<stdio.h>
#include<ctype.h>
char stack[20];
int top=-1;

void push(char e){
	stack[++top]=e;
}

void pop(){
	if(top==-1)
		printf("Stack Underflow!!");
	else
		top--;
}

int isoperator(char e){
	if(e=='('||e==')'||e=='+'||e=='-'||e=='*'||e=='/'||e=='^')
		return 1;
	else
		return 0;	
}

int pre(char e){
	if(e=='+'||e=='-'){
		return 1;
	}
	else if(e=='*'||e=='/'){
		return 2;
	}
	else if(e=='^'){
		return 3;
	}
	else
		return 0;
}

int main()
{
	int i;
	char infix[20];
	printf("\nEnter a Infix expression: ");
	scanf("%s",infix);
	printf("\nConverting.....\n Postfix Expression: ");
	for(i=0;infix[i]!='\0';i++){
		if(isoperator(infix[i]) && top!=-1){
			if(infix[i]=='(')
				push(infix[i]);
			else if(infix[i]==')'){
				while(stack[top]!='('){
					printf("%c",stack[top]);
					pop();
				}
				pop();
			}
			else if(stack[top]!='('){
				if(pre(infix[i])>=pre(stack[top])){
					push(infix[i]);
				}
				else{
					while(pre(infix[i])>=pre(stack[top])){
						printf("%c",stack[top]);
						pop();
					}
					push(infix[i]);
				}
			}
			else{
				push(infix[i]);
			}
		}
		else if(isoperator(infix[i]) && top==-1){
			push(infix[i]);
		}
		else if(isalnum(infix[i])){
			printf("%c",infix[i]);
		}
		else 
			printf("Invalid Expression!!");
	}
	while(top>-1){
		printf("%c",stack[top]);
		pop();
	}
	return 0;	
}