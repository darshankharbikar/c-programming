//Wilson’s Theorem states that the prime number p completely divides ((p – 1)! + 1), i.e. ((p – 1)! + ) % p == 0.

#include<stdio.h>

//utility function to evaluate factorial
long long int getFactorial(int n)
{
	long long int f=1;
	for (int i=2; i<=n; i++)
	{
		f *=i;
	}
	return f;
}

//function to check prime no
void checkPrime(int N)
{
	long long fact =getFactorial(N-1);

	if (fact % N == N-1)
		printf("%d-prime\n",N);
	else
		printf("%d -not a prime\n",N);

return;
}

//driver code
int main()
{
	int N;

	printf("enter the no.s :");
	scanf("%d",&N);

	checkPrime(N);
	return 0;
}


