#include <stdio.h>

int main()
{
	int	n;

	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++)
	{
		if (i != 1)
			printf("\n");
		printf("%d", i);
	}
	return 0;
}