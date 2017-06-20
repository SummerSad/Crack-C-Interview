#include <stdio.h>

struct Node
{
	int key;
	Node *next;
};

Node *getNode(int key)
{
	Node *p = new Node;
	p->key = key;
	p->next = NULL;
	return p;
}

void addHead(Node *&head, int key)
{
	Node *p = getNode(key);
	if(head == NULL)
	{
		head = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}

void removeHead(Node *&head)
{
	if(head != NULL)
	{
		if(head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}
}

void addTail(Node *&head, int key)
{
	if(head == NULL)
		addHead(head, key);
	else
	{
		Node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		Node *p = getNode(key);
		temp->next = p;
	}
}

void removeList(Node *&head)
{
	while(head != NULL)
		removeHead(head);
}

void printList(Node *head)
{
	if(head == NULL)
		printf("NULL\n");
	else
	{
		printf("%d-->", head->key);
		printList(head->next);
	}
}

struct Queue
{
	Node *head;
};

void initQueue(Queue &Q)
{
	Q.head = NULL;
}

bool isEmpty(Queue Q)
{
	return Q.head == NULL;
}

void enqueue(Queue &Q, int key)
{
	addTail(Q.head, key);
}

void dequeue(Queue &Q)
{
	removeHead(Q.head);
}

int firstQueue(Queue Q)
{
	return Q.head->key;
}

int main()
{
	Node *head = NULL;
	addHead(head, 2);
	addHead(head, 3);
	addTail(head, 4);
	addTail(head, 5);
	removeHead(head);
	printList(head);
	removeList(head);
	return 0;
}
