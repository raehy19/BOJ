#include <stdio.h>
#include <stdlib.h>

int main()
{
	int		m, n;
	char	**board;
	int 	to_change;
	int		min_change = 32;

	scanf("%d %d", &m, &n);
	board = (char **) malloc(sizeof (char *) * m);
	for (int i = 0; i < m; i++)
	{
		*(board + i) = (char *) malloc(sizeof(char) * n);
		scanf("%s", *(board + i));
	}
	for (int i = 0; i < m - 7; i++)
	{
		for (int j = 0; j < n - 7; j++)
		{
			to_change = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if ((k % 2 == 1 && l % 2 == 1)
						|| (k % 2 == 0 && l % 2 == 0))
					{
						if (*(*(board + i + k) + j + l) == 'W')
							to_change++;
					}
					else
					{
						if (*(*(board + i + k) + j + l) == 'B')
							to_change++;
					}
				}
			}
			if (to_change > 32)
				to_change = 64 - to_change;
			if (to_change < min_change)
				min_change = to_change;
		}
	}
	for (int i = 0; i < m; i++)
		free(*(board + i));
	free(board);
	printf("%d", min_change);
	return 0;
}