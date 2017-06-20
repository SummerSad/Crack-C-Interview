#include <stdio.h>

const int MaxSize = 1024;

char *strinput()
{
	char *Buff = new char[MaxSize];
	scanf("%s", Buff);
	return Buff;
}

int main()
{
	char *arr = strinput();
	printf("%s\n", arr);
	return 0;
}
