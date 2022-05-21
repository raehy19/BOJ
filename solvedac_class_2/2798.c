#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	n, m, temp, max;
	int *cards;

	scanf("%d %d", &n, &m);
	cards = (int *) malloc (sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", cards + i);
	max = 0;
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				temp = *(cards + i) + *(cards + j) + *(cards + k);
				if (temp <= m && temp > max)
					max = temp;
			}
		}
	}
	printf("%d", max);
	free(cards);
	return (0);
}