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
		i++;
	}
	return (1);
}

int main()
{
	int	m, n;

	scanf("%d %d", &m, &n);
	for (int i = m; i < n + 1; ++i)
		if (ft_is_prime(i))
			printf("%d\n", i);
	return 0;
}