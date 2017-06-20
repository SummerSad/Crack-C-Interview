#include <stdio.h>

int my_atoi(char *str)
{
	int result=0;
	char *p=str;
	while(*p)
	{
		if(*p>='0' && *p<='9')
		{
			result=result*10+*p-'0';
		}
		p++;
	}
	return result;
}

char *my_strstr(char *src,char *sub)
{
	char *p=src;
	bool Flag;
	while(*p)
	{
		Flag=true;
		for(int i=0;sub[i]!='\0' && p[i]!='\0';i++)
		{
			if(*(p+i)!=*(sub+i))
				Flag=false;
		}
		if(Flag==true)
			return p;
		p++;
	}
	return NULL;
}

int main()
{
	printf("%s\n",my_strstr("abctest","bc_"));
	return 0;
}
