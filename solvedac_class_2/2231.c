#include <stdio.h>

int ft_cal_start_num(int num)
{
	int digit;
	int temp;

	digit = 1;
	temp = num;
	while (temp / 10 > 0)
	{
		++digit;
		temp /= 10;
	}
	temp = num - (digit * 9 - 1);
	if (temp < 1)
		return (1);
	else
		return (temp);
}

int ft_cal_decompose(int num)
{
	int	temp;

	temp = num;
	while (num / 10 > 0)
	{
		temp += num % 10;
		num /= 10;
	}
	temp += num;
	return (temp);
}

int main()
{
	int	n, gen;

	scanf("%d", &n);
	gen = 0;
	for (int i = ft_cal_start_num(n); i < n; ++i)
	{
		if (ft_cal_decompose(i) == n)
		{
			gen = i;
			break ;
		}
	}
	printf("%d", gen);
	return (0);
}