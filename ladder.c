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
	char	**ladder;
	int		isValid;
	long	num;
	ladder = malloc(sizeof(char**) * 13);
	ladder[12] = NULL;
	for (int i=0; i < 12; i++)
	{
		ladder[i] = malloc(sizeof(char*) * (col + 1));
		memset(ladder[i], '1', sizeof(char) * (col));
		ladder[i][col] = '\0';
	}
	srand(clock());
	for (int j=0; j < col - 1; j++)
	{
		isValid = -1;
		for (int i=1; i < 11; i++)
		{
			num = rand();
			// printf("%ld %% %d = %ld", num, lv, num % lv);
			// printf("%s", "\n");
			if (num / 2 % lv == 0 && ladder[i][j] != '2')
			{
				ladder[i][j] = '0';
				ladder[i][j+1] = '2';
				isValid = 0;
			}
		}
		j += isValid;
	}
	return ladder;
}

void	printLadder(char **ladder, int col)
{
	char* bars[4] = {"├", "│", "┤", "──────────"};
	// char* thickBars[4] = {"┣", "┃", "┫", "━━━━━━━━━━"};

	for (int i=0; ladder[i]; i++)
	{
		for (int j=0; j < col; j++)
		{
			printf("%s", bars[ladder[i][j] - '0']);
			if (ladder[i][j] == '0')
				printf("%s", bars[3]);
			else
				printf("          ");
		}
		printf("%s", "\n");
	}	
}

int 	main(int argc, char **argv)
{
	int		col;
	int		lv;
	char	**ladder;

	// 인자 입력 안할 경우 초기값
	col = 2 <= argc ? atoi(argv[1]) : 10;
	lv = 3 <= argc ? atoi(argv[2]) : 3;
	switch (lv)
	{
		case 1 : lv = 10; break;
		case 2 : lv = 5; break;
		default : lv = 3;
	}
	if (col < 2)
	{
		printf("첫번째 인자를 2 이상으로 넣어주새요.\n");
		return(0);
	}

	ladder = genLadder(col, lv);
	printLadder(ladder, col);
	for (int i=0; ladder[i]; i++)
	{
		printf("%s", ladder[i]);
		printf("%s", "\n");
	}
	freeAll(ladder);
	return 0;
}