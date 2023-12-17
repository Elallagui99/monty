#include "monty.h"

/**
*pall - show up what in files
*/

void pall(void)
{
	Node *current = stack;

	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
