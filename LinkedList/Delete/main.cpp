#include "header.h"

int main()
{
	SNode *head = NULL;

	addSHead(head, 2);
	addSHead(head, 3);
	addSHead(head, 4);
	delSNode(head, head->next);
	printSNode(head);
	return 0;
}
