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
node * reverse(node * lptr){
	node *head,*mid,*tail;
	mid=NULL;
	head=lptr;
	if(head!=NULL){
		while(head!=NULL){
			tail=mid;
			mid=head;
			head=head->next;
			mid->next=tail;
			mid->prev=head;
		}
	}
	return mid;
}

void print(node * lptr){
	node*temp=lptr;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

main(){
	node * lptr=NULL;
	int n;
	printf("give size and elements of first list");
	scanf("%d",&n);
	lptr=create(lptr,n);
	lptr=reverse(lptr);
	printf(" the list is\n");
	print(lptr);
}
