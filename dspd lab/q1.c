#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node * next;
}node;

node * create(node * lptr,int n){
	int i;
	node *temp;
	for (i=0;i<n;i++){
		temp=(node*)malloc(sizeof(node));
		scanf("%d",&(temp->data));
		temp->next=lptr;
		lptr=temp;
	}
	return lptr;
}

node * merge(node * l1ptr, node * l2ptr){
	node * res;
	if(l1ptr==NULL){
		res=l2ptr;
	}
	else if(l2ptr==NULL){
		res=l1ptr;
	}
	else{
		res=l1ptr;
		l1ptr=l1ptr->next;
		node * temp=res;
		while(l1ptr!=NULL && l2ptr!=NULL){
			temp->next=l2ptr;
			l2ptr=l2ptr->next;
			temp=temp->next;
			temp->next=l1ptr;
			temp=temp->next;
			l1ptr=l1ptr->next;
		}
		if(l1ptr!=NULL){
			temp->next=l1ptr;
		}
		else{
			temp->next=l2ptr;
		}
	}
	return res;
}

void print(node * lptr){
	node * temp=lptr;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

main(){
	node * l1ptr=NULL,*l2ptr=NULL;
	int n;
	printf("give size and elements of first list");
	scanf("%d",&n);
	l1ptr=create(l1ptr,n);
	printf("give size and elements of second list");
	scanf("%d",&n);
	l2ptr=create(l2ptr,n);
	node * res=merge(l1ptr,l2ptr);
	print(res);
}






	
