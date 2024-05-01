#include<stdio.h>

int insert(int ar[],int pos){
	int i, e;
	if(pos==9){
		printf("\nARRAY IS FULL!");
	}
	else{
		printf("\nEnter element to insert: ");
		scanf("%d",&e);
		ar[++pos]=e;
	}
	printf("\nElement inserted!");
	return pos;
}

int del(int ar[],int pos){
	int i, e, flag=0;
	if(pos==-1){
		printf("\nARRAY IS EMPTY!");
	}
	else{
		printf("\nEnter element to delete: ");
		scanf("%d",&e);
		for(i=0;i<=pos;i++){
			if(ar[i]==e && i!=pos){
				pos--;
				for(i;i<=pos;i++){
					ar[i]=ar[i+1];
				}
				flag=1;
				break;
			}
			else if(ar[i]==e)
			{
				pos--;
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("\nElement Not Found!");
		else
			printf("\nElement Deleted!");
	}
	return pos;
}

void search(int ar[],int pos){
	int flag=0, i, e;
	printf("\nEnter element to search: ");
	scanf("%d",&e);
	for(i=0;i<=pos;i++){
		if(ar[i]==e){
			printf("\nElement found at postion %d!",i+1);
			flag=1;
		}
	}
	if(flag==0){
		printf("Element not found!");
	}
}

void sort(int ar[],int pos)
{
	int temp,i,j;
	for(i=0;i<=pos;i++){
		for(j=0;j<=pos-i-1;j++){
			if(ar[j]>=ar[j+1]){
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
	printf("\nSORTED ARRAY : ");
	for(i=0;i<=pos;i++){
		printf("%d\t",ar[i]);
	}
}

void display(int ar[], int pos){
	int i;
	if(pos==-1){
		printf("\nARRAY IS EMPTY!");
	}
	else{
		printf("\nArray : ");
		for(i=0;i<=pos;i++)
			printf("%d\t",ar[i]);
	}
}

int menu(int e){
	printf("\n\nMENU\n______\n[1] Insert\n[2] Delete\n[3] Search\n[4] Sort\n[5] Display\n[6] Exit\n______");
	printf("\nEnter your choice: ");
	scanf("%d",&e);
	return e;	
}

int main(){
	int ar[10],pos=-1,e,i;
	int ch;
	for(ch=menu(e);ch!=6;ch=menu(e)){
		switch(ch){
			case 1:
				pos=insert(ar,pos);
				break;
			case 2:
				pos=del(ar,pos);
				break;
			case 3:
				search(ar,pos);
				break;
			case 4:
				sort(ar,pos);
				break;
			case 5:
				display(ar,pos);
				break;
			default:
				printf("INVALID ENTRY!");
				break;
		}
	}
	return 0;
}