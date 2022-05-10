#include <stdio.h>
#include <stdlib.h>

int main()
{
	int		a, b, c, result;
	char	*str;
	char	nums[] = "0123456789";
	int		counts[10];

	str = (char *) malloc(sizeof(char) * 10);
	for (int i = 0; i < 10; i++)
		counts[i] = 0;
	scanf("%d\n%d\n%d", &a, &b, &c);
	result = a * b * c;
	itoa(result,str,10);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (*(nums + j) == *(str + i))
			{
				counts[j]++;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++)
		printf("%d\n",counts[i]);
	printf("%d",counts[9]);
	free(str);
	return 0;
}