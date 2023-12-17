#include "monty.h"


void parse_line(const char* line)
{
	char opcode[10];
	int value;

	if (sscanf(line, "%9s %d", opcode, &value) == 2)
	{
		if (strcmp(opcode, "push") == 0)
		{
			push(value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall();
		}
		else
		{
			fprintf(stderr, "Error: Unknown opcode - %s\n", opcode);
			exit(EXIT_FAILURE);
		}
	}
	else if (sscanf(line, "%9s", opcode) == 1)
	{
		if (strcmp(opcode, "pall") == 0)
		{
			pall();
		}
		else
		{
			fprintf(stderr, "Error: Invalid instruction - %s\n", line);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
			fprintf(stderr, "Error: Invalid instruction - %s\n", line);
			exit(EXIT_FAILURE);
	}
}

void interpret(const char* filename)
{
	FILE* file = fopen(filename, "r");
	char line[256];

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		parse_line(line);
	}

	fclose(file);
}

Node* stack = NULL;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	interpret(argv[1]);

	return 0;
}

