#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define m 5
//#include "Insertmenu.h"
// MENU
typedef struct menu_type{
	char item[20];			//name of items
	int price;
	int data;
	struct menu_type * next;
	struct menu_type * branch0;
	struct menu_type * branch1;
} menu;
// Previous Order
typedef struct prevorder_type{
	menu * Olist;
	char rname[20];				//name of restaurant from where the order was placed
	struct prevorder_type * next;
	struct prevorder_type * branch0;
	struct prevorder * branch1;
} prevorder;
// Restaurant
typedef struct rest_type{
	char rname[20];
	char radd[20];
	char ctype[10];			//cuisine type
	char rtype[10];			//category of restaurant (pub, cafe etc)
	int seats;
	int pincode;
	int data;
	struct rest_type* name;
	struct rest_type* area;
	struct rest_type* cuisine;
	struct rest_type* type;
	struct rest_type* next;
	struct rest_type* branch0;
	struct rest_type* branch1;
					//special facilities
	menu * mptr;
} rest;
// Agent
typedef struct agent_type{
	//int id;
	int pno;
	char name[20];
	char aadd[20];			//area for agent
	int free;			//to check if he is free or not? 0 means free while 1 means he is already assigned to some order
	int comm;
	int coust_phno;
	struct agent_type * next;			//current accumulated commision
	struct agent_type* branch0;
	struct agent_type* branch1;
} agent;
// User
typedef struct user_type{
	//int uid;		
	int pno;
	char name[20];
	char add[20];
	char favitem[20];
	int pincode;
	prevorder * list;
	menu* mptr;
	struct user_type* next;
	struct user_type* User;
	struct user_type* branch0;
	struct user_type* branch1;
} user;
// Order
typedef struct order_type{
	int oid;
	user * cust;
	char rname[20];
	menu * order;
	agent * dboy;
	int sum;		//total money to be paid  //this would be done by adding up money while ordering or selecting the menu
	struct order_type * next;
	struct order_type * branch0;
	struct order_type * branch1;
} orderlist;
// Global Arrays
rest* Root;
rest* Name[100];
rest* Area[100];
rest* Cuisine[100];
rest* Type[100];
user* ulist;
orderlist* olist;
agent *Agent;
// Insert menu
int length_menu(menu *lptr)
{
	menu *ptr = lptr;
	int length = 0;
	while(ptr != NULL)
	{
		length ++;
		ptr = ptr -> next;
	}
	return length;
}
void printList(menu *lptr)
{
	while(lptr != NULL)
	{
		printf("%d.%s\t",lptr -> data,lptr -> item);
		lptr = lptr -> next;
	}
	printf("\n");
}
void printTree(menu *b_tree)
{
	if(b_tree != NULL)
	{
		printList(b_tree);
		printTree(b_tree -> branch0);
		printTree(b_tree -> branch1);
		if(b_tree->next!=NULL)
		{
			printList(b_tree->next->branch1);
		}
	}
}
menu* sort_menu(menu *lptr)
{
	menu *ptr1 = lptr,*ptr2 = NULL;
	int temp;
	while(ptr1 != NULL)
	{
		ptr2 = ptr1->next;
		while(ptr2 != NULL)
		{
			if(ptr1 -> data > ptr2 -> data)
			{
				temp = ptr2 -> data;
				ptr2 -> data = ptr1-> data;
				ptr1 ->data = temp;
			}
			ptr2 = ptr2 -> next;
		}
		ptr1 = ptr1 -> next;
	}
	return lptr;
}
menu* Insert_Node(menu* p ,menu* Data,int x)
{
	menu* q = p;
	if(x==0)
	{
		while(q->next!=NULL)
		{
			q = q->next;
		}
		q->next = Data;
		p = sort_menu(p);
	}
	if(x==1)
	{
		if(q->data > Data->data)
		{
			if(q->branch0 == NULL)
			{
				q->branch0 = Data;
			}
			else
			{
				q = Insert_Node(q->branch0,Data,1);
			}
		}
		else
		{
		    if(q->branch1 == NULL)
		    {
		        q->branch1 = Data;
		    }
		    else
		    {
		        q = Insert_Node(q->branch1,Data,1);
		    }
		}
		p = sort_menu(p);
	}
	return p;
}
menu* Insert(menu* root,menu* Data)
{
	menu* p,*temp,*prev,*next,*use,*q;
	p = root;
	q = root;
	if(p == NULL)
	{
		root = Data;
	}
	else
	{
		while(p->next!=NULL && (Data->data) > (p->data))
		{
			p = p->next;
		}
		if((p->data) > (Data->data))
		{
			if(p->branch0 == NULL)
			{
				p= Insert_Node(p,Data,0);
			}
			else
			{
				p = Insert(p->branch0,Data);
				if(p->branch0!=NULL && p->branch1!=NULL)
				{
					if(root==NULL)
					{
						root = p;
					}
					else
					{
						if(root->data > p->data)
						{
							p->next = root;
							root->branch0 = p->branch1;
							root = p;
						}
						else
						{
							root->next = p;
							root->branch1 = p->branch0;
						}
					}
				}
			}
			if(length_menu(q)==m)
			{
				int i = m/2;
				temp = q;
				while(i!=0)
				{
					temp = temp->next;
					i--;
				}
				prev = q;
				i = m/2 -1;
				while(i!=0)
				{
					i--;
					prev = prev->next;
				}
				(prev->next) = NULL;
				next = temp->next;
				temp->next = NULL;
				q = Insert_Node(temp,q,1);
				q = Insert_Node(temp,next,1);
				root = q;
			}
		}
		else
		{
			if(p->branch1 == NULL)
			{
				p= Insert_Node(p,Data,0);
			}
			else
			{
				p = Insert(p->branch1,Data);;
				if(p->branch0!=NULL && p->branch1!=NULL)
				{
					if(root==NULL)
					{
						root = p;
					}
					else
					{
						if(root->data > p->data)
						{
							p->next = root;
							root->branch0 = p->branch1;
							root = p;
						}
						else
						{
							root->next = p;
							root->branch1 = p->branch0;
						}
					}
				}
			}
			if(length_menu(q)==m)
			{
				int i = m/2;
				temp = q;
				while(i!=0)
				{
					temp = temp->next;
					i--;
				}
				prev = q;
				i = m/2 -1;
				while(i!=0)
				{
					i--;
					prev = prev->next;
				}
				(prev->next) = NULL;
				next = temp->next;
				temp->next = NULL;
				q = Insert_Node(temp,q,1);
				q = Insert_Node(temp,next,1);
				root = q;
			}
		}
	}
	return root;
}
//Search Menu
menu* search_menu(menu *b_tree,int data)
{
        menu *temp_b,*prev,*lptr,*ret_val = NULL;
        int found = 0;
        if(temp_b -> branch1 == NULL && temp_b -> branch0 == NULL)
    	{
		if(b_tree -> data == data)
		   { 
			found = 1;
			ret_val = b_tree;
		    }
        }
        else
        {
		while(temp_b != NULL && found == 0)
		{
		    prev = NULL;
		    lptr = temp_b;
		    while(lptr != NULL && lptr -> data < data)
		    {
			prev = lptr;
			lptr = lptr -> next;
		    }
		    if(prev == NULL)
		    {
			if(lptr -> data != data)
			    temp_b = lptr -> branch0;
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
			    temp_b = prev -> branch1;
			}
			else
			{
			    temp_b = lptr -> branch1;
			}
		    }
		}
        }
	return ret_val;
}

