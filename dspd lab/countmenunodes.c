int countMenuNodes(menu * root){
	
	int sum=0;
	if(root!=NULL){
		if(root->next==NULL){
			sum=1+countMenuNodes(root->branch0)+countMenuNodes(root->branch1);
		}
		else{
			sum=1+countMenuNodes(root->branch0)+countMenuNodes(root->next);
		}
	}
	return sum;
}

user * search(user * root,int p){
	user * ret=NULL;
	user *temp=NULL;
	if(root!=NULL){
		if(root->pno==p){
			ret=root;
		}
		else {
		/*	ret=search(root->next,p);
			if(ret==NULL){
				ret=search(root->branch0,p);
			}
			if(ret==NULL && root->next==NULL){
				ret=search(root->branch1,p);
			}*/
			temp=root;
			while(temp->next!=NULL && temp->pno < p){
				temp=temp->next;
			}
			if(temp->pno > p){
				ret=search(temp->branch0,p);
			}
			else{
				ret=search(temp->branch1,p);
			}
		}
	}
	return ret;
}

//isme basic checks hi nahi kiye the tune isiliye segmentation fault dera hoga ise thoda change kiya h pura nhi kiya you can either use this or u can use the one i wrote (the recursive one)
/*menu* search_menu(menu *root,int data)
{
        menu *temp=root,*prev=NULL,*lptr=NULL,*ret_val = NULL;
        int found = 0;
        if (root!=NULL)
        {
	        if(temp -> branch1 == NULL && temp -> branch0 == NULL)
	        {
		        if(temp-> data == data)
		        {
		            found = 1;
		            ret_val = root;
		        }
	        }
	        else
	        {
		        while(temp != NULL && found == 0)
		        {
		            prev = NULL;
		            lptr = temp;
		            while(lptr != NULL && lptr -> data < data)
			         {
			            prev = lptr;
			            lptr = lptr -> next;
			         }
		            if(prev == NULL)
		            {
			            if(lptr -> data != data)
			                temp = lptr -> branch0;
			            else
			            {
			                found = 1;
			                ret_val = lptr;
			            }
		            }
		            else if(lptr != NULL && lptr -> data == data)
		            {
			            found = 1;
			            ret_val = lptr;
		            }
		            else
		            {
			            if(lptr == NULL)
			            {
			                temp = prev -> branch1;
			            }
			            else
			            {
			                temp = lptr -> branch1;
			            }
		            }
		        }
	        }
	 	}
    return ret_val;
}*/	

//i think this should work kuch load hua to kl 12-2 ke slot me thik kr dungi. or we can ask for some extension thoda sa dikha ke.

menu* search_menu(menu *root,int data){
	menu * ret=NULL;
	menu *temp=NULL;
	if(root!=NULL){
		if(root->data==data){
			ret=root;
		}
		else {
			temp=root;
			while(temp->next!=NULL && temp->data < data){
				temp=temp->next;
			}
			if(temp->data > data){
				ret=search(temp->branch0,data);
			}
			else{
				ret=search(temp->branch1,data);
			}
		}
	}
	return ret;
}