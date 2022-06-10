#include <stdio.h>

int	ft_fibonacci(int n)
{
	if (n < 2)
		return (n);
	else
		return (ft_fibonacci(n - 1) + ft_fibonacci(n - 2));
}

int main()
{
	int		num_of_case, input_num;

	scanf("%d", &num_of_case);
	for (int i = 0; i < num_of_case; ++i)
	{
		scanf("%d", &input_num);
		if (input_num == 0)
			printf("1 0\n");
		else
			printf("%d %d\n", ft_fibonacci(input_num - 1), ft_fibonacci(input_num));
	}
	return (0);
}