#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int data;
	struct node * next;
}node;

typedef struct tree{
	int count;
	node * key;
	struct tree *right,*left;
}tree;

tree * insert(int data,tree * root){
	if(root==NULL){
		root=(tree *)malloc(sizeof(tree));
		root->count=1;
		root->key=(node *)malloc(sizeof(node));
		root->key->data=data;
		root->key->next=NULL;
		root->right=NULL;
		root->left=NULL;
	}
	else{

		if (/* condition */)
		{
			/* code */
		}
		else{
			
		}
	}
	return root;
}
main(){
	tree * root=NULL;
	root=insert(5,root);
	printf("%d\t%d\n",root->count,root->key->data );
}