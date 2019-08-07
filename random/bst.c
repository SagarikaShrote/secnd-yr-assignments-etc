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

void intraverse(tree * root, int * a, int s, int *i){
	if(root!=NULL){
		intraverse(root->left,a,s,i);
		if (root->left!= NULL)
		{
			(*i)++;
		}
		if(*i<s){
			a[*i]=root->data;
		}
		if (root->right!= NULL)
		{
			(*i)++;
		}
		intraverse(root->right,a,s,i);
	}
}

int sums(tree * root, int  k, int * a){
	int sum=0,i=0;
	intraverse(root,a,k,&i);
	for(i=0;i<k;i++){
		sum+=a[i];
	}
	return sum;
}

int ispresent(int n, tree * root){
	int ret=0;
	if(root!=NULL){
		if(root->data==n){
			ret=1;
		}
		else{
			ret=ispresent(n,root->left);
			if(ret==0){
				ret=ispresent(n,root->right);
			}
		}
	}
	return ret;
}

int findpair (tree * root,int k, int * a){
	int ret=0;
	if(root!=NULL){
		int num1,num2=0;
		num1=root->data;
		num2=k-num1;
		if(ispresent(num2,root) && num2!=num1){
			a[0]=num2;
			a[1]=num1;
			ret=1;
		}
		else{
			 ret=findpair (root->left, k, a);
			 if(ret!=1){
			 	ret=findpair (root->right, k, a);
			 }
		}
	}
	return ret;
}

main(){
	tree * root=NULL;
	root=make();
	int ht=height(root);
	printf("height is %d\n",ht );
	traversal(root,ht);
	int k;
	printf("enter k for k smallest elements\n");
	scanf("%d",&k);
	int * a=(int *) malloc(sizeof(int)*k);
	int sum=0;
	sum=sums(root,k,a);
	printf("sum is %d\n",sum );
	int p=0;
	printf("enter sum to check pair\n");
	scanf("%d",&p);
	int * aa=(int *) malloc(sizeof(int)*2);
	int ret=findpair(root,p,aa);
	if(ret){
		printf("%d %d is the pair\n",aa[0],aa[1] );
	}
	else{
		printf("sorry no pair present\n");
	}
}
