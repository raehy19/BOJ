#include <stdio.h>

int main()
{
	int	n, x;
	int	num;
	int	flag = 0;

	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (num < x)
		{
			if (flag == 1)
				printf(" ");
			printf("%d", num);
			flag = 1;
		}
	}
	return 0;
}