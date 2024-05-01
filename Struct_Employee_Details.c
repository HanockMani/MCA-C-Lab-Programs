#include<stdio.h>
#include<string.h>

struct employee{
	int eno, esal, dno;
	char ename[10];
};

void disp(struct employee emp[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("\n\nEmployee %d: ",i+1);
		printf("\n______________");
		printf("\nEmployee Name: %s",emp[i].ename);
		printf("\nEmployee No: %d",emp[i].eno);
		printf("\nEmployee Salary: %d",emp[i].esal);
		printf("\nDepartment No: %d",emp[i].dno);
	}
}

void namesort(struct employee emp[], int n){
	int i, j;
    	struct employee temp;
    	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(strcmp(emp[j].ename,emp[j+1].ename)>0){
				temp= emp[j];
				emp[j]=emp[j+1];
				emp[j+1]=temp;
			}
		}
	}
}

void salsort(struct employee emp[], int n){
	int i, j;
	struct employee temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(emp[j].esal>emp[j+1].esal){
				temp= emp[j];
				emp[j]=emp[j+1];
				emp[j+1]=temp;
			}
		}
	}
}

void search(struct employee emp[], int n){
	int sel,i,flag=0;
	printf("\n\nEnter Employee no to search: ");
	scanf("\n%d",&sel);
	for(i=0;i<n;i++){
		if(emp[i].eno==sel){
			printf("\nEmployee found!!");
			printf("\n______________");
			printf("\nEmployee Name: %s",emp[i].ename);
			printf("\nEmployee No: %d",emp[i].eno);
			printf("\nEmployee Salary: %d",emp[i].esal);
			printf("\nDepartment No: %d",emp[i].dno);
		}
		flag=1;
	}
	if(flag==0){
		printf("\nEmployee not found!!");
	}
}

int insert(struct employee emp[], int n){
	int i;
	if(n==9){
		printf("\n\nMaximum number of employees entered!!");
	}
	else{
		if(n==-1)n=0;
		printf("\n\nEnter Employee Details: ");
		printf("\n______________");
		printf("\nEnter Name: ");
		scanf("%s",emp[n].ename);
		printf("Enter Employee No: ");
		scanf("%d",&emp[n].eno);
		printf("Enter Salary: ");
		scanf("%d",&emp[n].esal);
		printf("Enter Department No: ");
		scanf("%d",&emp[n].dno);
		n++;
	}
	return n;
}

int del(struct employee emp[], int n){
	int sel,i,flag=0;
	struct employee temp;
	if(n==-1){
		printf("\n\nNo Employees!!");
	}
	else{
		printf("\n\nEnter Employee No to delete: ");
		scanf("%d",&sel);
		for(i=0;i<n;i++){
			if(emp[i].eno==sel){
				n--;
				while(i<n){
					temp= emp[i];
					emp[i]=emp[i+1];
					emp[i+1]=temp;
					i++;
				}
				if(n==0)
					n=-1;
				printf("\nEmployee Deleted");
				flag=1;
			}
		}
		if(flag==0)
			printf("\nEmployee not found!!");
	}
	return n;
}

int main()
{
	int n=-1,ch=0;
	struct employee emp[10];
	while(ch!=7){
		printf("\n\nMENU\n____\n[1] INSERT\n[2] DELETE\n[3] DISPLAY\n[4] SEARCH\n[5] SALARY SORT\n[6] NAME SORT\n[7] EXIT\n");
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: n=insert(emp,n);
				break;
    	    		case 2: n=del(emp,n);
    	            		break;
    	    		case 3: disp(emp,n);
    	            		break;
    	    		case 4: search(emp,n);
    	            		break;
			case 5: salsort(emp,n);
				break;
    	    		case 6: namesort(emp,n);
    	            		break;
    	    		case 7: printf("\nExiting");
    	            		break;
    	    		default:printf("\nInvalid Entry!!");
    	            	break;
    		}
	}
	return 0;
}