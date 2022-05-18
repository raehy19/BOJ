#include <stdio.h>

int main()
{
	int	n, i;

	scanf("%d", &n);
	i = 1;
	--n;
	while (n > 0)
	{
		n -= (i * 6);
		++i;
	}
	printf("%d", i);
	return (0);
}