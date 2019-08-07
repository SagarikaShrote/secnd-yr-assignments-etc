#include<stdio.h>
#include<stdlib.h>
#include "fn.c"

main(){
	set s1,s2,unions,intersectns,diffs;
	statuscode sc;
	boolean b;
	int size,temp=0;
	itemtype * arr,e;
	int flag=1,choice;
	while(flag==1){
		printf("1.create a set.\n2.create second set.\n3.build first set.\n4.build second set.\n5.size of first set.\n6.size of second set.\n7.print first set.\n8.print second set.\n9.check if set 1 is empty.\n10.check if set 2 is empty\n11.check presence of any element in set 1\n12.check presence of any element in set 2.\n13.list of elements in set 1\n14.list of elements in set 2\n15.add element in set 1\n16.add element in set 2\n17.remove any element from set 1\n18.remove any element from set 2\n19.union of set 1 and set 2\n20.intersection of set 1 and set 2\n21.difference s1-s2\n22.difference s2-s1\n23.is s1 subset of s2?\n24.is s2 subset of s1?\n");
	
		scanf("%d",&choice);
		switch(choice){
			case 1:	{
					createSet(&s1);
					printf("created a new set\n");
				}
					break;
			case 2:{
					createSet(&s2);
					printf("created another new set\n");
				}
					break;
			case 3:{
					
					printf("give no. of elements\n");
					scanf("%d",&size);
					arr=(itemtype*) malloc (sizeof(itemtype)*size);
					for(temp=0;temp<size;temp++){
						scanf("%d",&arr[temp]);
					}
					sc=buildSet(&s1,arr,size);
					if(sc==FAILURE){
						printf("error building set\n");
					}
					else{
						printf("build successful\n");
					}
					free(arr);
								
				}	
					break;
			case 4:{
					printf("give no. of elements\n");
					scanf("%d",&size);
					arr=(itemtype*) malloc (sizeof(itemtype)*size);
					for(temp=0;temp<size;temp++){
						scanf("%d",&arr[temp]);
					}
					sc=buildSet(&s2,arr,size);
					if(sc==FAILURE){
						printf("error building set\n");
					}
					else{
						printf("build successful\n");
					}
					free(arr);
				}
					break;
			case 5:{
					printf("size of set1:%d\n",sizeOf(&s1));
				}
					break;
			case 6:{
					printf("size of set2:%d\n",sizeOf(&s2));
				}
					break;
			case 7:{
					printSet(&s1);
				}
					break;
			case 8:{
					printSet(&s2);
				}
					break;
			case 9:{
					b=isSetEmpty(&s1);
					if(b==True){
						printf("set is empty\n");
					}
					else{
						printf("set is not empty\n");
					}
				}
					break;
			case 10:{
					b=isSetEmpty(&s2);
					if(b==True){
						printf("set is empty\n");
					}
					else{
						printf("set is not empty\n");
					}
				}
					break;
			case 11:{
					printf("enter the element you want to check\n");
					scanf("%d",&e);
					b=isElementOf(&s1,e,&temp);
					if(b==True){
						printf("element is present in the set at position %d\n",temp);
					}
					else{
						printf("no such element found in the set\n");
					}
					
				}
					break;
			case 12:{
					printf("enter the element you want to check\n");
					scanf("%d",&e);
					b=isElementOf(&s2,e,&temp);
					if(b==True){
						printf("element is present in the set at position %d\n",temp);
					}
					else{
						printf("no such element found in the set\n");
					}
					
				}
					break;
			case 13:{
					arr=enumerate(&s1,&size);
					printf("the elements are:\n");
					for(temp=0;temp<size;temp++){
						printf("%d\n",arr[temp]);
					}
				}
					break;
			case 14:{
					arr=enumerate(&s2,&size);
					printf("the elements are:\n");
					for(temp=0;temp<size;temp++){
						printf("%d\n",arr[temp]);
					}
				}
					break;
			case 15:{	
					printf("enter element to add:\n");
					scanf("%d",&e);
					sc= addElement(&s1,e);
					if(sc==FAILURE){
						printf("error adding element\nthe set contains:\n");
						printSet(&s1);
					}
					else{
						printf("element added successfully\nthe new set contains:\n");
						printSet(&s1);
					}		
				}
					break;
			case 16:{
					printf("enter element to add:\n");
					scanf("%d",&e);
					sc= addElement(&s2,e);
					if(sc==FAILURE){
						printf("error adding element\nthe set contains:\n");
						printSet(&s2);
					}
					else{
						printf("element added successfully\nthe new set contains:\n");
						printSet(&s2);
					}
				}
					break;
			case 17:{
					printf("enter element to remove:\n");
					scanf("%d",&e);
					sc= removeElement(&s1,e);
					if(sc==FAILURE){
						printf("error removing element\nthe set contains:\n");
						printSet(&s1);
					}
					else{
						printf("element removed successfully\nthe new set contains:\n");
						printSet(&s1);
					}
				}
					break;
			case 18:{
					printf("enter element to remove:\n");
					scanf("%d",&e);
					sc= removeElement(&s2,e);
					if(sc==FAILURE){
						printf("error removing element\nthe set contains:\n");
						printSet(&s2);
					}
					else{
						printf("element removed successfully\nthe new set contains:\n");
						printSet(&s2);
					}
				}
					break;
			case 19:{
					unions=unionOfSet(&s1,&s2);
					printSet(&unions);
				}
					break;
			case 20:{
					intersectns=intersectionOfSet(&s1,&s2);
					printSet(&intersectns);
				}
					break;
			case 21:{
					diffs=differenceOfSet(&s1,&s2);
					printSet(&diffs);
				}
					break;
			case 22:{
					diffs=differenceOfSet(&s2,&s1);
					printSet(&diffs);
				}
					break;
			case 23:{
					b=isSubsetOf(&s2,&s1);
					if(b==True){
						printf("set1 is subset of set2\n");
					}
					else{
						printf("set1 is not a subset of set2\n");
					}
				}
					break;
			case 24:{
					b=isSubsetOf(&s1,&s2);
					if(b==True){
						printf("set2 is subset of set1\n");
					}
					else{
						printf("set2 is not a subset of set1\n");
					}
				}
					break;
			default: printf("\nenter a valid choice\n");
					break;		
		}
	printf("press 1 to go back to menu or 0 to end");
	scanf("%d",&flag);
	}
}
