#include <stdio.h>

bool isPrime(int n)
{
	if(n < 2)
		return false;
	if(n == 2)
		return true;
	if(n > 2 && n % 2 == 0)
		return false;
	for(int i = 3; i * i <= n; i += 2)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int nextPrime(int prime_1)
{
	if(prime_1 == 2)
		return 3;
	int prime_2;
	for(prime_2 = prime_1 + 2;; prime_2 += 2)
	{
		bool flag = true;
		for(int i = 3; i * i < prime_2; i += 2)
		{
			if(prime_2 % i == 0)
				flag = false;
		}
		if(flag)
			return prime_2;
	}
}

int main()
{
	int MAX = 100000;
	for(int i = 0; i < MAX; i++)
	{
		if(isPrime(i))
		{
			printf("%d %d\n", i, nextPrime(i));
		}
	}
	return 0;
}
