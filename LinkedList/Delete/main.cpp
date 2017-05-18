#include "header.h"

int main()
{
	SNode *head = NULL;
	addSHead(head, 3);
	addSHead(head, 4);
	addSHead(head, 5);
	printSNode(head);
	delAll(head);

	return 0;
}
