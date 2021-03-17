#include <iostream>
#include "linkedlist.h"

Node* removeNthFromEnd(Node* head, int n) 
{
    Node* node = init(0);
    node->next = head;
    int length = 0;
    Node* first = node;

    while (first != NULL)
    {
        length++;
        first = first->next;
    }

    length -= n;
    first = node;

    while (length > 0)
    {
        length--;
        first = first->next;
    }
    
    first->next = first->next->next;
    return node->next;
};

int main()
{   
    //TODO
    //make a node to test with

    removeNthFromEnd(head, 2);
    return 0;
}