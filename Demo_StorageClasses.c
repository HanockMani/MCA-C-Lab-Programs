#include<stdio.h>
int a=10;

void demo(){
	static int b=1;
	int c=1;
	printf("\n\nIn Demo Function....");
	printf("\nGlobal Variable A =%d, Static Varaible B =%d, Local Variable C =%d",a,b,c);
	a++;
	b++;
	c++;
}

int main(){
	register int d=10;
	demo();
	printf("\n\nIn Main....\nGlobal Variable A =%d, Register Variable D =%d",a,d);
	demo();
	demo();
	return 0;
}