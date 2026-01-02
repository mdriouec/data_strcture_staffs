#include <stdio.h>
#include <stdlib.h>

unsigned long long fact(int n)
{
	if( n < 0 ) return 0;
	unsigned long long result = 1;
	for( int i = 2; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
int main()
{
	int num;
	printf("Enter a number :");
	scanf("%d", &num);
	unsigned long long f = fact(num);
	printf("%d! = %llu\n", num, f);
	return 0;
}
