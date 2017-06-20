#include <stdio.h>

int calc_mang(int n, int a)
{
	int *arr = new  int[n + 1];
	arr[0] = a;
	arr[1] = 2 * a;
	arr[2] = 5 * a;
	for(int i = 3; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 15 * arr[i - 2] * arr[i - 3];
	}
	int result = arr[n];
	delete[]arr;
	return result;
}

int calc_0mang(int n, int a)
{
	int x, y, z;
	x = a;
	y = 2 * a;
	z = 5 * a;
	if(n == 0)
		return x;
	if(n == 1)
		return y;
	if(n == 2)
		return z;
	for(int i = 3; i <= n; i++)
	{
		if(x > y && x > z) //y<z<x
		{
			y = 15 * y * z + x;
		}
		else if(y > x && y > z) //z<x<y
		{
			z = 15 * z * x + y;
		}
		else //x<y<z
		{
			x = 15 * x * y + z;
		}
	}
	int result;
	if(x > y && x > z)
	{
		result = x;
	}
	else if(y > x && y > z)
	{
		result = y;
	}
	else
	{
		result = z;
	}
	return result;
}

int main()
{
	int T = 8;
	for(int i = 0; i < T; i++)
	{
		printf("%d %d\n", calc_mang(i, 1), calc_0mang(i, 1));
	}
	return 0;
}
