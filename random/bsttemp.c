#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
	int data;
	struct tree * left, * right;
}tree;

void visit(tree * r){
	if(r!=NULL){
		printf("%d\t",r->data );
	}
}
void levtraversal(tree * r, int l){
	if(r!=NULL){
		if (l==1){
			visit(r);
		}
		else{
			levtraversal(r->left,l-1);
			levtraversal(r->right,l-1);
		}
	}
}
int height(tree * r){
	int ht=0,htl,htr;
	if(r!=NULL){
		htl=1+height(r->left);
		htr=1+height(r->right);
		ht=(htl>htr)?htl:htr;
	}
	return ht;
}

void traversal(tree * r, int ht){
	int i;
	for(i=1;i<=ht;i++){
		levtraversal(r,i);
		printf("\n");
	}
}
tree * insert(tree* root,tree * node){
	if(root==NULL){
		root=node;
	}
	else{
		tree * r=root;
		int found=1;
		while(found==1 && r->data!=node->data){
			if(r->data>node->data){
				if(r->left==NULL){
					found=0;
				}
				else{
					r=r->left;
				}
			}
			else {
				if(r->right==NULL){
					found=0;
				}
				else{
					r=r->right;
				}
			}
		}
		if(r->data == node-> data){
			free(node);
			printf("data already present\n");
		}
		else if(r->data>node->data){
			r->left=node;
		}
		else{
			r->right=node;
		}
	}
	return root;
}

tree * make(){
	tree * root= NULL;
	tree * temp;
	int d;
	int stop=0;
	int n;
	printf("enter no. of nodes\n");
	scanf("%d",&n);
	while(n){
		printf("give data\n");
		scanf("%d",&d);
		temp= (tree*)malloc(sizeof(tree));
		temp->left=NULL;
		temp->right=NULL;
		temp->data=d;
		root=insert(root,temp);
		n--;
	}
	return root;
}
main(){
	tree * root=NULL;
	root=make();
	int ht=height(root);
	printf("height is %d\n",ht );
	traversal(root,ht);
	
}