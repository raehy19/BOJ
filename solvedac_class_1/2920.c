#include <stdio.h>

int main()
{
	int	n[8];
	int	ascending = 0;
	int	descending = 0;

	for (int i = 0; i < 8; i++)
	{
		scanf("%d", n + i);
		if (i > 0)
		{
			if (*(n + i - 1) < *(n + i))
				ascending++;
			else if (*(n + i - 1) > *(n + i))
				descending++;
			else
			{
				ascending++;
				descending++;
			}
		}
	}
	if (ascending == 7)
		printf("ascending");
	else if (descending == 7)
		printf("descending");
	else
		printf("mixed");
	return 0;
}