// Make Node Menu
menu * MakeNode_Menu(char name[],int price,int i)
{
	menu* temp=(menu*)malloc(sizeof(menu));
	temp->next=NULL;
	strcpy(temp->item,name);
	temp->price=price;
	temp->data = i;
	temp->branch0 = temp->branch1 = NULL;
	return temp;
}
// Add Menu Items
menu * addMenu(menu * ptr,int s)
{       //s is the no. of items to be added
        int i=0,price,data;
	if(ptr == NULL)
	{
		data = 0;
	}
	else
	{
		printf("Need number of keys in list\n");		// **********Need function to count number of keys********** //
	}
        char name[20];
        while(i<s){
                i++;
                printf("enter name of dish\n");
                scanf("%s",name);
                printf("input price\n");
                scanf("%d",&price);
                menu* temp = MakeNode_Menu(name,price,i);
		ptr = Insert(ptr,temp);
        }
        return ptr;
}
// Order and user search
// Insert Restaurant
int length_Name(rest *lptr)
{
	rest *ptr = lptr;
	int length = 0;
	while(ptr != NULL)
	{
		length ++;
		ptr = ptr -> next;
	}
	return length;
}
void printList_Name(rest *lptr)
{
	while(lptr != NULL)
	{
		printf("%s\t",lptr -> rname);
		printf("%s\t",lptr -> radd);
		printf("%s\t",lptr -> ctype);
		printf("%s\t",lptr -> rtype);
		printf("%d\t",lptr -> data);
		printf("\n");
		lptr = lptr -> next;
	}
}
void printTree_Name(rest *b_tree)
{
	if(b_tree != NULL)
	{
		printList_Name(b_tree);
		printTree_Name(b_tree -> branch0);
		printTree_Name(b_tree -> branch1);
		if(b_tree->next!=NULL)
		{
			printList_Name(b_tree->next->branch1);
		}
	}
}
rest* sort_Name(rest *lptr)
{
	rest *ptr1 = lptr,*ptr2 = NULL;
	int temp;
	while(ptr1 != NULL)
	{
		ptr2 = ptr1->next;
		while(ptr2 != NULL)
		{
			if(ptr1 -> data > ptr2 -> data)
			{
				temp = ptr2 -> data;
				ptr2 -> data = ptr1-> data;
				ptr1 ->data = temp;
			}
			ptr2 = ptr2 -> next;
		}
		ptr1 = ptr1 -> next;
	}
	return lptr;
}
rest* Insert_Node_Name(rest* p ,rest* Data,int x)
{
	rest* q = p;
	if(x==0)
	{
		while(q->next!=NULL)
		{
			q = q->next;
		}
		q->next = Data;
		p = sort_Name(p);
	}
	if(x==1)
	{
		if(q->data > Data->data)
		{
			if(q->branch0 == NULL)
			{
				q->branch0 = Data;
			}
			else
			{
				q = Insert_Node_Name(q->branch0,Data,1);
			}
		}
		else
		{
		    if(q->branch1 == NULL)
		    {
		        q->branch1 = Data;
		    }
		    else
		    {
		        q = Insert_Node_Name(q->branch1,Data,1);
		    }
		}
		p = sort_Name(p);
	}
	return p;
}
rest* Insert_rest(rest* root,rest* Data)
{
	rest* p,*temp,*prev,*next,*use,*q;
	p = root;
	q = root;
	if(p == NULL)
	{
		root = Data;
	}
	else
	{
		while(p->next!=NULL && (Data->data) > (p->data))
		{
			p = p->next;
		}
		if((p->data) > (Data->data))
		{
			if(p->branch0 == NULL)
			{
				p= Insert_Node_Name(p,Data,0);
			}
			else
			{
				p = Insert_rest(p->branch0,Data);
				if(p->branch0!=NULL && p->branch1!=NULL)
				{
					if(root==NULL)
					{
						root = p;
					}
					else
					{
						if(root->data > p->data)
						{
							p->next = root;
							root->branch0 = p->branch1;
							root = p;
						}
						else
						{
							root->next = p;
							root->branch1 = p->branch0;
						}
					}
				}
			}
			if(length_Name(q)==m)
			{
				int i = m/2;
				temp = q;
				while(i!=0)
				{
					temp = temp->next;
					i--;
				}
				prev = q;
				i = m/2 -1;
				while(i!=0)
				{
					i--;
					prev = prev->next;
				}
				(prev->next) = NULL;
				next = temp->next;
				temp->next = NULL;
				q = Insert_Node_Name(temp,q,1);
				q = Insert_Node_Name(temp,next,1);
				root = q;
			}
		}
		else
		{
			if(p->branch1 == NULL)
			{
				p= Insert_Node_Name(p,Data,0);
			}
			else
			{
				p = Insert_rest(p->branch1,Data);;
				if(p->branch0!=NULL && p->branch1!=NULL)
				{
					if(root==NULL)
					{
						root = p;
					}
					else
					{
						if(root->data > p->data)
						{
							p->next = root;
							root->branch0 = p->branch1;
							root = p;
						}
						else
						{
							root->next = p;
							root->branch1 = p->branch0;
						}
					}
				}
			}
			if(length_Name(q)==m)
			{
				int i = m/2;
				temp = q;
				while(i!=0)
				{
					temp = temp->next;
					i--;
				}
				prev = q;
				i = m/2 -1;
				while(i!=0)
				{
					i--;
					prev = prev->next;
				}
				(prev->next) = NULL;
				next = temp->next;
				temp->next = NULL;
				q = Insert_Node_Name(temp,q,1);
				q = Insert_Node_Name(temp,next,1);
				root = q;
			}
		}
	}
	return root;
}
user * user_search(int num)
{
	int flag=0,p;
	user * ptr=ulist;							//ulist is the assumed global user list
	while(ptr!=NULL && flag==0)
	{
		if(ptr->pno == num){
			flag=1;
		}
		else
			ptr=ptr->User;
	}

	return ptr;
}

