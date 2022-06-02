#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	n, m, temp;
	int *count;

	count = (int *) malloc(sizeof(int) * 20000001);
	for (int i = 0; i < 20000001; ++i)
		*(count + i) = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp);
		++(*(count + 10000000 + temp));
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &temp);
		printf("%d ", *(count + 10000000 + temp));
	}
	free(count);
	return (0);
}