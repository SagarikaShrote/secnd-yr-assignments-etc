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
void print(node * lptr){
	node * temp=lptr;
	if(temp!=NULL){
		print(temp->next);
		printf("%d\n",temp->data);
	}
}
