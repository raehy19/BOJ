#include <stdio.h>

int main()
{
	int	n, k, binomial_coefficient;

	scanf("%d %d", &n, &k);
	if (k > (n / 2))
		k = n - k;
	binomial_coefficient = 1;
	for (int i = k; i > 0; --i)
	{
		binomial_coefficient *= n;
		--n;
	}
	for (int i = k; i > 0; --i)
		binomial_coefficient /= i;
	printf("%d", binomial_coefficient);
	return (0);
}