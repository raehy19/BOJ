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

int main()
{
	int	n;
	int *nums;

	scanf("%d", &n);
	nums = (int *) malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", nums + i);
	qsort(nums, n, sizeof(int), ft_compare);
	for (int i = 0; i < n; ++i)
		printf("%d\n", *(nums + i));
	free(nums);
	return (0);
}