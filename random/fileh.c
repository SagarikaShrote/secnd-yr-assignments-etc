#include<stdio.h>

main(){
FILE * f= fopen("/home/sagarika/Desktop/file","r");
char name[10],sname[10];
int age;
 while(!feof(f)){
	fscanf(f,"%s %s %d",name,sname,&age);
	printf("%s %s %d\n",name,sname,age);
	
}
fclose(f);
}
