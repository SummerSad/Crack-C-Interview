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
            //set NULL after delete
            temp = NULL;
        }
    }
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

void removeList(Node *&head)
{
    while(head != NULL)
        removeHead(head);
}

Node *middleList(Node *head)
{
    int temp = 0;
    Node *p = head;
    while(p != NULL)
    {
        p = p->next;
        temp++;
    }
    int middle = temp / 2;
    p = head;
    for(int i = 0; i < middle; i++)
    {
        p = p->next;
    }
    return p;
}

//Su dung 2 Node
//Node 1 next 1, Node 2 next 2
//Node 2 end la Node 1 middle
Node *middleList2(Node *head)
{
    if(head == NULL)
        return NULL;
    Node *p_1 = head;
    Node *p_2 = head->next;
    while(p_2 != NULL && p_2->next != NULL)
    {
        p_1 = p_1->next;
        p_2 = p_2->next->next;
    }
    return p_1;
}

bool compareList(Node *head_1, Node *head_2)
{
    Node *p, *q;
    p = head_1;
    q = head_2;
    while(p != NULL && q != NULL)
    {
        if(p->key != q->key)
            return false;
        p = p->next;
        q = q->next;
    }
    if(p != q) //=NULL
        return false;
    return true;
}

//Su dung de quy
bool compareList2(Node *head_1, Node *head_2)
{
    if(head_1 == NULL && head_2 == NULL)
        return true;
    if(head_1 == NULL && head_2 != NULL)
        return false;
    if(head_1 != NULL && head_2 == NULL)
        return false;
    return compareList2(head_1->next, head_2->next);
}

Node *copyList(Node *head)
{
    if(head == NULL)
        return NULL;
    Node *newList = getNode(head->key);
    Node *p = newList;
    head = head->next;
    while(head != NULL)
    {
        Node *temp = getNode(head->key);
        p->next = temp;
        p = p->next;
        head = head->next;
    }
    return newList;

}

void copyList2(Node *src, Node *&des)
{
    if(src == NULL)
        des = NULL;
    else
    {
        des = getNode(src->key);
        copyList2(src->next, des->next);
    }
}

void removeDup(Node *&head)
{
    Node *p1 = head;
    while(p1 != NULL && p1->next != NULL)
    {
        // Lay p1 lam goc, chay p2 den khi = p1 thi xoa
        Node *p2 = p1;
        while(p2->next != NULL)
        {
            if(p2->next->key == p1->key)
            {
                Node *temp = p2->next;
                p2->next = temp->next;
                delete temp;
                temp = NULL;
            }
            else
                p2 = p2->next;
        }
        p1 = p1->next;
    }
}

int main()
{
    Node *head = NULL;
    addHead(head, 1);
    addHead(head, 2);
    addHead(head, 1);
    addHead(head, 2);
    addHead(head, 1);
    addHead(head, 2);
    removeDup(head);
    printList(head);
    removeList(head);
    return 0;
}
