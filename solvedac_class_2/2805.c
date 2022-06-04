#include <stdio.h>
#include <stdlib.h>

int main()
{
	int 		n;
	unsigned long long	m, min, max, median, temp_sum;
	unsigned long long	*trees;

	scanf(("%d %lld"), &n, &m);
	trees = (unsigned long long *) malloc(sizeof(unsigned long long) * n);
	min = 0;
	max = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", trees + i);
		if (*(trees + i) > max)
			max = *(trees + i);
	}
	while (min + 1 < max)
	{
		median = (min + max) / 2;
		temp_sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (*(trees + i) > median)
				temp_sum += *(trees + i) - median;
		}
		if (temp_sum >= m)
			min = median;
		else
			max = median;
	}
	printf("%lld", min);
	return (0);
}