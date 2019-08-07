#include<stdio.h>
#include<stdlib.h>


typedef enum statuscode {FAILURE,SUCCESS} statuscode;

typedef enum boolean {False,True} boolean;

typedef int itemtype;

typedef struct node_type{
	itemtype data;
	struct node_type * next;
} node;

typedef struct set_type{
	node * start;
} set;


//this fn should be called as the first operation on a new set always
void createSet(set * sptr){
	sptr->start=NULL;
}

//this fn is a helper fn and is not for the use of the user
node * makeNode(node * nptr, itemtype data){
	nptr=(node *)malloc(sizeof(node));
	if(nptr!=NULL){
		nptr->next=NULL;
		nptr->data=data;
	}
	return nptr;
}

//this fn takes list of elements as array and n is the size of the same
statuscode buildSet(set * sptr, itemtype e[], int n){
	node * nptr;
	statuscode sc=SUCCESS;
	int i=0;
	while(i<n && sc==SUCCESS){
		nptr=makeNode(nptr,e[i]);
		i++;
		if(nptr==NULL){
			sc=FAILURE;
		}
		else{
			nptr->next=sptr->start;
			sptr->start=nptr;
		}
	}
	return sc;
}

//this fn returns integer type data
int sizeOf(set * sptr){
	node * nptr= sptr->start;
	int count=0;
	while(nptr!=0){
		count++;
		nptr=nptr->next;
	}
	return count;
}

//this fn returns boolean type data where true means set is empty and false means it is not empty which does not necessarily mean it is full
boolean isSetEmpty(set * sptr){
	boolean check=False;
	if(sptr->start==NULL){
		check=True;
	}
	return check;
}

//this fn also returns a boolean type data where true means the element is present in the given set and false means it is not.
//also position of the element in the set is returned back through the pointer pos.
boolean isElementOf(set * sptr, itemtype data, int * pos){
	*pos=0;
	boolean check=False;
	node * nptr= sptr->start;
	while(nptr!=NULL && check==False){
		(*pos)++;
		if(nptr->data==data){
			check=True;
		}
		else{
			nptr=nptr->next;
		}
	}
	if(check==False){
		*pos=0;
	}
	return check;
}

//this fn returns the elements of the set in the form of an array whose size will be stored in a pointer to an integer type element "size" which should be passed as an input by the user
itemtype * enumerate(set* sptr, int * size){
	
	int len = *size = sizeOf(sptr);
	itemtype * elist= (itemtype *)malloc (sizeof(itemtype)*len);
	node * nptr= sptr->start;
	int i=0;
	while(nptr!=NULL){
		elist[i]=nptr->data;
		i++;
		nptr=nptr->next;
	}
	return elist;
}

//this fn adds the element e in the given set only and only if it is not already present in the set
statuscode addElement(set * sptr, itemtype e){
	statuscode sc=SUCCESS;
	node * nptr=makeNode(nptr,e);
	if(nptr==NULL){
		sc=FAILURE;
	}
	else{
		int temp=0;
		if(!isElementOf(sptr,e,&temp)){
			nptr->next=sptr->start;
			sptr->start=nptr;
		}
		else{
			sc=FAILURE;
		}
	}
	return sc;
}

//this fn removes the given element from the link list if it is present
statuscode removeElement(set * sptr, itemtype e){
	node * pptr=NULL;
	node * nptr=sptr->start;
	statuscode sc= FAILURE;
	while(nptr!=NULL && sc==FAILURE){
		if(nptr->data==e){
			sc=SUCCESS;
			if(pptr!=NULL){
				pptr->next=nptr->next;
			}
			else{
				sptr->start=nptr->next;
			}
			free(nptr);
		}
		else{
			pptr=nptr;
			nptr=nptr->next;
		}
	}
	return sc;
}

//this fn returns a "set" type element containing unique elements from the two given sets
set unionOfSet( set * s1ptr, set * s2ptr){
	set us;
	createSet(&us);
	node * nptr=s1ptr->start;
	while(nptr!=NULL){
		addElement(&us,nptr->data);
		nptr=nptr->next;
	}
	nptr=s2ptr->start;
	while(nptr!=NULL){
		addElement(&us,nptr->data);
		nptr=nptr->next;
	}
	return us;
}

//this fn returns a "set" type element containing elements of the two given sets which are common in them
set intersectionOfSet( set * s1ptr, set * s2ptr){
	set is;
	createSet(&is);
	node * nptr=s1ptr->start;
	int temp=0;
	while(nptr!=NULL){
		if(isElementOf(s2ptr,nptr->data,&temp)){
			addElement(&is,nptr->data);
		}
		nptr=nptr->next;
	}
	return is;
}

//this fn returns a set type element which contains the difference of the second set from first (s1-s2) meaning that it contains elements that are present in set1 but not in set2
set differenceOfSet( set * s1ptr, set * s2ptr){
	node * nptr=s1ptr->start;
	set ds;
	createSet(&ds);
	int temp=0;
	while(nptr!=NULL){
		if(!isElementOf(s2ptr,nptr->data,&temp)){
			addElement(&ds,nptr->data);
		}
		nptr=nptr->next;
	}
	return ds;
}

//this fn tests if the set pointed to by ssptr is subset of that pointed by sptr or not and returns a boolean type element where true means it is a subset and false means it is not a subset
boolean isSubsetOf(set * sptr, set * ssptr){
	node * nptr=ssptr->start;
	boolean check=True;
	int temp=0;
//it is notable that a null set is always a subset of any set
	while(nptr!=NULL && check!=False){
		if(!isElementOf(sptr,nptr->data,&temp)){
			check=False;
		}
		nptr=nptr->next;
	}
	return check;
}

//this is a helper fn which prints the elements contained in the set
void printSet(set * sptr){
	node * nptr=sptr->start;
	printf("\n your set contains following elements\n");
	while(nptr!=NULL){
		printf("%d\n",nptr->data);
		nptr=nptr->next;
	}
}

