#include <stdio.h>

int main()
{
	int	size;
	int	num;
	int	max = -2147483648;
	int min = 2147483647;

	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &num);
		if (num > max)
			max = num;
		if (num < min)
			min = num;
	}
	printf("%d %d", min, max);
	return 0;
}