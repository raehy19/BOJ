#include <stdio.h>

int main()
{
	int		a, b, c, result;
	int 	nums[10];
	int		counts[10];

	for (int i = 0; i < 10; i++)
		nums[i] = i;
	for (int i = 0; i < 10; i++)
		counts[i] = 0;
	scanf("%d\n%d\n%d", &a, &b, &c);
	result = a * b * c;
	while (result > 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (result % 10 == *(nums + i))
			{
				counts[i]++;
				break;
			}
		}
		result /= 10;
	}
	for (int i = 0; i < 9; i++)
		printf("%d\n",counts[i]);
	printf("%d",counts[9]);
	return 0;
}