#include "monty.h"

/**
*push - enter values to file
*@value: the vaule
*/

void push(int value)
{
	Node *new_node = (Node *)malloc(sizeof(Node));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->data = value;
	new_node->next = stack;
	stack = new_node;
}
