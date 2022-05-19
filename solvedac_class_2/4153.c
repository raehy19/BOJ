#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int	a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	while (a != 0 || b != 0 || c != 0)
	{
		if (a > b)
			ft_swap(&a, &b);
		if (b > c)
			ft_swap(&b, &c);
		if (a * a + b * b == c * c)
			printf("right\n");
		else
			printf("wrong\n");
		scanf("%d %d %d", &a, &b, &c);
	}
	return (0);
}