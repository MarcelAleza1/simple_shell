#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stype.h>
#include "shell.h"

static char **history
static int len_history
static char *input;

static struct cmd *previous_command;
static struct cmds *prvious_commands;
static char *temp;


/*
 * take_input - function that accpet input
 * Return: void
 */
char *take_input(void)
{
	int buffer = 2048;
	char input = malloc(buffer * sizeof(char));
	int num = 0;
	char c;

	if (input == NULL)
	{
		fprintf(stderr, "Error: can not allocate space in memory\n");

	}
	while (( c = getchar()) != '\n') {
		if (c == EOF) {
			free(input);
			return NULL;
		}

		if ( num >= buffer) {
			buffer = 2 * buffer;
			input = realloc(input, buffer);
		}
		input[num++] = c;
	}

	input[num] = '\0';
	return input;
}
