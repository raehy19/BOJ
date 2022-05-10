#include <stdio.h>

int main()
{
	int	h, m;

	scanf("%d %d", &h, &m);
	if (m < 45)
	{
		if (h == 0)
			printf("%d %d", 23, m + 60 - 45);
		else
			printf("%d %d", h - 1, m + 60 - 45);
	}
	else
		printf("%d %d", h, m -45);
	return 0;
}