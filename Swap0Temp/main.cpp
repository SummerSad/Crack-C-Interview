#include <stdio.h>

void swap(int &x,int &y)
{
	x=x+y;
	y=x-y;
	x=x-y;
}

int main()
{
	int x=20;
	int y=5;
	swap(x,y);
	printf("%d %d\n",x,y);
	return 0;
}
