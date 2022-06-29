#include <stdio.h>
#include <stdlib.h>

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int main()
{
	int	n;
	int *map;
	int *result;

	scanf("%d", &n);
	map = (int *) malloc(sizeof(int) * n);
	result = (int *) malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", map + i);
	*(result + 0) = *(map + 0);
	if (n > 1)
		*(result + 1) = *(map + 0) + *(map + 1);
	if (n > 2)
		*(result + 2) = *(map + 2) + ft_max(*(map + 0), *(map + 1));
	for (int i = 3; i < n; ++i)
		*(result + i) = ft_max(*(result + i - 2), (*(result + i - 3) + *(map + i - 1))) + (*(map + i));
	printf("%d", *(result + n - 1));
	free(map);
	free(result);
	return (0);
}