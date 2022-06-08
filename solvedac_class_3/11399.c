#include <stdio.h>
#include <stdlib.h>

int	ft_compare(const void *a, const void *b)
{
	if (*((int *)a) > *((int *)b))
		return (1);
	else if (*((int *)a) < *((int *)b))
		return (-1);
	else
		return (0);
}

int main(void)
{
	int	n, total_time;
	int	*each_time;

	scanf("%d", &n);
	each_time = (int *) malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", each_time + i);
	qsort(each_time, n, sizeof(int), ft_compare);
	total_time = 0;
	for (int i = 0; i < n; ++i)
		total_time += (n - i) * (*(each_time + i));
	printf("%d", total_time);
	return (0);
}