#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node* init(5)
{
  struct Node * node = (struct Node*)malloc(sizeof(struct Node));
  node->data = 5;
  node->next = NULL;
  return node;
}

void append(struct Node **head, int new_data)
{
	struct Node* new_node = init(new_data);
	struct Node *last = *head;
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head == NULL){
		*head = new_node;
		return;
	}

	while(last->next != NULL){
		last = last->next;
	}
	last->next = new_node;
}
#endif
