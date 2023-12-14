#include "monty.h"

void pall()
{
	Node* current = stack;

	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
