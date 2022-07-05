#include <stdio.h>
#include <stdlib.h>

typedef struct s_count
{
	int	minus;
	int	zero;
	int plus;
} t_count;

void	ft_plus_sum(t_count *a, t_count b)
{
	a->minus += b.minus;
	a->zero += b.zero;
	a->plus += b.plus;
}

t_count	ft_solve(int **map, int x, int y, int size)
{
	int		temp_value;
	t_count	temp_count;

	temp_count.minus = 0;
	temp_count.zero = 0;
	temp_count.plus = 0;
	temp_value = *(*(map + x) + y);
	for (int i = x; i < x + size; ++i)
	{
		for (int j = y; j < y + size; ++j)
		{
			if (*(*(map + i) + j) != temp_value)
			{
				ft_plus_sum(&temp_count, (ft_solve(map, x, y, size/3)));
				ft_plus_sum(&temp_count, (ft_solve(map, x, y + (size / 3), size/3)));
				ft_plus_sum(&temp_count, (ft_solve(map, x, y + 2 * (size / 3), size/3)));
				ft_plus_sum(&temp_count, (ft_solve(map, x + (size / 3), y, size/3)));
				ft_plus_sum(&temp_count, (ft_solve(map, x + (size / 3), y + (size / 3), size/3)));
				ft_plus_sum(&temp_count, (ft_solve(map, x + (size / 3),  y + 2 * (size / 3), size/3)));
				ft_plus_sum(&temp_count, (ft_solve(map, x + 2 * (size / 3), y, size/3)));
				ft_plus_sum(&temp_count, (ft_solve(map, x + 2 * (size / 3), y + (size / 3), size/3)));
				ft_plus_sum(&temp_count, (ft_solve(map, x + 2 * (size / 3), y + 2 * (size / 3), size/3)));
				return (temp_count);
			}
		}
	}
	if (temp_value == -1)
		temp_count.minus = 1;
	else if (temp_value == 1)
		temp_count.plus = 1;
	else
		temp_count.zero = 1;
	return (temp_count);
}

int main()
{
	int		n;
	int		**map;
	t_count	temp_count;

	scanf("%d", &n);
	map = (int **) malloc(sizeof(int *) * (n));
	for (int i = 0; i < n + 1; ++i)
		*(map + i) = (int *) malloc(sizeof(int) * (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", (*(map + i) + j));
	temp_count = ft_solve(map, 0, 0, n);
	printf("%d\n%d\n%d", temp_count.minus, temp_count.zero, temp_count.plus);
	for (int i = 0; i < n + 1; ++i)
		free(*(map + i));
	free(map);
	return (0);
}