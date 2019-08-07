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
	node*temp=lptr;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
node * sort(node * lptr){
	node * l1,*l2;
	l2=lptr;
	while(l2ptr!=NULL)
	
	
