#include <stdio.h>
#include <stdlib.h>

int ft_round(double num)
{
	if (num < 0)
		num -= 0.5;
	else
		num += 0.5;
	return ((int) num);
}

int	ft_compare(const void *a, const void *b)
{
	if (*((int *)a) > *((int *)b))
		return (1);
	else if (*((int *)a) < *((int *)b))
		return (-1);
	else
		return (0);
}

int main()
{
	int	n, temp, mode_max_count, mode_idx;
	int	*nums;
	int *nums_count;

	scanf("%d", &n);
	nums = (int *) malloc(sizeof(int) * n);
	nums_count = (int *) malloc(sizeof(int) * n);
	temp = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", nums + i);
		temp += *(nums + i);
	}
	qsort(nums, n, sizeof(int), ft_compare);
	printf("%d\n%d\n", ft_round((double) temp / (double) n), *(nums + (n / 2)));
	temp = 1;
	mode_max_count = 1;
	*(nums_count) = 1;
	for (int i = 1; i < n; ++i)
	{
		if (*(nums + i - 1) == *(nums + i))
		{
			++temp;
			*(nums_count + i) = temp;
			if (temp > mode_max_count)
				mode_max_count = temp;
		}
		else
		{
			temp = 1;
			*(nums_count + i) = temp;
		}
	}
	temp = 0;
	for (int i = 0; i < n && temp < 2; ++i)
	{
		if (*(nums_count + i) == mode_max_count)
		{
			mode_idx = i;
			++temp;
		}
	}
	printf("%d\n%d", *(nums + mode_idx), (*(nums + n - 1) - *(nums)));
	free(nums);
	free(nums_count);
	return (0);
}