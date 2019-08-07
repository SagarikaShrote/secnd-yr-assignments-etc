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

void createSet(set * sptr);

node * makeNode(node * nptr, itemtype data);

statuscode buildSet(set * sptr, itemtype e[], int n);

int sizeOf(set * sptr);

boolean isSetEmpty(set * sptr);

boolean isElementOf(set * sptr, itemtype data, int * pos);

itemtype * enumerate(set* sptr, int * size);

statuscode addElement(set * sptr, itemtype e);

statuscode removeElement(set * sptr, itemtype e);

set unionOfSet( set * s1ptr, set * s2ptr);

set intersectionOfSet( set * s1ptr, set * s2ptr);

set differenceOfSet( set * s1ptr, set * s2ptr);

boolean isSubsetOf(set * sptr, set * ssptr);

void printSet(set * sptr);
