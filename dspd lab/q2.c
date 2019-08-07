#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node * next;
	struct node * prev;
}node;

node * create(node * lptr,int n){
	int i;
	node *temp;
	for (i=0;i<n;i++){
		temp=(node*)malloc(sizeof(node));
		scanf("%d",&(temp->data));
		if(lptr!=NULL){
			lptr->prev=temp;
		}
		temp->next=lptr;
		temp->prev=NULL;
		lptr=temp;
	}
	return lptr;
}
void print(node * lptr){
	node * temp=lptr;
	if(temp!=NULL){
		print(temp->next);
		printf("%d\n",temp->data);
	}
}
node * delete(node * lptr,int k){
	node * res=NULL;
	if(lptr!=NULL){
		res=lptr;
		node*prev,*next;
		while(lptr!=NULL){
			if(lptr->data%k==0){
				if(lptr->prev==NULL){
					lptr=lptr->next;
					free(res);
					res=lptr;
					if(res!=NULL){
						res->prev=NULL;
					}
				}
				else{
					prev=lptr->prev;
					
					next=lptr->next;
					prev->next=next;
					if(next!=NULL){
						next->prev=prev;
					}
					free(lptr);
					lptr=next;
				}
			}
			else
			lptr=lptr->next;
		}
	}
	return res;
}

main(){
	node * lptr=NULL;
	int n;
	printf("give size and elements of first list");
	scanf("%d",&n);
	lptr=create(lptr,n);
	printf("give k");
	scanf("%d",&n);
	lptr=delete(lptr,n);
	print(lptr);
}

	

































					






























