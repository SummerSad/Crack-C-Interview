#include <stdio.h>
#include <stdlib.h>

void input_arr(int *&arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		arr = (int *)realloc(arr, sizeof(int) * (i + 1));
		printf("%dth: ", i);
		scanf("%d", &arr[i]);
	}
}

void chen0(int *&arr, int &n)
{
	int *temp = new int[2 * n];
	int len_temp = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] % 2 != 0 || arr[i] == 0)
		{
			temp[len_temp++] = arr[i];
		}
		else
		{
			temp[len_temp++] = 0;
			temp[len_temp++] = arr[i];
		}
	}
	arr = (int *)realloc(arr, sizeof(int) * len_temp);
	for(int i = 0; i < len_temp; i++)
	{
		arr[i] = temp[i];
	}
	delete[]temp;
	n = len_temp;
}

int main()
{
	int *arr = NULL;
	int n = 5;
	input_arr(arr, n);
	chen0(arr, n);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	return 0;
}
