#include <stdio.h>

int ft_cal(int k, int n)
{
	if (n == 1)
		return (1);
	else if (k == 0)
		return (n);
	else
		return (ft_cal(k - 1, n) + ft_cal(k, n - 1));
}

int main()
{
	int	num_of_case, k, n;

	scanf("%d", &num_of_case);
	for (int i = 0; i < num_of_case; ++i)
	{
		scanf("%d\n%d", &k, &n);
		printf("%d\n", ft_cal(k, n));
	}
	return (0);
}