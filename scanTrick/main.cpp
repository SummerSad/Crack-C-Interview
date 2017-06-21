#include <stdio.h>
#define MAX 100

int main()
{
	char str[MAX];
	// scanf with \n
	// %[^\n] mean read everything except \n
	// trick &[^\n]%*c
	scanf("%[^\n]%*c", str);
	printf("%s.\n", str);
	char str2[MAX];
	scanf("%[^\n]%*c", str2);
	printf("%s.\n", str2);
	char str3[MAX];
	scanf("%[^\n]%*c", str3);
	printf("%s.\n", str3);
	return 0;
}
