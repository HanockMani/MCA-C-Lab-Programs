#include<stdio.h>
#include<stdlib.h>

struct books{
	char book_name[20], author_name[20];
};

typedef struct books books;
int read_no(){
	int n;
	printf("\nEnter number of books: ");
	scanf("%d",&n);
	return n;
}

void read_books(books *ptr, int n){
	int i;
	printf("\nEnter %d Book Details:",n);
	for(i=0;i<n;i++){
		printf("\nBook %d\nEnter Book Name: ",i+1);
		scanf(" %[^\n]s",ptr[i].book_name);
		printf("Enter Author Name: ");
		scanf(" %[^\n]s",ptr[i].author_name);
	}
}

void disp(books *ptr, int n){
	int i;
	printf("\nBook Details\n------------");
	for(i=0;i<n;i++){
		printf("\nBook %d\nBook Name: %s\nAuthor Name: %s",i+1,ptr[i].book_name,ptr[i].author_name);
	}
}

int main(){
	books *ptr;
	int n;
	n=read_no();
	ptr=(books *)calloc(n,sizeof(books));
	read_books(ptr,n);
	disp(ptr,n);
	free(ptr);
	return 0;
}