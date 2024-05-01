#include<stdio.h>

int read(int ar[], int n){
	int i;
	printf("\nEnter array size (<11): ");
	scanf("%d",&n);
	printf("\nEnter array elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	return n;
}

void disp(int ar[], int n, int i){
	printf("%d\t",ar[i]);
	i++;
	if(i<n){
		disp(ar,n,i);
	}
}

int main(){
	int ar[10],n,i=0;
	n=read(ar,n);
	printf("\nArray is : ");
	disp(ar,n,i);
	return 0;
}