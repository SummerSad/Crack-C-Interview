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

int longest_distance(int *arr, int n)
{
	int result = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(arr[i]*arr[j] < 0)
			{
				int temp = arr[i] > arr[j] ? arr[i] - arr[j] : arr[j] - arr[i];
				if(result < temp)
					result = temp;
			}
		}
	}
	return result;

}

int main()
{
	int *arr = NULL;
	int n = 5;
	input_arr(arr, n);
	printf("%d\n", longest_distance(arr, n));
	free(arr);
	return 0;
}
