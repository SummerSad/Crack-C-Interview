#include <stdio.h>

int main()
{
	// some macro to remember
	// __FILE__ source name
	// __LINE__ current line
	// __DATE__
	// __TIME__
	// __TIMESTAMP__ compile date
	printf("%s\n", __FILE__);
	printf("%d\n", __LINE__); //line is 12
	printf("%d\n", __LINE__); //line is 13
	printf("%s\n", __TIMESTAMP__);
	return 0;
}
