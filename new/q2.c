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

int isPrime(int d){
	int res=1;
	if(d%2==0){
		res=0;
	}
	else{
		int i=3;
		while(i<=d/2 && res==1){
			if(d%i==0){
				res=0;
			}
			i++;
		}
	}
	return res;
}

int product(node * lptr){
	int p=1;
	node * temp=lptr;
	while(temp!=NULL){
		if(isPrime(temp->data) || temp->data==2){
			p*=temp->data;
		}
		temp=temp->next;
	}
	return p;
}


void main(){
	node * lptr=NULL;
	
	lptr=create(lptr);
	int pdt=product(lptr);
	printf("%d",pdt);
}
