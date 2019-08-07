#include<stdio.h>
#include<stdlib.h>

typedef struct node_type{
	int data;
	struct node_type*next;
	struct node_type* prev;
}node;
node * makenode(node * lptr, int d){
	
	lptr=(node *)malloc(sizeof(node));
	lptr->data=d;
	lptr->prev=NULL;
	lptr->next=NULL;
	
	return lptr;
}

node * create(node * lptr)
{
	int s,d,i;
	node * temp=NULL;
	printf("give no. of inputs");
	scanf("%d",&s);
	printf("give inputs");
	for(i=0;i<s;i++){
		scanf("%d",&d);
		temp=makenode(temp,d);
		temp->next=lptr;
		if(lptr!=NULL){
			lptr->prev=temp;
		}
		lptr=temp;
	}
	return lptr;
}

void same_data(node*lptr,node*nptr)
{
	node* ptr1,*ptr2;
	ptr1 = lptr;
	ptr2 = nptr;
	int count = 0;
	while(ptr1!=NULL)
	{
		ptr2 = nptr;
		while(ptr2!=NULL)
		{
			if(ptr1->data != ptr2->data)
			{
				
			}
			else count++;
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	printf("COUNT: %d\n",count);
}

void main(){
	node * n1=NULL, *n2=NULL;
	
	create(n1);
	create(n2);
	same_data(n1,n2);

}


