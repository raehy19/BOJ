#include <stdio.h>
#include <stdlib.h>

int	ft_power(int nb, int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

int main()
{
	int			l;
	long long	hash;
	char		*str;

	scanf("%d", &l);
	str = (char *) malloc (sizeof(char) * (l + 1));
	scanf("%s", str);
	hash = 0;
	for (int i = 0; *(str + i) != '\0'; ++i)
		hash += ((int) (*(str + i) - 'a' + 1)) * ft_power(31, i);
	hash %= 1234567891;
	printf("%lld", hash);
	free(str);
	return (0);
}