#include<stdio.h>
#include<stdlib.h>

int main(){
	float *p;
	int n,i;
	float mean,s=0;
	printf("\nEnter number of Elements: ");
	scanf("%d",&n);
	p=(float *)malloc(n*sizeof(float));
	printf("Enter values to find mean : ");
	for(i=0;i<n;i++){
		scanf("%f",&p[i]);	
		s=s+p[i];
	}
	mean=s/n;
	printf("\nMean = %f",mean);
	free(p);
	return 0;
}