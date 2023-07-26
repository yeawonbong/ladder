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

char	**getResult(char **ladder, int start)
{
	int j = start - 1;

	for (int i=0; i < 12; i++)
	{
		ladder[i][j] += 4;
		if (ladder[i][j] == '0' || ladder[i][j] == '4')
		{
			ladder[i][j] += 4;
			j++;
			ladder[i][j] += 8;
		}
		else if (ladder[i][j] == '2' || ladder[i][j] == '6')
		{
			ladder[i][j] += 8;
			j--;
			ladder[i][j] += 12;
		}
	}
	return ladder;
}

void	printLadder(char **ladder, int col)
{
	char* bars[16] = {"├", "│", "┤", "──────────", "┣", "┃", "┫", "━━━━━━━━━━", "┡", "┃", "┪", "          ", "┢", "┃", "┩"};

	for (int i=0; ladder[i]; i++)
	{
		for (int j=0; j < col; j++)
		{
			printf("%s", bars[ladder[i][j] - '0']);
			switch (ladder[i][j])
			{
				case '0' : printf("%s", bars[3]); break;
				case '4' : printf("%s", bars[7]); break;
				case '8' : printf("%s", bars[7]); break;
				case '<' : printf("%s", bars[7]); break;
				default  : printf("          ");
			}
		}
		printf("%s", "\n");
	}	
}

int 	main(int argc, char **argv)
{
	int		col;
	int		lv;
	int		start;
	char	**ladder;

	// 인자 입력 안할 경우 초기값
	col = 1 < argc ? atoi(argv[1]) : 10;
	lv = 2 < argc ? atoi(argv[2]) : 3;
	start = 3 < argc ? atoi(argv[3]) : 1;
	switch (lv)
	{
		case 1 : lv = 10; break;
		case 2 : lv = 5; break;
		default : lv = 3;
	}
	// 에러상황 처리
	if (col < 2)
	{
		printf("첫번째 인자를 2 이상으로 넣어주새요.\n");
		return(0);
	}
	if (start < 1 || col < start)
	{
		printf("세번째 인자를 1 ~ %d 사이의 값으로 넣어주새요.\n", col);
		return(0);
	}

	ladder = genLadder(col, lv);
	if (3 < argc)
		ladder = getResult(ladder, start);
	printLadder(ladder, col);
	freeAll(ladder);
	return 0;
}