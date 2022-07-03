#include <stdio.h>
#include <stdlib.h>

int	ft_is_square_number(int n)
{
	for (int i = 0; i * i < n + 1; ++i)
		if (i * i == n)
			return (1);
	return (0);
}

int main()
{
	int			n, temp;
	int			*dp;

	scanf("%d", &n);
	++n;
	dp = (int *) malloc(sizeof(int) * n);
	*(dp + 0) = 0;
	for (int i = 1; i < n; ++i)
	{
		if (ft_is_square_number(i) == 1)
			*(dp + i) = 1;
		else
		{
			temp = 5;
			for (int j = 1; j * j < i; ++j)
			{
				if (*(dp + (j * j)) + *(dp + (i - (j * j))) < temp)
					temp = *(dp + (j * j)) + *(dp + (i - (j * j)));
			}
			*(dp + i) = temp;
		}
	}
	printf("%d", *(dp + n - 1));
	free(dp);
	return (0);
}