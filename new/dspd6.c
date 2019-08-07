#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node * next;
	struct node* prev;
} node;

node * makenode( node * nptr, int data)
{
	nptr=(node *)malloc (sizeof(node));
	if(nptr!=NULL){
		nptr->data=data;
		nptr->next=NULL;
		nptr->prev=NULL;
	}
	return nptr;
}
	
node * createlist(node * nptr , int size)
{
	int i=0,e;
	nptr=NULL;
	node * ptr=NULL;
	printf("enter data");
	for(i=0;i<size;i++){
		scanf("%d",&e);
		ptr=makenode(ptr,e);
		ptr->next=nptr;
		nptr=ptr;
	}
	return nptr;
}
node * create_Dlist(node * nptr , int size)
{
	int i=0,e;
	nptr=NULL;
	node * ptr=NULL;
	printf("enter data");
	for(i=0;i<size;i++){
		scanf("%d",&e);
		ptr=makenode(ptr,e);
		ptr->next=nptr;
		if(nptr!=NULL)
			nptr->prev=ptr;
		nptr=ptr;
	}
	return nptr;
}
node * SLL_to_DLL(node* lptr)
{
	node* nptr,*head;
	nptr = lptr;
	head = NULL;
	if(nptr!=NULL)
	{
		while(nptr!=NULL)
		{
			nptr->prev = head;
			head = nptr;
			nptr = nptr->next;
		}
		
	}
	return lptr;
}
int prime(int n)
{
	int i,flag = 0;
	for(i = 2; i <= n/2; i++)
    	{
        	// condition for nonprime number
        	if(n%i == 0)
        	{
        	    flag = 1;
        	    break;
        	}
    	}
	if(n==1)
	{
		flag = 1;
	}
	return flag;
}
void prime_mul(node* lptr)
{
	node * nptr;
	nptr = lptr;
	int mul = 1,flag=0;
	while(nptr!=NULL)
	{
		flag = prime(nptr->data);
		if(flag==0)
		{
			mul = mul*(nptr->data);
		}
		nptr = nptr->next;
	}
	printf("MULTIPLICATION: %d\n",mul);
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
		while(ptr2 !=NULL)
		{
			if(ptr1->data == ptr2->data)
			{
				count++;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	printf("COUNT: %d\n",count);
}
int main()
{
	int n,l,m;
	printf("give size of list");
	scanf("%d",&n);
	node * nptr=NULL,*ptr,*Dptr1,*Dptr2;
	nptr=createlist(nptr,n);
	printf("Enter size of DLL1");
	scanf("%d",&l);
	printf("Enter size of DLL2");
	scanf("%d",&m);
	Dptr1 = create_Dlist(Dptr1,l);
	Dptr2 = create_Dlist(Dptr2,m);
	nptr = SLL_to_DLL(nptr);
	ptr = nptr;
	prime_mul(nptr);
	same_data(Dptr1,Dptr2);
	while(ptr->next!=NULL)
	{
		printf("DATA: %d\n",ptr->data);
		ptr = ptr->next;
	}
	printf("DATA: %d\n",ptr->data);
	while(ptr!=NULL)
	{
		printf("DATA: %d\n",ptr->data);
		ptr = ptr->prev;
	}
	return 0;
}
