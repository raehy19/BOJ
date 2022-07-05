#include <stdio.h>
#include <stdlib.h>

typedef struct s_count
{
	int blue;
	int white;
} t_count;

t_count	ft_solve(int **map, int x, int y, int size)
{
	int		temp_value;
	t_count	temp_count;

	temp_value = *(*(map + x) + y);
	for (int i = x; i < x + size; ++i)
	{
		for (int j = y; j < y + size; ++j)
		{
			if (*(*(map + i) + j) != temp_value)
			{
				temp_count.blue = ft_solve(map, x, y, size / 2).blue
								  + ft_solve(map, x + (size / 2), y,
											 size / 2).blue
								  + ft_solve(map, x, y + (size / 2),
											 size / 2).blue
								  +
								  ft_solve(map, x + (size / 2), y + (size / 2),
										   size / 2).blue;
				temp_count.white = ft_solve(map, x, y, size / 2).white
								   + ft_solve(map, x + (size / 2), y,
											  size / 2).white
								   + ft_solve(map, x, y + (size / 2),
											  size / 2).white
								   +
								   ft_solve(map, x + (size / 2), y + (size / 2),
											size / 2).white;
				return (temp_count);
			}
		}
	}
	if (temp_value == 1)
	{
		temp_count.blue = 1;
		temp_count.white = 0;
	}
	else
	{
		temp_count.blue = 0;
		temp_count.white = 1;
	}
	return (temp_count);
}

int main()
{
	int		n;
	int		**map;
	t_count	temp_count;

	scanf("%d", &n);
	map = (int **) malloc(sizeof(int *) * (n));
	for (int i = 0; i < n; ++i)
		*(map + i) = (int *) malloc(sizeof(int) * (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", (*(map + i) + j));
	temp_count = ft_solve(map, 0, 0, n);
	printf("%d\n%d", temp_count.white, temp_count.blue);
	for (int i = 0; i < n; ++i)
		free(*(map + i));
	free(map);
	return (0);
}