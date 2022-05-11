#include <stdio.h>

int main()
{
	int	a, b;
	int	temp_a, temp_b;

	scanf("%d %d", &a, &b);
	temp_a = a;
	temp_b = b;
	for (int i = 0; i < 3; i++)
	{
		if (temp_a % 10 > temp_b % 10)
		{
			printf("%d%d%d",a % 10, a / 10 % 10, a / 100);
			break ;
		}
		else if (temp_a % 10 < temp_b % 10)
		{
			printf("%d%d%d",b % 10, b / 10 % 10, b  / 100);
			break ;
		}
		temp_a /= 10;
		temp_b /= 10;
	}
	return 0;
}