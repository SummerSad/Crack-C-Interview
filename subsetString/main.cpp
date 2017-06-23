#include <stdio.h>
#define MAXCHAR 256

// return true if char in string b can reorganize to string a
// example: this --- hist
// example: xxt --- xtx
bool isSubset(char *a, char *b)
{
	int char_a[MAXCHAR] = {0};
	int char_b[MAXCHAR] = {0};
	for(int i = 0; a[i] != '\0'; i++)
	{
		char_a[(int)a[i]]++;
	}
	for(int i = 0; b[i] != '\0'; i++)
	{
		char_b[(int)b[i]]++;
	}
	for(int i = 0; i < MAXCHAR; i++)
	{
		if(char_a[i] != char_b[i])
			return false;
	}
	return true;
}

int main()
{
	printf("%d\n", isSubset("hack", "hcka"));
	return 0;
}
