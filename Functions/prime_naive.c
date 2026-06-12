//check prime on. using naive approach
#include<stdio.h>

//function to check prime no.
void checkPrime(int N)
{
	//initially flag is set to true or 1
	int flag = 1;

	//loop to iterate through 2 to N/2
	for (int i =2;i<=N/2 ;i++)
	{	//if N is perfectly divisible by 1 
		//flag is set to 0 i.e false
		if( N%i ==0)
		{
			flag=0;
			break;
		}
	}

	if(flag)
	{
		printf("%d-prime\n",N);
	}
	else
	{
		printf("not a prime\n");
		
	}
	return;
}
//driver code
 int main()
{
	int N;
	printf("enter no. :");
	scanf("%d",&N);

	checkPrime(N);
	return 0;
	     
}

