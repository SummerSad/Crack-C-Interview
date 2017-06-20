#include <stdio.h>
#define UNSOLVED -1
#define MAX 40

int Fibo_result(int n);
int Fibo_solve(int *arr, int n);
int Fibo2(int n);
int Fibo3(int n);

int main()
{
	for(int i = 1; i < MAX; i++)
	{
		printf("%d %d\n", Fibo_result(i), Fibo2(i));
	}
	return 0;
}

int Fibo_solve(int *arr, int n)
{
	if(n < 1)
		return -1;
	if(arr[n - 1] != UNSOLVED)
		return arr[n - 1];
	else
	{
		if(n % 2 == 0)
		{
			int temp = n / 2;
			arr[n - 1] = 2 * Fibo_solve(arr, temp) * Fibo_solve(arr, temp + 1) - Fibo_solve(arr, temp) * Fibo_solve(arr, temp);
		}
		else
		{
			int temp = (n - 1) / 2;
			arr[n - 1] = Fibo_solve(arr, temp + 1) * Fibo_solve(arr, temp + 1) + Fibo_solve(arr, temp) * Fibo_solve(arr, temp);
		}
	}
	return arr[n - 1];
}
int Fibo_result(int n)
{
	int result;
	// Tao bang luu loi giai
	int *arr = new int[n];
	for(int i = 0; i < n; i++)
	{
		arr[i] = -1;
	}
	// Gia tri dau
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;

	result = Fibo_solve(arr, n);
	delete[]arr;
	return result;
}

int Fibo2(int n)
{
	// Gia tri dau
	int *arr = new int[n];
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;

	for(int i = 3; i < n; i++)
	{
		if((i + 1) % 2 == 0)
		{
			int temp = (i + 1) / 2;
			arr[i] = 2 * arr[temp - 1] * arr[temp] - arr[temp - 1] * arr[temp - 1];
		}
		else
		{
			int temp = i / 2;
			arr[i] = arr[temp] * arr[temp] + arr[temp - 1] * arr[temp - 1];
		}
	}

	int result = arr[n - 1];
	delete[]arr;
	return result;
}

int Fibo3(int n);
