#include <stdio.h>
#include <stdlib.h>
#define SPACE ' '

int my_strlen(char *src);
char *ChuanHoa(char *src);
char Lower(char c)
{
	char result;
	if(c >= 'A' && c <= 'Z')
	{
		result = c - 'A' + 'a';
		return result;
	}
	return c;
}
char Upper(char c)
{
	char result;
	if(c >= 'a' && c <= 'z')
	{
		result = c + 'A' - 'a';
		return result;
	}
	return c;
}
int main()
{
	char *p = ChuanHoa(" pHuc    lOc        tHo ");
	printf("%s.", p);
	return 0;
}

int my_strlen(char *src)
{
	int temp = 0;
	char *p = src;
	while(*p)
	{
		temp++;
		p++;
	}
	return temp;
}
char *ChuanHoa(char *src)
{
	char *p = (char *)malloc(my_strlen(src) + 1);
	int temp = 0, i = 0;
	//Xoa khoang trang dau tien
	while(src[i] == SPACE)
		i++;
	//Xoa khoang trang giua cac tu +  Viet hoa
	for(; i < my_strlen(src); i++)
	{
		if(src[i] != SPACE)
		{
			if(src[i - 1] == SPACE)
				p[temp++] = Upper(src[i]);
			else
				p[temp++] = Lower(src[i]);
		}
		else if(src[i] == SPACE && src[i + 1] != SPACE && i + 1 < my_strlen(src))
			p[temp++] = src[i];
	}
	p[0] = Upper(p[0]);
	p[temp] = '\0';
	return p;
}
