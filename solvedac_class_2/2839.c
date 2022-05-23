#include <stdio.h>

int main()
{
	int	n, cnt_5;

	scanf("%d", &n);
	cnt_5 = n / 5;
	while (cnt_5 > -1)
	{
		if ((n - (cnt_5 * 5)) % 3 == 0)
		{
			printf("%d",(cnt_5 + (n - (cnt_5 * 5)) / 3));
			break ;
		}
		else
			--cnt_5;
	}
	if (cnt_5 == -1)
		printf("-1");
	return (0);
}