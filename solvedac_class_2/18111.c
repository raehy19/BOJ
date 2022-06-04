#include <stdio.h>
#include <stdlib.h>

int	ft_compare(const void *a, const void *b)
{
	if (*((int *)a) < *((int *)b))
		return (1);
	else if (*((int *)a) > *((int *)b))
		return (-1);
	else
		return (0);
}

int main()
{
	int	n, m, b, min_height, max_height, temp_b, min_time, result_height;
	int *map;
	int	*time_by_height;

	scanf("%d %d %d", &n, &m, &b);
	map = (int *) malloc(sizeof(int) * (n * m));
	min_height = 256;
	max_height = 0;
	for (int i = 0; i < (n * m); ++i)
	{
		scanf("%d", (map + i));
		if (*(map + i) > max_height)
			max_height = *(map + i);
		if (*(map + i) < min_height)
			min_height = *(map + i);
	}
	qsort(map, n * m, sizeof(int), ft_compare);
	if (min_height > 0)
		--min_height;
	if (max_height < 256)
		++max_height;
	time_by_height = (int *) malloc(sizeof(int) * (max_height - min_height + 1));
	for (int i = 0; i < max_height - min_height + 1; ++i)
	{
		temp_b = b;
		*(time_by_height + i) = 0;
		for (int j = 0; j < (n * m); ++j)
		{
			if (*(map + j) > (min_height + i))
			{
				*(time_by_height + i) += (*(map + j) - (min_height + i)) * 2;
				temp_b += (*(map + j) - i);
			}
			else if (*(map + j) < (min_height + i))
			{
				if (((min_height + i) - *(map + j)) <= temp_b)
				{
					*(time_by_height + i) += ((min_height + i) - *(map + j));
					temp_b -= ((min_height + i) - *(map + j));
				}
				else
				{
					*(time_by_height + i) = -1;
					break ;
				}
			}
		}
	}
	min_time = 2147483647;
	for (int i = 0; i < max_height - min_height + 1; ++i)
	{
		if (*(time_by_height + i) > -1 && *(time_by_height + i) <= min_time)
		{
			min_time = *(time_by_height + i);
			result_height = i + min_height;
		}
	}
	printf("%d %d", min_time, result_height);
	free(map);
	free(time_by_height);
	return (0);
}