//check if no. is prime using sqrt(n)
#include<math.h>
#include<stdio.h>

int main()
{
	int N;
	printf("enter No. :");
	scanf("%d",&N);

	int flag =1;
	double sqroot =sqrt(N);

	//iterate from 2 to sqrt(n)
	for ( int i=2; i<=sqroot ;i++)
	{
		//if n is divisible by any no. between 2 and 
		//sqrt(n) ,it is not prime
		if (N%i == 0)
		{
			flag =0;
			break;
		}
	}

	if(flag)
		printf("%d -prime\n",N);
	
	else
		printf("%d-not prime\n",N);
	return 0;
}

	
