#include "./ladder.h"

void	freeAll(char **arr)
{
	for (int i=0; i < 12; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

long	getTimeMs(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return(time.tv_usec);
}

int 	initVars(int argc, char **argv, int *col, int *lv, int *start)
{
	for (int i=1; argv[i]; i++)
	{
		for (int j=0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("자연수만 입력해주세요.\n");
				return(0);
			}
		}
	}
	*col = 1 < argc ? atoi(argv[1]) : 10;
	*lv = 2 < argc ? atoi(argv[2]) : 3;
	*start = 3 < argc ? atoi(argv[3]) : 1;
	if (*col < 2 || 100 < *col)
	{
		printf("첫번째 인자를 [2 ~ 100] 사이의 값으로 입력해주세요.\n");
		return(0);
	}
	switch (*lv)
	{
		case 1 : *lv = 50; break;
		case 2 : *lv = 10; break;
		case 3 : *lv = 2;	break;
		default : 
			printf("두번째 인자를 [1, 2, 3] 중 선택하여 입력해주세요.\n");
			return(0);
	}
	if (*start < 1 || *col < *start)
	{
		printf("세번째 인자를 [1 ~ 막대의 갯수] 사이의 값으로 입력해주세요.\n");
		return(0);
	}
	return(1);
}

char	**genLadder(int col, int lv)
{
	char	**ladder;
	int		isValid;

	ladder = malloc(sizeof(char**) * 13);
	ladder[12] = NULL;
	for (int i=0; i < 12; i++)
	{
		ladder[i] = malloc(sizeof(char*) * (col + 1));
		memset(ladder[i], '1', sizeof(char) * (col));
		ladder[i][col] = '\0';
	}
	srand(getTimeMs());
	for (int j=0; j < col - 1; j++)
	{
		isValid = -1;
		for (int i=1; i < 11; i++)
		{
			if (rand() % lv == 0 && ladder[i][j] != '2')
			{
				ladder[i][j] = '0';
				ladder[i][j+1] = '2';
				isValid = 0;
			}
		}
		j += isValid;
	}
	return(ladder);
}

char	**getResult(char **ladder, int start)
{
	int j = start - 1;

	for (int i=0; i < 12; i++)
	{
		ladder[i][j] += 4;
		if (ladder[i][j] == '0' || ladder[i][j] == '4') // 왼쪽으로 꺾어질 때
		{
			ladder[i][j] += 4;
			j++;
			ladder[i][j] += 8;
		}
		else if (ladder[i][j] == '2' || ladder[i][j] == '6') // 오른쪽으로 꺾어질 때
		{
			ladder[i][j] += 8;
			j--;
			ladder[i][j] += 12;
		}
	}
	return(ladder);
}

void	printLadder(char **ladder)
{
	char* bars[16] = {"├", "│", "┤", "──────────", "┣", "┃", "┫", "━━━━━━━━━━", "┡", "┃", "┪", "          ", "┢", "┃", "┩"};

	for (int i=0; ladder[i]; i++)
	{
		for (int j=0; ladder[i][j]; j++)
		{
			printf("%s", bars[ladder[i][j] - '0']);
			switch (ladder[i][j] - '0')
			{
				case 0 	: printf("%s", bars[3]); break;
				case 4 	: printf("%s", bars[7]); break;
				case 8 	: printf("%s", bars[7]); break;
				case 12 : printf("%s", bars[7]); break;
				default : printf("%s", bars[11]);
			}
		}
		printf("%s", "\n");
	}	
}

int 	main(int argc, char **argv)
{
	int		col = 0;
	int		lv = 0;
	int		start = 0;
	char	**ladder = 0;

	if (!initVars(argc, argv, &col, &lv, &start))
		return(0);
	ladder = genLadder(col, lv);
	if (3 < argc)
		ladder = getResult(ladder, start);
	printLadder(ladder);
	freeAll(ladder);
	return(0);
}
