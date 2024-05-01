#include<stdio.h>

int read(int coeff[], int expo[], int n){
	int i;
	printf("\nEnter the number of terms in the expression: ");
	scanf("%d",&n);
	printf("\nEnter polynomial expression:\n------------------------");
	for(i=0;i<n;i++){
		printf("\nEnter term %d:\nCoefficient: ",i+1);
		scanf("%d",&coeff[i]);
		printf("\nExponent: ");
		scanf("%d",&expo[i]);
	}
	return n;
}

void sort(int coeff[],int expo[], int n){
	int i,j,temp1,temp2;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(expo[j]<expo[j+1]){
				temp1=expo[j];
				expo[j]=expo[j+1];
				expo[j+1]=temp1;
				temp2=coeff[j];
				coeff[j]=coeff[j+1];
				coeff[j+1]=temp2;
			}
		}
	}
}

void disp(int coeff[], int expo[], int n){
	int i;
	sort(coeff,expo,n);
	printf("\nExponent is: ");
	for(i=0;i<n;i++){
		if(expo[i]==0){
			if(coeff[i]<0)
				printf(" - %d",-coeff[i]);
			else if(coeff[i]>0){
				if(i==0)
					printf("%d",coeff[i]);
				else
					printf(" + %d",coeff[i]);   
			}
		}
		else if(expo[i]>0){
			if(coeff[i]<0)
				printf(" - %dx^%d",-coeff[i],expo[i]);
			else if(coeff[i]>0){
				if(i==0)
					printf("%dx^%d",coeff[i],expo[i]);
				else
					printf(" + %dx^%d",coeff[i],expo[i]);
				}
		}
		else{
			if(coeff[i]<0)
				printf(" - %d/x^%d",-coeff[i],-expo[i]);
			else if(coeff[i]>0){
				if(i==0)
					printf("%d/x^%d",coeff[i],-expo[i]);
				else
					printf(" + %d/x^%d",coeff[i],-expo[i]);
			}
		}
	}
}

int main()
{
	int n,coeff[10],expo[10];
	n=read(coeff,expo,n);
	disp(coeff,expo,n);
	return 0;
}