user * user_MakeNode()
{
	user* temp=(user *)malloc(sizeof(user));
	temp->next=NULL;
	temp->branch0 = temp->branch1 = NULL;
	printf("give user name\n");
	scanf("%s",temp->name);
	printf("give user phone no\n");
	scanf("%d",&temp->pno);
	printf("give user address\n");
	scanf("%s",temp->add);
	printf("give user pincode\n");
	scanf("%d",&temp->pincode);
	return temp;
}
menu* add_item(menu* Menu)
{
	menu* mptr = MakeNode_Menu(Menu->item,Menu->price,1);		// **********Need function to count number of keys********** //
	return mptr;
}
void add_order(user* nptr,rest* lptr)
{
	int i;
	menu* Menu = lptr->mptr;
	printTree_Name(lptr);
	printf("Enter digit before the food item you want to add\n");
	scanf("%d",&i);
	Menu = search_menu(Menu,i);
	orderlist* optr = (orderlist*)malloc(sizeof(orderlist));
	optr->cust = nptr;
	strcpy(optr->rname,lptr->rname);
	optr->oid = nptr->pno;
	optr->dboy = Agent;
	Agent = Agent->next;
	optr->dboy->coust_phno = nptr->pno;
	optr->order = add_item(Menu);
	optr->next = NULL;
	optr->branch0 = optr->branch1 = NULL; 
	nptr->mptr = Insert(nptr->mptr,add_item(Menu));	// ***** This is to be checked. ***** //
	//olist = Insert_olist(olist,optr);		// ***** Insert_olist is to be made. ***** //
}
void order(rest* lptr)
{
	int num;
	printf("Enter your Number\n");
	scanf("%d",&num);
	user* nptr = user_search(num);		// ***** User Search number se banana padega. ***** //
	if(nptr== NULL)
	{
		printf("Your data is not found please register first\n");
		nptr  =  user_MakeNode();
	}
	add_order(nptr,lptr);
}

