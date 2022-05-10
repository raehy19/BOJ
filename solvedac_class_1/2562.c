#include <stdio.h>

int main()
{
	int	nums[9];
	int max = 0;
	int	max_idx = 0;

	for (int i = 0; i < 9; i++)
		scanf("%d", nums + i);
	for (int i = 0; i < 9; i++)
	{
		if (*(nums + i) > max)
		{
			max = *(nums + i);
			max_idx = i + 1;
		}
	}
	printf("%d\n%d", max, max_idx);
	return 0;
}