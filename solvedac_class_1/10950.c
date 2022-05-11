#include <stdio.h>

int main()
{
	int	num_of_case;
	int	a, b;

	scanf("%d", &num_of_case);
	for (int i = 0; i < num_of_case; i++)
	{
		if (i != 0)
			printf("\n");
		scanf("%d %d", &a, &b);
		printf("%d",a + b);
	}
	return 0;
}