rest* MakeNode_rest()
{
	int i;
	rest* lptr = (rest*) malloc (sizeof(rest));
	printf("Enter Name of restaurant ");
	scanf("%s",lptr->rname);
	printf("Enter Address of restaurant ");
	scanf("%s",lptr->radd);
	printf("Enter Cuisine of restaurant ");
	scanf("%s",lptr->ctype);
	printf("Enter type of restaurant ");
	scanf("%s",lptr->rtype);
	printf("Enter Number of seats of restaurant ");
	scanf("%d",&lptr->seats);
	printf("Enter pincode of restaurant ");
	scanf("%d",&lptr->pincode);
	lptr->data = lptr->pincode;
	lptr->name = NULL;
	lptr->area = NULL;
	lptr->cuisine = NULL;
	lptr->type = NULL;
	lptr->branch0 = lptr->branch1 = NULL;
	printf("enter number of menu items to be added");
	scanf("%d",&i);
	lptr->mptr = addMenu(lptr->mptr,i);
	FILE *f=fopen("/home/sanket/Desktop/dspd/data.txt","a");
	fprintf(f,"%s %s %s %s %d %d",lptr->rname,lptr->radd,lptr->ctype,lptr->rtype,lptr->seats,lptr->pincode);
	fclose(f);
	return lptr;
}

