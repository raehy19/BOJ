#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ft_itoa(int num, char *dest)
{
	int	temp;
	int	len = 0;

	temp = num;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	for (int i = 0; i < len; i++)
	{
		*(dest + len - 1 - i) = (num % 10) + '0';
		num /= 10;
	}
	*(dest + len) = '\0';
}

int main()
{
	int		n;
	int 	count = 0;
	char	*str;

	scanf("%d", &n);
	str = (char *) malloc(sizeof(char) * 11);
	for (int i = 666; 1; i++)
	{
		ft_itoa(i, str);
		if (strstr(str, "666") != NULL)
		{
			count++;
			if (count == n)
			{
				printf("%d", i);
				free(str);
				return 0;
			}
		}
	}
}