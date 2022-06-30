#include <stdio.h>
#include <stdlib.h>

int main()
{
	int					num_of_case, n;
	unsigned long long	*dp;

	scanf("%d", &num_of_case);
	for (int i = 0; i < num_of_case; ++i)
	{
		scanf("%d", &n);
		dp = (unsigned long long *) malloc(sizeof(unsigned long long ) * n);
		for (int j = 0; j < n && j < 3; ++j)
			*(dp + j) = 1;
		for (int j = 3; j < n && j < 5; ++j)
			*(dp + j) = 2;
		for (int j = 5; j < n; ++j)
			*(dp + j) = *(dp + j - 1) + *(dp + j - 5);
		printf("%lld\n", *(dp + n - 1));
		free(dp);
	}
	return (0);
}