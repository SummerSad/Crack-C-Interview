#include <stdio.h>
#include <string.h>
#define SPACE ' '
int countWord(char *str, int n)
{
	int count = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		int lenWord = 0;
		//Khi khong co khoang trang
		//Bat dau dem tu
		while(str[i] != SPACE && i < strlen(str))
		{
			i++;
			lenWord++;
		}
		if(lenWord > n)
			count++;
	}
	return count;
}

int main()
{
	char *s = " Phuc Loc Tho";
	printf("%d\n", countWord(s, 0));
	return 0;
}
