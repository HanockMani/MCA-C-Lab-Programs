#include<stdio.h>

int coeff1[10],expo1[10],coeff2[10],expo2[10],coeff3[20],expo3[20];
int n1,n2,n3;

int read(int coeff[], int expo[]){
	int i,n;
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

void sort(int coeff[], int expo[], int n){
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

void add(){
	int i=0, j=0, k=0;
	while (i < n1 && j < n2){
		if (expo1[i] == expo2[j]){
			coeff3[k] = coeff1[i] + coeff2[j];
			expo3[k] = expo1[i];
			i++;
			j++;
			k++;
		}
		else if (expo1[i] > expo2[j]){
			coeff3[k] = coeff1[i];
			expo3[k] = expo1[i];
			i++;
			k++;
		}
		else{
			coeff3[k] = coeff2[j];
			expo3[k] = expo2[j];
			j++;
			k++;
		}
	}
	while (i < n1){
		coeff3[k] = coeff1[i];
		expo3[k] = expo1[i];
		i++;
		k++;
	}
	while (j < n2){
		coeff3[k] = coeff2[j];
		expo3[k] = expo2[j];
		j++;
		k++;
	}
	n3=k;
}

int main(){
	n1=read(coeff1,expo1);
	sort(coeff1,expo1,n1);
	disp(coeff1,expo1,n1);
	n2=read(coeff2,expo2);
	sort(coeff2,expo2,n2);
	disp(coeff2,expo2,n2);
	printf("\nAdding two Polynomials:\n");
	add();
	sort(coeff3,expo3,n3);
	disp(coeff3,expo3,n3);
	return 0;
}