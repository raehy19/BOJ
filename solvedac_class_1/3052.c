#include <stdio.h>

int main()
{
	int	nums[10];
	int	mods[10];
	int count = 1;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", nums + i);
		*(mods + i) = *(nums + i) % 42;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (*(mods + i) == *(mods + j))
				break ;
			if (j + 1 == i)
				count++;
		}
	}
	printf("%d", count);
	return 0;
}