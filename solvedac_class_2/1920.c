#include <stdio.h>
#include <stdlib.h>

int	ft_compare(const void *a, const void *b)
{
	if (*((int *)a) > *((int *)b))
		return 1;
	else if (*((int *)a) < *((int *)b))
		return -1;
	else
		return 0;
}

int main()
{
	int	n, m, temp, min, max, median;
	int	*nums;
	int *result;

	scanf("%d", &n);
	nums = (int *) malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", nums + i);
	qsort(nums, n, sizeof(int), ft_compare);
	scanf("%d", &m);
	result = (int *) malloc(sizeof(int) * m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &temp);
		min = 0;
		max = n -1;
		while (min <= max)
		{
			median =((max + min) / 2);
			if (*(nums + median) > temp)
				max = median - 1;
			else if (*(nums + median) < temp)
				min = median + 1;
			else
				break;
		}
		if (temp == *(nums + median))
			*(result + i) = 1;
		else
			*(result + i) = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		if (i != 0)
			printf("\n");
		printf("%d",*(result + i));
	}
	free(nums);
	free(result);
	return 0;
}