int Hash_name(char s[])
{
	int index=0,i=0;
	while(s[i]!='\0')
	{
		index = index + (s[i]-'a');
		index = index%10;
		i++;
	}
	return index;
}
int Hash_area(int pincode)
{
	int index;
	index = (pincode)%100;
	index = index;
	return (index-1);
}
int Hash_cuisine(char s[])
{
	int index;
	if(strcmp(s,"south")==0)
	{
		index = 0;
	}
	else if(strcmp(s,"north")==0)
	{
		index = 1;
	}
	else if(strcmp(s,"chinese")==0)
	{
		index = 2;
	}
	else
	{
		index = -1;
	}
	return index;
}
int Hash_type(char s[])
{
	int index;
	if(strcmp(s,"pub")==0)
	{
		index = 0;
	}
	else if(strcmp(s,"cafe")==0)
	{
		index = 1;
	}
	else if(strcmp(s,"restaurant")==0)
	{
		index = 2;
	}
	else
	{
		index = -1;
	}
	return index;
}
void Add_name(rest*lptr)
{
	int i;
	if(lptr!=NULL)
	{
		i = Hash_name(lptr->rname);
		rest*nptr = Name[i];
		lptr->name = nptr;
		Name[i] = lptr;
	}
}
void Add_area(rest* lptr)
{
	int i;
	if(lptr!=NULL)
	{
		i = Hash_area(lptr->pincode);
		rest*nptr = Area[i];
		lptr->area = nptr;
		Area[i] = lptr;
	}
}
void Add_cuisine(rest* lptr)
{
	int i;
	if(lptr!=NULL)
	{
		i = Hash_cuisine(lptr->ctype);
		rest*nptr = Cuisine[i];
		lptr->cuisine = nptr;
		Cuisine[i] = lptr;
	}
}
void Add_type(rest* lptr)
{
	int i;
	if(lptr!=NULL)
	{
		i = Hash_type(lptr->rtype);
		rest*nptr = Type[i];
		lptr->type = nptr;
		Type[i] = lptr;
	}
}
void Add()
{
	rest* lptr,*nptr;
	int i;
	lptr = (rest*) malloc (sizeof(rest));
	lptr = MakeNode_rest();
	if(lptr!=NULL)
	{
		Root = Insert_rest(Root,lptr);
		Add_name(lptr);
		Add_area(lptr);
		Add_cuisine(lptr);
		Add_type(lptr);
	}
}
void printMenu(rest * r){
	menu * M=NULL;
	M=r->mptr;
	int i=0;
	printf("our menu is \n");
	while(M!=NULL){
		printf("%d.",i);
		printf("%s - %d\n",M->item,M->price);
		M=M->next;
		i++;
	}
}
void search_name()
{
	rest* lptr;
	char s[10];
	int f=0,i;
	printf("Enter the name of Restaurant");
	scanf("%s",s);
	int index = Hash_name(s);
	lptr = Name[index];
	while(lptr!=NULL && f==0)
	{
		if(strcmp(s,lptr->rname)==0)
		{
			printf("Restaurant found\n");
			printf("%s\n",lptr->rname);
			printf("%d\n",lptr->pincode);
			printf("MENU:\n");
			printMenu(lptr);
			f = 1;
		}
		else
		{
			lptr = lptr->name;
		}
	}
	if(f==0)
	{
		printf("Restaurant is not present in our list sorry\n");
	}
	if(lptr!=NULL)
	{
		printf("To order press 1 else 0");
		scanf("%d",&i);
		if(i==1)
		{
			order(lptr);
		}
	}
}


