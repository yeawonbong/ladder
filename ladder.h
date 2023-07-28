#ifndef LADDER_H
# define LADDER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include <ctype.h>
# include <sys/time.h>

/* utils */
void	freeAll(char **arr);
long	getTimeMs(void);

/* ladder */
int 	initVars(int argc, char **argv, int *col, int *lv, int *start);
char	**genLadder(int col, int lv);
char	**getResult(char **ladder, int start);
void	printLadder(char **ladder);

#endif