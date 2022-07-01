#include <stdio.h>
#include <stdlib.h>

int main()
{
	int					num_of_nums, num_of_case, start, end;
	unsigned long long	sum;
	int					*nums;

	scanf("%d %d", &num_of_nums, &num_of_case);
	nums = (int *) malloc(sizeof(int) * num_of_nums);
	for (int i = 0; i < num_of_nums; ++i)
		scanf("%d", nums + i);
	for (int i = 0; i < num_of_nums; ++i)
	{
		sum = 0;
		scanf("%d %d", &start, &end);
		for (int j = start - 1; j < end; ++j)
			sum	+= *(nums + j);
		printf("%lld\n",sum);
	}
	free(nums);
	return (0);
}