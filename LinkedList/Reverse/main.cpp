#include "LinkedList.h"

int main()
{
	DNode *head = NULL;
	addDHead(head, 3);
	addDHead(head, 4);
	addDHead(head, 5);
	addDHead(head, 7);
	reverseDNode(head);
	printDNode(head);
	delDAll(head);

	return 0;
}
