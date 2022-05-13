#include <stdio.h>
#include <stdlib.h>

int main()
{
	int 		k, n;
	long long	max = 0;
	long long	min = 1;
	int 		*cables;

	scanf(("%d %d"), &k, &n);
	cables = (int *) malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", cables + i);
		if (*(cables + i) > max)
			max = (long long) *(cables + i);
	}
	while (min <= max)
	{
		long long	can_make = 0;
		long long	median;

		median = (max + min) / 2;
		for (int i = 0; i < k; i++)
			can_make += (*(cables + i) / median);
		if (can_make < n)
			max = median - 1;
		else
			min = median + 1;
	}
	printf("%lld", max);
}