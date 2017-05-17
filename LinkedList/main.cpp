#include "LinkedList.h"

int main()
{
	SNode *SHead = NULL;
	addSHead(SHead, 3);
	addSHead(SHead, 4);
	addSHead(SHead, 5);
	reverseSNode(SHead);
	printSNode(SHead);
	return 0;
}
