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

//*********************end of basics***********************************************************

int search(int a[],int val,int start , int end){
	int i=start;
	while(i<=end && a[i]!=val){
		i++;
	}
	printf("index i :%d\n", i);
	return i;
	
}

tree * makenode(int val){
	tree * ret=(tree *)malloc(sizeof(tree));
	printf("i print node %d\n",val );
	ret->right=NULL;
	ret->left=NULL;
	ret->data=val;
	return ret;
}



tree * buildtree(int in[],int pre[],int start,int end,int n){
	static int pin=0;
	tree * ret=	NULL;
	if(start<=end && pin<=n){
		ret=makenode(pre[pin]);
		int i=search(in,pre[pin],start,end);		
		if(start<end){
			pin++;
			ret->left=buildtree(in,pre,start,i-1,n);
			pin++;
			ret->right=buildtree(in,pre,i+1,end,n);
		}
	}
	return ret;
}



main(){
	tree * root=NULL;
	printf("enter no. of data items\n");
	int n;
	scanf("%d",&n);
	int * in=(int*)malloc(sizeof(int)*n);
	int * pre=(int*)malloc(sizeof(int)*n);
	printf("enter elements of preorder\n");
	int i=0;
	while(i<n){
		scanf("%d",&pre[i]);
		printf("%d\n",pre[i] );
		i++;
	}
	i=0;
	printf("enter elements of inorder\n");
	while(i<n){
		scanf("%d",&in[i]);
		printf("%d\n",in[i] );
		i++;
	}	
	i=0;
	root=buildtree(in,pre,0,n-1,n);
	int ht=height(root);
	printf("the tree is\n");
	traversal(root,ht);
}



//*****************************************************************************************************************************************

/*main(){
	tree * root=NULL;
	root=make();
	int ht=height(root);
	printf("height is %d\n",ht );
	traversal(root,ht);
	
}*/