void search_address()
{
	rest* lptr;
	int pincode,index;
	printf("Enter the pincode of area");
	scanf("%d",&pincode);
	index = Hash_area(pincode);
	lptr = Area[index];
	if(lptr!=NULL)
	{
		while(lptr!=NULL)
		{
			if(lptr->pincode==pincode)
			{
				printf("Restaurant found\n");
				printf("%s\n",lptr->rname);
				printf("%d\n",lptr->pincode);
				printf("MENU:\n");
				printMenu(lptr);
			}
			lptr = lptr->area;
		}
	}
	else
	{
		printf("Sorry!! We do not serve in your area\n");
	}
}
void search_cuisine()
{
	rest* lptr;
	int f=0,index;
	char s[10];
	printf("Enter the cuisine of Restaurant");
	scanf("%s",s);
	index = Hash_cuisine(s);
	lptr = Cuisine[index];
	while(lptr!=NULL)
	{
		if(strcmp(lptr->ctype,s)==0)
		{
			printf("Restaurant found\n");
			printf("%s\n",lptr->rname);
			printf("%d\n",lptr->pincode);
			printf("MENU:\n");
			printMenu(lptr);
			f = 1;
		}
		lptr = lptr->cuisine;
	}
	if(f==0)
	{
		printf("Restaurant is not present in our list sorry\n");
	}
}void search_type()
{
	rest* lptr;
	int f=0,index;
	char s[10];
	printf("Enter the type of Restaurant");
	scanf("%s",s);
	index = Hash_type(s);
	lptr = Type[index];
	while(lptr!=NULL)
	{
		if(strcmp(lptr->rtype,s)==0)
		{
			printf("Restaurant found\n");
			printf("%s\n",lptr->rname);
			printf("%d\n",lptr->pincode);
			printf("MENU:\n");
			printMenu(lptr);
			f = 1;
		}
		lptr = lptr->type;
	}
	if(f==0)
	{
		printf("Restaurant is not present in our list sorry\n");
	}
}
void search()
{
	int i;
	printf("Enter your choice of search\n");
	printf("1. Search By Name\n");
	printf("2. Search By Address\n");
	printf("3. Search By Cuisine\n");
	printf("4. Search By Type\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1: search_name();
		break;
		case 2: search_address();
		break;
		case 3: search_cuisine();
		break;
		case 4: search_type();
		break;
		default: break;
	}
}
// Favourite Item
void favitem(user * ptr){
		prevorder * pptr=ptr->list;
		menu * mptr=ptr->list->Olist,*tmptr;
		char i[20];
		strcpy(i,mptr->item);
		int freq=0,nfreq=0;
			while(pptr!=NULL){
				mptr=pptr->Olist;
				while(mptr!=NULL){
					tmptr=mptr->next;
					while(tmptr!=NULL){
						if(strcmp(mptr->item,tmptr->item)==0){
							nfreq+=1;
						}
						else{
							tmptr=tmptr->next;
						}
					}
					if(nfreq>freq){
						freq=nfreq;
						strcpy(i,mptr->item);
					}
					mptr=mptr->next;
				}
				pptr=pptr->next;
			}
		strcpy(ptr->favitem,i);
}
// Place Order
void place_order()
{
	search_name();	
}
void delivered()
{
	int id,flag=0,ph;
	printf("Enter your phone number");
	scanf("%d",&ph);
	orderlist* ptr=olist,*prev=NULL;				//olist is the assumed starting pointer of the universal order list
	while(ptr!=NULL && flag==0)
	{
		
		if(ptr->oid==ph )
		{
			flag=1;
			ptr->dboy->comm+=(ptr->sum/10);		//for 10% commision being added to the agent
			if(prev==NULL){
				olist=ptr->next;
				
				
			}
			else{
				prev->next=ptr->next;
				
			}

//yaha se
			(ptr->cust)->list=(prevorder *) malloc (sizeof(prevorder));
			(ptr->cust)->list->next=NULL;
			(ptr->cust)->list->Olist=(menu*)malloc(sizeof(menu));
			(ptr->cust)->list->Olist->next=NULL;				
			(ptr->order)->next=((ptr->cust)->list)->Olist->next;		//adding order in users preordered list
			ptr->cust->list->Olist=ptr->order;
			strcpy(ptr->cust->list->rname,ptr->rname);
			favitem(ptr->cust);
			printf("fav item is:%s \n",ptr->cust->favitem);
//yaha tk

			ptr->dboy->next = Agent;
			Agent = ptr->dboy; 
			free(ptr);
		}
		else
			prev=ptr;
			ptr=ptr->next;
	}
	if(flag == 1)
		printf("done\n");
	else
		printf("No current order on your ACCOUNT");
}
void cancel(){
	printf("input your phone number\n");
	int id,flag=0,ph;
	scanf("%d",&ph);
	orderlist * ptr=olist,*prev=NULL;				//olist is the assumed starting pointer of the universal order list
	while(ptr!=NULL && flag==0){
		if(ptr->oid==ph ){
			flag=1;
			if(prev==NULL){
				olist=ptr->next;
			}
			else{
				prev->next=ptr->next;
				
			}
			ptr->dboy->next = Agent;
			Agent = ptr->dboy; 
			free(ptr);							//only successfully served orders are added to the previous order list of the user
		}
		else
			prev=ptr;
			ptr=ptr->next;
	}
	if(flag == 1)
		printf("cancelled\n");
	else
		printf("NO order to delete\n");
}
void details()
{
	int num,f=0;
	printf("Enter your mobile number");
	scanf("%d",&num);
	orderlist* optr;
	optr = olist;
	while(optr!=NULL)
	{
		if(optr->dboy->coust_phno = num);
		{
			printf("agent details\n");
			printf("phone number %d\n",optr->dboy->pno);
			printf("Name: %s",optr->dboy->name);
			f = 1;
		}
		optr=optr->next;
	}
	if(f==0)
	{
		printf("You have no order ongoing ");
	}
}
void agent_details()
{
	agent* aptr;
	aptr = Agent;
	while(aptr!=NULL)
	{
		printf("%s\n",aptr->name);
		printf("%d\n",aptr->pno);
		aptr = aptr->next;
	}
}
void All_orders()
{
	orderlist* optr;
	optr = olist;
	if(optr==NULL)
	{
		printf("No orders to show\n");
	}
	while(optr!=NULL)
	{
		printf("order id is : %d\n",optr->oid);
		menu * M=NULL;
		M = optr->order;
		int i=0;
		printf("your order \n");
		while(M!=NULL){
		printf("%d .",i);
		printf("%s - %d\n",M->item,M->price);
		M = M->next;
		i++;
		}
		optr = optr->next;
	}
}
/*int main()			// ***** Search_menu is to be made. ***** //
{
	menu* ptr = NULL,*lptr = NULL;
	int n;
	//printf("Enter number of elements to be added\n");
	//scanf("%d",&n);
	//ptr = addMenu(ptr,n);
	//printTree(ptr);
	//lptr = search_menu(ptr,2);
	//Add();
	//printTree_Name(Root);
	//Add();
	//printTree_Name(Root);
	//search_cuisine();
	return 0;
}
*/
void initiliase()
{
	int i;
	for(i=0;i<100;i++)
	{
		Name[i] = NULL;
		Area[i] = NULL;
		Cuisine[i] = NULL;
		Type[i] = NULL;
	}
	olist = NULL;
	ulist = NULL;
	Agent = NULL;
	Root = NULL;
}
int main()
{	
	initiliase();
	//agent_init();
	//data_rest();
	//data_agent();
	int i,flag=1;
	printf("WELCOME TO THE APP\n");
	while(flag==1)
	{
		printf("\n0.To close the app\n");
		printf("1.Search Restaurant\n");
		printf("2.Add Restaurant\n");
		printf("3.Order from Restaurant\n");
		printf("4.TO check details of your order\n");
		printf("5.TO confirm delivery of order\n");
		printf("6.To cancle the order\n");
		printf("7.Agent details\n");
		printf("8.All orders\n");
		scanf("%d",&i);
		switch(i)
		{
			case 0: flag=0;
			break;
			case 1: search();
			break;
			case 2: Add();
			break;
			case 3: place_order();
			break;
			case 4: details();
			break;
			case 5: delivered();
			break;
			case 6: cancel();
			break;
			case 7: agent_details();
			break;
			case 8: All_orders();
			break;
			default: break;
		}
	}
	return 0;
}
