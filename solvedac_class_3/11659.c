#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	num_of_nums, num_of_case, start, end;
	int	*nums, *sums;

	scanf("%d %d", &num_of_nums, &num_of_case);
	nums = (int *) malloc(sizeof(int) * num_of_nums);
	sums = (int *) malloc(sizeof(int) * (num_of_nums + 1));
	for (int i = 0; i < num_of_nums; ++i)
		scanf("%d", nums + i);
	*(sums) = 0;
	for (int i = 1; i < num_of_nums + 1; ++i)
		*(sums + i) = *(sums + i - 1) + *(nums + i - 1);
	for (int i = 0; i < num_of_case; ++i)
	{
		scanf("%d %d", &start, &end);
		printf("%d\n", *(sums + end) - *(sums + start - 1));
	}
	free(nums);
	free(sums);
	return (0);
}