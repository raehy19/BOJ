#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long	k, n, can_make;
	long long	*cables;

	scanf(("%lld %lld"), &k, &n);
	cables = (long long *) malloc(sizeof(long long) * k);
	for (int i = 0; i < k; i++)
		scanf("%lld", cables + i);
	for (int cable_len = 1; 1; cable_len++)
	{
		can_make = 0;
		for (int i = 0; i < k; i++)
			can_make += (*(cables + i) / cable_len);
		if (can_make < n)
		{
			printf("%d", cable_len - 1);
			free(cables);
			return 0;
		}
	}
}