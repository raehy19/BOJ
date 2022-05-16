#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i * i < nb + 1)
	{
		if (nb % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int main()
{
	int	n, temp, count;

	count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp);
		if (ft_is_prime(temp))
			++count;
	}
	printf("%d", count);
	return (0);
}