#ifndef SHELL_H
#define SHELL_H

#define MAX_ARG 1024
/* Maximun number of lelemnts in history */
#define MAX_HISORY 100

/**
 * struct cmd - structure that stores parsed command
 * @argc: integer, number of argument in the command
 * @name: command name
 * @argv: arguments
 * @fd: integer to describe a file
 */
struct cmd
{
	int argc;
	char *name;
	char *argv[MAX_ARG];
	int fd;
};
/**
 * struct cmds - struct to store command
 * @cmd_num: count commands
 * @commands: commands
 */

struct cmds
{
	int cmd_num;
	struct cmd *commands[];
};

