#include<stdio.h>

int read(int ar[], int n,int i){
	printf("\nEnter the number of elements in array(<11): ");
	scanf("%d",&n);
	printf("\nEnter array elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	return n;
}

void sort(int ar[],int n,int i){
	int temp,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(ar[j]>=ar[j+1]){
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
}

void disp(int ar[],int n,int i){
	for(i=0;i<n;i++){
		printf("%d\t",ar[i]);
	}
}

int main(){
	int ar[10],n,i;
	n=read(ar,n,i);
	printf("\nUNSORTED ARRAY : ");
	disp(ar,n,i);
	sort(ar,n,i);
	printf("\nSORTED ARRAY : ");
	disp(ar,n,i);
	return 0;
}