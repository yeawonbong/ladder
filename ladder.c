#include "./ladder.h"

void	freeAll(char **ladder)
{
	for (int i=0; i < 12; i++)
	{
		free(ladder[i]);
	}
	free(ladder);
}

char	**genLadder(int col, int lv)
{
	char **ladder;

	ladder = malloc(sizeof(char**) * 13);
	ladder[12] = NULL;
	for (int i=0; i < 12; i++)
	{
		ladder[i] = malloc(sizeof(char*) * (col + 1));
		memset(ladder[i], '1', sizeof(char) * (col));
		ladder[i][col] = '\0';
	}
	srand(time(NULL));
	for (int j=0; j < col - 1; j++)
	{
		for (int i=1; i < 11; i++)
		{
			usleep(300);
			if (rand() * 10 % lv == 0 && ladder[i][j] != '2')
			{
				ladder[i][j] = '0';
				ladder[i][j+1] = '2';
			}
		}
	}
	return ladder;
}

void	printLadder(char **ladder, int col)
{
	char* bars[4] = {"┣", "┃", "┫", "━"};
	for (int i=0; ladder[i]; i++)
	{
		for (int j=0; j < col; j++)
		{
			printf("%s", bars[ladder[i][j] - '0']);
			if (ladder[i][j] == '0')
				printf("━━━━━━━━━━");
			else
				printf("          ");
		}
		printf("%s", "\n");
	}	
}

int 	main(int argc, char **argv)
{
	int		col = atoi(argv[1]);
	int		lv = atoi(argv[2]);
	char	**ladder;

	argc++;
	switch (lv)
	{
		case '1' : lv = 2; break;
		case '2' : lv = 3; break;
		default	 : lv = 4;
	}
	ladder = genLadder(col, lv);

	printLadder(ladder, col);
	// for (int i=0; ladder[i]; i++)
	// {
	// 	printf("%s", ladder[i]);
	// 	printf("%s", "\n");
	// }
	freeAll(ladder);
	return 0;
}