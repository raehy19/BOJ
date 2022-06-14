#include <stdio.h>
#include <stdlib.h>

int main()
{
	int			n;
	int			*dp;
	const int	mod = 10007;

	scanf("%d", &n);
	dp = (int *) malloc(sizeof(int) * n);
	*(dp + 0) = 1;
	if (n > 1)
	{
		*(dp + 1) = 2;
		for (int i = 2; i < n; ++i)
			*(dp + i) = (*(dp + i - 1) + *(dp + i - 2)) % mod;
	}
	printf("%d", *(dp + n - 1));
	free(dp);
	return (0);
}