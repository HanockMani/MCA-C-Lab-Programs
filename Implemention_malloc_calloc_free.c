#include<stdio.h>
#include<stdlib.h>

int main(){
	int *p1, *p2;
	int i;
	p1=(int *)malloc(sizeof(int));
	p2=(int *)calloc(5,sizeof(int));
	if(p1!=NULL){
		printf("\nmalloc Succesful! Enter a value: ");
		scanf("%d",&p1);
		printf("Entered values is %d",p1);
	}
	else{
		printf("malloc Failed!");		
	}
	if(p2!=NULL){
		printf("\ncalloc Successful! Enter 5 elements: ");
		for(i=0;i<5;i++){
			scanf("%d",&p2[i]);
		}
		printf("Elements are:\t");				
		for(i=0;i<5;i++){
			printf("%d\t",p2[i]);
		}
	}
	else{
		printf("calloc Failed!");		
	}
	free(p1);
	free(p2);
	return 0;
}