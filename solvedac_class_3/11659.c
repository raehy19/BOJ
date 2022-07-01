#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	num_of_nums, num_of_case, input_num, start, end;
	int	*sums;

	scanf("%d %d", &num_of_nums, &num_of_case);
	sums = (int *) malloc(sizeof(int) * (num_of_nums + 1));
	*(sums) = 0;
	for (int i = 1; i < num_of_nums + 1; ++i)
	{
		scanf("%d", &input_num);
		*(sums + i) = *(sums + i - 1) + input_num;
	}
	for (int i = 0; i < num_of_case; ++i)
	{
		scanf("%d %d", &start, &end);
		printf("%d\n", *(sums + end) - *(sums + start - 1));
	}
	free(sums);
	return (0);
}