#include <stdio.h>

//short %hi
struct Circle
{
	short X, Y, R;
};

void readCircle()
{
	FILE *bin = fopen("CIRCLES.BIN", "rb");
	if(bin == NULL)
	{
		printf("No files\n");
		return;
	}
	short N;
	fread(&N, sizeof(short), 1, bin);
	Circle *arr = new Circle[N];
	for(int i = 0; i < N; i++)
	{
		fread(&arr[i], sizeof(Circle), 1, bin);
	}
}

int main()
{
	printf("%d\n", sizeof(Circle));
	return 0;
}
