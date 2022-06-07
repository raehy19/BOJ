#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	n, k, coin_count;
	int *coins;

	scanf("%d %d", &n, &k);
	coins = (int *) malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", coins + i);
	coin_count = 0;
	for (int i = n - 1; i > -1; --i)
	{
		coin_count += k / *(coins + i);
		k %= *(coins + i);
	}
	printf("%d", coin_count);
	free(coins);
	return (0);
}