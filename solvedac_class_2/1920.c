#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	n, m, flag;
	int	*nums;
	int *to_search;

	scanf("%d", &n);
	nums = (int *) malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", nums + i);
	scanf("%d", &m);
	to_search = (int *) malloc(sizeof(int) * m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", to_search + i);
		flag = 0;
		for (int j = 0; j < n; ++j)
		{
			if (*(nums + j) == *(to_search + i))
			{
				flag = 1;
				break ;
			}
		}
		*(to_search + i) = flag;
	}
	for (int i = 0; i < m; ++i)
	{
		if (i != 0)
			printf("\n");
		printf("%d",*(to_search + i));
	}
	return 0;
}