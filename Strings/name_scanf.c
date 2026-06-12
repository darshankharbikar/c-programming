//C prog to demonstrate printing of 
//our own name using scanf

#include<stdio.h>

int main()
{
	char name[20];
	printf("Enter name :\n");

	//user input will be taken here
	scanf("%s",name);
	printf("Name is %s\n",name);
	return 0;
}


