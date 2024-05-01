#include <stdio.h>
#include <stdlib.h>

int main(){
	int *ptr, count=0, new_count, mode, i, j, n;
	printf("Enter no. of terms");
	scanf("%d",&n);
	ptr=(int *)calloc(n,sizeof(int));
	printf("\nEnter %d numbers: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&ptr[i]);
	}
	for(i=0;i<n;i++){
		new_count=0;
		for(j=0;j<5;j++){
			if(ptr[i]==ptr[j])
				new_count++;
		}
		if(new_count>count){
			count=new_count;
			mode=ptr[i];
		}
	}
	printf("\nMode=%d",mode);
	free(ptr);
	return 0;
}