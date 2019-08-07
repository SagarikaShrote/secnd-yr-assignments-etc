#include<stdio.h>
#include<stdlib.h>

typedef struct node_type{
	int data;
	struct node_type*next;
	struct node_type* prev;
}node;

void init(node * lptr){
	lptr->prev=lptr->next=NULL;
}

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
		lptr=temp;
	}
	return lptr;
}

void change(node * lptr){
	if(lptr!=NULL){
		if(lptr->next!=NULL){
			(lptr->next)->prev=lptr;
			change(lptr->next);
		}
	}
}

void print(node * lptr){
	while(lptr->next!=NULL){
		lptr=lptr->next;
	}
	
	while(lptr->prev!=NULL){
		printf("%d\n",lptr->data);
		lptr=lptr->prev;
	}
	printf("%d\n",lptr->data);
}


void main(){
	node * lptr=NULL;
	
	lptr=create(lptr);
	change(lptr);
	print(lptr);
}

	
		
		
