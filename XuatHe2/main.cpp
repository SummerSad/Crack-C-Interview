#include <stdio.h>

void XuatHe2(long n)
{
	if(n == 1)
		printf("1");
	else if(n > 1)
	{
		XuatHe2(n / 2);
		printf("%d", n % 2);
	}
}

int main()
{
	XuatHe2(13);
	return 0;
}
