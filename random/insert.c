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
	while(!stop){
		printf("give data\n");
		scanf("%d",&d);
		temp= (tree*)malloc(sizeof(tree));
		temp->left=NULL;
		temp->right=NULL;
		temp->data=d;
		root=insert(root,temp);
		printf("press 0 to continue or 1 to end\n");
		scanf("%d",&stop);
	}
	return root;
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

int heightof(tree* r, int d){
	int l=0;
	tree * p=r;
	if(r!=NULL){
		l++;
		while(p->data!=d){
			if(d<p->data){
				p=p->left;
			}
			else{
				p=p->right;
			}
			l++;
		}
	}
	return l;
}

/*void deletenode(tree**pptr){
	tree * temp, *p=*pptr;
	if(p->right==NULL){
		*pptr=p->left;
		free(p);
	}
	else if(p->left==NULL){
		*pptr=p->right;
		free(p);
	}
	else{
		tree * prev=NULL;
		for(temp=p->left;temp->right!=NULL;){
			prev=temp;
			temp=temp->right;
		}
		prev->right=temp->left;
		temp->left=p->left;
		temp->right=p->right;
		*pptr=temp;
		free(p);
	}
}

void delete(tree ** r,int d){
	tree * p=*r,*prev=NULL;
	while(p!=NULL && p->data!=d){
		prev=p;
		if(p->data<d){
			p=p->right;
		}
		else{
			p=p->left;
		}
	}
	if (p!=NULL){
		if(prev==NULL){
			
			deletenode(r);
			
		}
		else{
			if(p==prev->left){
				deletenode(&(prev->left));
			}
			else{
				deletenode(&(prev->right));
			}
		}
	}
	
}*/

void slevtraversal(tree * r, int l,int * s){
	if(r!=NULL){
		if (l==1){

			*s+=r->data;
		}
		else{
			slevtraversal(r->left,l-1,s);
			slevtraversal(r->right,l-1,s);
		}
	}
	
}

void straversal(tree * r, int ht){
	int i,max=0;
	for(i=1;i<=ht;i++){

		int s=0;
		slevtraversal(r,i,&s);
		printf("%d\n",s);
		if(max<s){
			max=s;
		}
	}
	printf("max sum is: %d\n",max );
}

main(){
	tree * root=NULL;
	root=make();
	int d;
	int ht=height(root);
	printf("height is %d\n",ht );
	traversal(root,ht);
	printf("enter element to check ht\n");
	scanf("%d",&d);
	int htd=heightof(root,d);
	printf("height of %d is %d\n",d,htd );
	//printf("enter a no. to delete\n");
	//scanf("%d",&d);
	//tree ** r=&root;
	//delete(r,d);
	//ht=height(*r);
	//traversal(*r,ht);
	straversal(root,ht);
}
