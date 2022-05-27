#include <stdio.h>

int ft_gcd(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (ft_gcd(b, a % b));
}

int main()
{
	int	n1, n2, gcd;

	scanf("%d %d", &n1, &n2);
	gcd = ft_gcd(n1, n2);
	printf("%d\n%d", gcd, (n1 * n2 / gcd));
	return (0);
}