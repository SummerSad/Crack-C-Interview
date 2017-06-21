#include <stdio.h>
#include <math.h>

// so sanh tung byte cua float
bool compareFloat(float f1, float f2)
{
	char *c1 = (char *)&f1;
	char *c2 = (char *)&f2;
	for(int i = 0; i < sizeof(float); i++)
	{
		if(c1[i] != c2[i])
			return false;
	}
	return true;
}

int main()
{
	float a, b;
	a = 0.003;
	b = 0.003;
	//a==b is wrong
	if(compareFloat(a, b))
		printf("True\n");
	return 0;
}
